#include<ros/ros.h>
#include<gps_processer/gps.h>
#include<std_msgs/Float32.h>    //ROS中的Float32类型

void gpsCallback(const gps_processer::gps::ConstPtr &msg)
{
    std_msgs::Float32 distance;
    distance.data = sqrt(pow(msg->x,2)+pow(msg->y,2));
    ROS_INFO("Subscriber:Distance to origin = %f,state = %s",distance.data,msg->state.c_str());

}

int main(int argc, char *argv[])
{   
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("gps_info",1,gpsCallback);
    ros::spin();
    return 0;
}