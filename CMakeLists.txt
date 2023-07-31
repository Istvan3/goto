cmake_minimum_required(VERSION 3.0.2)
project(goto)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(go_to src/go_to.cpp)
target_link_libraries(go_to ${catkin_LIBRARIES})

