# coding=utf-8
import math
import rospy
from gps_processer.msg import gps


def callback(gps):
    distance = math.sqrt(math.pow(gps.x, 2)+math.pow(gps.y, 2))
    rospy.loginfo('Subscriber:Distance to origin = %f,state = %s',
                  distance, gps.state)


def gps_sub():
    # 初始化节点
    rospy.init_node("subscriber")
    # 开始订阅
    rospy.Subscriber('gps_info', gps, callback)
    # 循环
    rospy.spin()


if __name__ == '__main__':
    gps_sub()
