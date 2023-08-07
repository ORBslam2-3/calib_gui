/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/ros_qt_demo/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"class1_ros_qt_demo");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
    //chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    T_sub = n.subscribe("/vector3_T_topic", 1000, &QNode::vector3_T_callback, this);
//    quat_sub = n.subscribe("/quaternion_topic", 1000, &QNode::quat_callback, this);
    euler_sub = n.subscribe("/euler_angles", 1000, &QNode::euler_callback, this);
    log_sub = n.subscribe("/logview", 1000, &QNode::logview_callback, this);
    log_succeed_sub = n.subscribe("/log_succeed_view", 1000, &QNode::log_succeed_view_callback, this);
	start();
	return true;
}

void QNode::run() {
	ros::Rate loop_rate(1);
    //int count = 0;
	while ( ros::ok() ) {

//		std_msgs::String msg;
//		std::stringstream ss;
//		ss << "hello world " << count;
//		msg.data = ss.str();
//		chatter_publisher.publish(msg);

        if(log_succeed_view.empty()) {
            if(logview.empty()){

            }else{
            log(Info,logview);
            }
        }else{
            if(count==0){
            log(Info,log_succeed_view);
                count++;}
        }

		ros::spinOnce();
		loop_rate.sleep();
        //++count;
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

void QNode::vector3_T_callback(const geometry_msgs::Vector3 &T)
{
    x=T.x;
    y=T.y;
    z=T.z;
    // 发出信号，将平移向量数据传递给MainWindow类
    emit translationDataReceived(x, y, z);
}

//void QNode::quat_callback(const geometry_msgs::Quaternion &q)
//{
//    qx=q.x;
//    qy=q.y;
//    qz=q.z;
//    qw=q.w;
//    // 发出信号，将平移向量数据传递给MainWindow类
//    emit quatDataReceived(qw, qx, qy, qz);
//}

void QNode::euler_callback(const geometry_msgs::PoseStamped &euler)
{
    euler_x=euler.pose.orientation.x;
    euler_y=euler.pose.orientation.y;
    euler_z=euler.pose.orientation.z;
    // 发出信号，将平移向量数据传递给MainWindow类
    emit eulerDataReceived(euler_x, euler_y, euler_z);
}

void QNode::logview_callback(const std_msgs::String &s1)
{
    logview=s1.data;
    std::size_t found = logview.find("fitness_score: ");
    double fitnessScore;
    if (found != std::string::npos)
    {
                fitnessScore = std::stod(logview.substr(found + 15));

    }
    emit fitnessScoreUpdated(fitnessScore);
}

void QNode::log_succeed_view_callback(const std_msgs::String &s2)
{
    log_succeed_view=s2.data;
    if(!log_succeed_view.empty())
    {
        // 在标定完成时发送信号
        emit calibrationFinishedSignal();
    }
}


// qnode.cpp



}  // namespace class1_ros_qt_demo
