# coding=utf-8
import rospy
from gps_processer.msg import gps


def gps_pub():
    # 数据的初始化
    x = 1.0
    y = 2.0
    state = 'working'

    # 初始化节点
    rospy.init_node('publisher')
    # 创建发布对象
    pub = rospy.Publisher('gps_info', gps, queue_size=1)

    # 设置循环间隔
    rate = rospy.Rate(1.0)
    while not rospy.is_shutdown():
        x += 1.3
        y += 1.5
        rospy.loginfo('Publisher:GPS:x = %f,y = %f', x, y)
        # 发布消息
        pub.publish(gps(x, y, state))
        rate.sleep()


if __name__ == '__main__':
    gps_pub()
