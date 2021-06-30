#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include <sstream>
#include <iostream>
#include "std_srvs/Empty.h"
#include "turtlesim/TeleportAbsolute.h"

ros::Publisher chatter_pub;

void subscriberCallback(const turtlesim::Pose::ConstPtr& pose_msg)
{
   geometry_msgs::Twist msg_sent;

   if ((pose_msg->x >= 2.0)&(pose_msg->x<=9.0))
    {
    msg_sent.linear.x = 1.0;
    msg_sent.angular.z = 0.0;
    }

    else if ((pose_msg->x > 9.0))
    {
    msg_sent.linear.x = 0.1;
    msg_sent.angular.z = 0.1;
    }

   else if ((pose_msg->x <2.0))
    {
    msg_sent.linear.x = 0.1;
    msg_sent.angular.z = -0.1;
    }

    chatter_pub.publish(msg_sent);
    
    if ((pose_msg->y >8.9))
    {
	ros::shutdown();
    }
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "turtlebot_controller");
  ros::NodeHandle n;

  ros::ServiceClient client1 = n.serviceClient<turtlesim::Kill>("/kill");
  ros::ServiceClient client2 = n.serviceClient<turtlesim::Spawn>("/spawn");

  ros::ServiceClient client3 = n.serviceClient<std_srvs::Empty>("/clear");
  ros::ServiceClient client4 = n.serviceClient<turtlesim::TeleportAbsolute>("/rt_turtle/teleport_absolute");

  
  turtlesim::Kill srv1;
  srv1.request.name = "turtle1";

  client1.call(srv1);

  turtlesim::Spawn srv2;

  srv2.request.x=5.0;
  srv2.request.y=5.0;
  srv2.request.theta=0.0;
  srv2.request.name="rt_turtle";

  client2.call(srv2);

  std_srvs::Empty srv3;
  turtlesim::TeleportAbsolute srv4;
  
  srv4.request.x=2.0;
  srv4.request.y=1.0;
  srv4.request.theta=0.0;

  client4.call(srv4);

  sleep(1);
  client3.call(srv3);
  sleep(1);
  ros::Subscriber pose_sub = n.subscribe("/rt_turtle/pose", 1000, subscriberCallback);
  chatter_pub = n.advertise<geometry_msgs::Twist>("/rt_turtle/cmd_vel", 1000);

  ros::spin();

  return 0;
}
