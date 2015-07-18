#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Point
#/vizzy/x_out@/vizzy_iKinGazeCtrl_ros
pub = rospy.Publisher('/my_x_out',Point)
rospy.init_node('ros_tests')
r = rospy.Rate(10)
while not rospy.is_shutdown():
  r.sleep()

