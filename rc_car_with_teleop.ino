#include <ros.h>
#include <geometry_msgs/Twist.h>

#define IN1 13
#define IN2 12
#define IN3 11 
#define IN4 10

void onTwist(const geometry_msgs::Twist& msg)
{
  //forward
  if(msg.linear.x > 0)
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  //backward
  else if(msg.linear.x < 0)
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
  //right
  else if(msg.angular.z < 0)
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    
  }

  else if(msg.angular.z > 0)
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  else 
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel",onTwist); 

ros::NodeHandle nh;

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
}
