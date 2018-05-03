#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
from std_msgs.msg import UInt16
from time import sleep
import sys, time

class joystick_to_ps3:
	def __init__(self):
		self.pub = rospy.Publisher("/motor",UInt16,queue_size = 100)
		self.subscriber = rospy.Subscriber("/joy",Joy,self.callback,queue_size = 10)
		

	def callback(self,data):
		motor_state = UInt16()	
		try:
			d1 = data.axes[0]
			d2 = data.axes[1]
			r1 = data.axes[2]
			r2 = data.axes[3]
			#print(d1)
			#print(d2)
			#print(r1)
			#print(r2)			
			rospy.loginfo(d1)
			rospy.loginfo(d2)
			rospy.loginfo(r1)
			rospy.loginfo(r2)
			
			motor_state.data = 0
			if abs(d1)-abs(d2) < 0:
				if d2 < 0:
					#forward
					motor_state.data = 1
				elif d2 > 0:
					#backward
					motor_state.data = 2
			elif abs(d1)-abs(d2) > 0:
				if d1 < 0:
					#shift right
					motor_state.data = 3
				elif d1 > 0:
					#shift left
					motor_state.data = 4


			elif r1 > 0:
				#rotate right
				motor_state.data = 5
			elif r1 < 0:
				#rotate left
				motor_state.data = 6
			else:
				motor_state.data = 0
			rospy.loginfo(motor_state.data)
			self.pub.publish(motor_state)
		except: rospy.loginfo("error")
		
				#rospy.loginfo(motor_state)
				#pub.publish(motor_state)
				#rate.sleep()

def main(args):
	ic = joystick_to_ps3()
	rospy.init_node('joystick_to_ps3',anonymous=True)
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print "Shutting down Ros Ps3 Arduino Node"

if __name__=='__main__':
	main(sys.argv)



