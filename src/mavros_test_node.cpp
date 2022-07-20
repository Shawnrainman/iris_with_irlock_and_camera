#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Vector3.h>
#include <mavros_msgs/LandingTarget.h>

ros::Subscriber lt_marker_sub;
ros::Subscriber pose_in_sub;

void pose_in_cb(const geometry_msgs::PoseStamped::ConstPtr& msg) {

	ROS_INFO("pose_in Pose:\nposition_x: %f, position_y: %f, position_z: %f\norientation_x: %f, orientation_y: %f, orientation_z: %f, orientation_w: %f\n", msg->pose.position.x, msg->pose.position.y, msg->pose.position.z, msg->pose.orientation.x, msg->pose.orientation.y, msg->pose.orientation.z, msg->pose.orientation.w);
	std::cout << "pose_in Pose:\nposition_x: " << msg->pose.position.x << ", position_y: " << msg->pose.position.y
		<< ", position_z: " << msg->pose.position.z << ", orientation_x: " << msg->pose.orientation.x
		<< ", orientation_y: " << msg->pose.orientation.y << ", orientation_z: " << msg->pose.orientation.z
		<< ", orientation_w: " << msg->pose.orientation.w << std::endl;
}

void lt_marker_cb(const geometry_msgs::Vector3Stamped::ConstPtr& msg) {
	ROS_INFO("lt_marker Vector3:\nx: %f, y: %f, z: %f\n", msg->vector.x, msg->vector.y, msg->vector.z);
	std::cout << "lt_marker Vector3:\nx: " << msg->vector.x << ", y: " << msg->vector.y << ", z: " << msg->vector.z << std::endl;
}


int main(int argc, char **argv) {
	ros::init(argc, argv, "mavros_test_node");
	ros::NodeHandle nh;

	ros::Rate(50);

	lt_marker_sub = nh.subscribe<geometry_msgs::Vector3Stamped>("/iris_0/mavros/landing_target/lt_marker", 1000, lt_marker_cb);
	pose_in_sub = nh.subscribe<geometry_msgs::PoseStamped>("/iris_0/mavros/landing_target/pose_in", 1000, pose_in_cb);

	ros::spin();
}
