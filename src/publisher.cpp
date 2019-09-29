#include<ros/ros.h> // ROS基本头文件
#include<gps_processer/gps.h>   // 引用自定义生成的消息类型

int main(int argc, char *argv[])
{
    // 设置消息初值
    gps_processer::gps msg;
    msg.x=1.0;
    msg.y=2.0;
    msg.state="working";

    // 初始化一个叫做publisher的节点
    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh; // 新建一个NodeHandle用于管理节点
    // 利用NodeHandle构造一个publisher
    ros::Publisher pub = nh.advertise<gps_processer::gps>("gps_info",1);
    // 设置循环迭代间隔并发布消息
    ros::Rate loop_rate(1.0);
    while (ros::ok())
    {
        msg.x += 1.3;
        msg.y += 1.5;
        ROS_INFO("Publisher:GPS:x = %f,y = %f",msg.x,msg.y);
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}