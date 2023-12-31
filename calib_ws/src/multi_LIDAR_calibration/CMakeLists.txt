cmake_minimum_required(VERSION 3.5.1)
project(multi_LiDAR_calibration)

find_package(Boost REQUIRED COMPONENTS thread)

set(CMAKE_BUILD_TYPE "Release")
set( CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_filters
  nav_msgs
  sensor_msgs
  message_generation
  message_runtime
  message_filters
  roscpp
  rospy
  rosbag
  std_msgs
  image_transport
  cv_bridge
  tf
)

#find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Ceres REQUIRED)

include_directories(
  include
	${catkin_INCLUDE_DIRS} 
	${PCL_INCLUDE_DIRS}
  ${CERES_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS})

catkin_package(
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy std_msgs
  DEPENDS EIGEN3 PCL 
  INCLUDE_DIRS include
)


add_executable(scanRegistration src/scanRegistration.cpp)
target_link_libraries(scanRegistration ${catkin_LIBRARIES} ${PCL_LIBRARIES})

add_executable(laserOdometry src/laserOdometry.cpp)
target_link_libraries(laserOdometry ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${CERES_LIBRARIES})

add_executable(laserMapping src/laserMapping.cpp)
target_link_libraries(laserMapping ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${CERES_LIBRARIES})

add_executable(multi_map_fusion src/multi_map_fusion.cpp)
target_link_libraries(multi_map_fusion ${catkin_LIBRARIES}  ${PCL_LIBRARIES} ${OpenCV_LIBS})
