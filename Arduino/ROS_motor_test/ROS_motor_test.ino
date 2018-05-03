/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

// motor one
int enA = 2;
int in1 = 3;
int in2 = 4;
// motor two
int enB = 7;
int in3 = 5;
int in4 = 6;
//motor three
int enA_2 = 8;
int in1_2 = 9;
int in2_2 = 10;
// motor two
int enB_2 = 13;
int in3_2 = 11;
int in4_2 = 12;
  int prev = 0;

void motor_state_machine( const std_msgs::UInt16& cmd_msg){
  //servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  //digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
  analogWrite(enA, 255);
  analogWrite(enA_2, 255);
  analogWrite(enB, 255);
  analogWrite(enB_2, 255);
  //println(cmd_msg.data);
  int current = cmd_msg.data;
  if(current != prev){
    switch(cmd_msg.data){
    case 1: //forward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in1_2, HIGH);
      digitalWrite(in2_2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      digitalWrite(in3_2, HIGH);
      digitalWrite(in4_2, LOW);
      prev = cmd_msg.data;
      break;
    case 2: //backward
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);  
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH); 
      digitalWrite(in1_2, LOW);
      digitalWrite(in2_2, HIGH);  
      digitalWrite(in3_2, LOW);
      digitalWrite(in4_2, HIGH); 
      prev = cmd_msg.data;
      break;
    case 3: //shift right
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW); 
      digitalWrite(in1_2, HIGH);
      digitalWrite(in2_2, LOW);  
      digitalWrite(in3_2, LOW);
      digitalWrite(in4_2, HIGH); 
      prev = cmd_msg.data;
      break;
    case 4: //shift left
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH); 
      digitalWrite(in1_2, LOW);
      digitalWrite(in2_2, HIGH);  
      digitalWrite(in3_2, HIGH);
      digitalWrite(in4_2, LOW); 
      prev = cmd_msg.data;
      break;
    case 5: //turn right
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      digitalWrite(in1_2, LOW);
      digitalWrite(in2_2, HIGH);
      digitalWrite(in3_2, LOW);
      digitalWrite(in4_2, HIGH);
      prev = cmd_msg.data;
      break;
    case 6:
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);  
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH); 
      digitalWrite(in1_2, HIGH);
      digitalWrite(in2_2, LOW);  
      digitalWrite(in3_2, HIGH);
      digitalWrite(in4_2, LOW);
      prev = cmd_msg.data;  
      break;
    default:
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);  
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      digitalWrite(in1_2, LOW);
      digitalWrite(in2_2, LOW);  
      digitalWrite(in3_2, LOW);
      digitalWrite(in4_2, LOW);
       prev = 0;
       break;
    }//end switch
    
  }//end if
  
}


ros::Subscriber<std_msgs::UInt16> sub("motor", motor_state_machine);

void setup(){
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA_2, OUTPUT);
  pinMode(enB_2, OUTPUT);
  pinMode(in1_2, OUTPUT);
  pinMode(in2_2, OUTPUT);
  pinMode(in3_2, OUTPUT);
  pinMode(in4_2, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
