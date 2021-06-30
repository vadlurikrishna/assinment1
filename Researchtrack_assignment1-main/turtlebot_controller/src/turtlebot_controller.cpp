#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Spawn.h"

ros::Publisher pub;

void positionCallback(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("Robot position [%f, %f]", msg->x, msg->y);
  geometry_msgs::Twist vel;
  vel.linear.x=0.1;
  vel.angular.z=0.1;
  pub.publish(vel);
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "turtlebot_controller");
   ros::NodeHandle n;
   ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");
   turtlesim::Spawn srv;
   srv.request.x = 1.0;
   srv.request.y = 1.0;
   client.call(srv);

   pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
   ros::Subscriber sub = n.subscribe("/turtle1/pose", 1000, positionCallback);
   
   ros::spin();

   return 0;
}
