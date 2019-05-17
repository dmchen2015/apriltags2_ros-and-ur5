#include "ros/ros.h"
#include "apriltags2_ros/AprilTagDetectionArray.h"
#include <iostream>
class Localizer
{
public:
  Localizer(ros::NodeHandle& nh)
  {
      ar_sub_ = nh.subscribe<apriltags2_ros::AprilTagDetectionArray>("tag_detections", 1,
      &Localizer::number_callback, this);
  }
  void number_callback(const apriltags2_ros::AprilTagDetectionArray::ConstPtr& msg)
  {
      last_msg_ = msg;
      ROS_INFO_STREAM(last_msg_->detections[0].pose.pose.pose);
      //ROS_INFO("the number %d ",);
      //ROS_INFO("%s\n", s.data.c_str());
  }

  ros::Subscriber ar_sub_;
  apriltags2_ros::AprilTagDetectionArrayConstPtr last_msg_;
};


int main(int argc, char **argv)
{
    ros::init(argc, argv,"apriltag_detector_subscriber");
    ros::NodeHandle node_obj;
    Localizer localizer(node_obj);
    //ros::Subscriber number_subscriber = node_obj.subscribe("tag_detections",1,number_callback);
    ROS_INFO("1Vision node starting");
    ros::spin();
    //return 0;
}
