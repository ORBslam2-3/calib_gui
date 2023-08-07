/**
 * @file /include/class1_ros_qt_demo/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef class1_ros_qt_demo_QNODE_HPP_
#define class1_ros_qt_demo_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/String.h>



/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	void run();

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);
    void vector3_T_callback(const geometry_msgs::Vector3 &T);
//    void quat_callback(const geometry_msgs::Quaternion &q);
    void euler_callback(const geometry_msgs::PoseStamped &euler);
    void logview_callback(const std_msgs::String &s1);
    void log_succeed_view_callback(const std_msgs::String &s2);



Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();
    void translationDataReceived(double x, double y, double z);
//    void quatDataReceived(double w, double x, double y, double z);
    void eulerDataReceived(double eulerX, double eulerY, double eulerZ);
    void calibrationFinishedSignal();  //发射一个信号到mainwindow，使其不再订阅 G0和G6的地图
    void fitnessScoreUpdated(double fitnessScore); //发射信号

private:
    int count=0;
    float x=0.0000;
    float y=0.0000;
    float z=0.0000;
    float qw=0.0000;
    float qy=0.0000;
    float qz=0.0000;
    float qx=0.0000;
    float euler_x=0.0000;
    float euler_y=0.0000;
    float euler_z=0.0000;
    std::string logview;
    std::string log_succeed_view;
	int init_argc;
	char** init_argv;
    //ros::Publisher chatter_publisher;
    ros::Subscriber T_sub;      //声明一个话题订阅者
    ros::Subscriber quat_sub;
    ros::Subscriber euler_sub;

    ros::Subscriber log_sub;
    ros::Subscriber log_succeed_sub;

    QStringListModel logging_model;

    QVector<double> timeData; // 存储时间戳
    QVector<double> fitnessScoreData; // 存储fitness_score

};

}  // namespace class1_ros_qt_demo

#endif /* class1_ros_qt_demo_QNODE_HPP_ */
