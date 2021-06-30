# Researchtrack_assignment1

# Done by Aatheethyaa Dhanasekaran(Matricola No.:S5051520)

This assignment is based on controlling a holonomic robot in a 2d space with 2d simulator.a new ROS packages is created with two ROS nodes are developed and cpp is used for writing the codes.First node in the package is incharge for calling the service for recieving a random target and making the robot to reach the target,second node is responsible for the service server and it replies to client with random target having x and y in the interval between (-6.0,6.0).The target is cinsidered to be reached when the distance between robot and target is below 0.1.

# Description of First node:
The first node implements a ROS publisher,cmd_vel which is used for setting robot speed and a ROS subscriber which is named as odom,to know the actual position of the robot and also a ROS client to recieve the random target.File named as robot_position.cpp is used to write codes for the first node in the assignment1 package.The position of the robot is defined in topic odom,by using a nav_msgs/Odometry,Odometry message which is defined in the package nav_msgs.This means that the x and y position of the robot is retrieved by reading the pose.pose.position.x and pose.pose.position.y fields of the message received by the callback associated with the subscriber.

# Server:my_srv
The server package my_srv contains the C++ file position_server.cpp which contains the source code for generating random integer within a specified range and advertising it over the node /position. It uses a custom message which provides responses with two integers namely min and max,whereas the request is empty.

# Instructions for Running the Project
The following steps is used to prepare the necessary environment and dependencies to run the assignment:

1.Open command line terminal and navigate to the the local workspace using  *cd /<name_of_workspace>(my_ros_ws)/src* command.

2.Clone the remote repository of assignment in your local workspace using the command: git clone    https://github.com/Aathee1103/Researchtrack_assignment1.git 

3.Build the file using *catkin_make* in the root folder of the workspace.

4.Run the command *rospack profile* to read and parse the .xml for each package and provide a complete dependency tree for all packages.

# Accessing the Assignment

1.The simulator for the holomonicc robot in 2d space with 2d simulator,this simulator can be launched using the command:

     rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
2.In the new command terminal,run the command to initialise the service node:

     rosrun my_srv position_server
3.In the new command terminal,run the command to intialise the node for recieving the random target and make the robot to reach the target:

     rosrun assigntment1 assignment1
4.In the new command terminal,run the commoand to view the computational graph:

     rosrun rqt_graph rqt_graph




