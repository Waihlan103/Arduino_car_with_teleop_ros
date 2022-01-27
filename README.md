# Arduino_car_with_teleop_ros
The project that arduino car is controlled with teleop_twist_keyboard node from ros.
In this project,I just invoke only "i","j","k","l","," that the keys to control the robot from teleop node.
"i" is the key to go forward.
"j" is the key to rotate to left.
"k" is for stop.
"l" is to rotate to right.
"," is for backward.
Note that I don't implement "u,o,m,." that are the keys to go diagonal directions.

To complete this project, we need to install ros in our machine and rosserial library.

This link is the way how to install rosserial arduino in ros.
https://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup
![arduino_rc_car_teleop]

