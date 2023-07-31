#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "go_to");
    ros::NodeHandle nh;
    ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // Wait for the turtlesim to start
    ros::Duration(1.0).sleep();

    geometry_msgs::Twist target_twist;
    target_twist.linear.x = 5.0; // Linear velocity in x-direction
    target_twist.linear.y = 5.0; // Linear velocity in y-direction (slanted line)
    target_twist.linear.z = 0.0; // No vertical movement
    target_twist.angular.x = 0.0; // No roll movement
    target_twist.angular.y = 0.0; // No pitch movement
    target_twist.angular.z = 0.0; // No yaw movement

    // Publish the target twist
    cmd_vel_pub.publish(target_twist);

    ros::spinOnce(); // Process any callbacks once

    // Keep the turtle moving for a few seconds
    ros::Duration(5.0).sleep();

    // Stop the turtle by publishing zero velocities
    target_twist.linear.x = 0.0;
    target_twist.linear.y = 0.0;
    cmd_vel_pub.publish(target_twist);

    return 0;
}

