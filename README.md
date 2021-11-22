# ECE16_Project

Joshua Smith  
A16549656  
ECE 16 Rapid Hardware and Software Development  
Prof Ramsin Khoshabeh, PhD 
11/20/2021

## Space Invader Controller


## Design Project: Doggy Door Tracker

### Arduino code
#### DoggyDoorTracker (Main)
This file is used to collect and send data to python 
for process. A message form python turns on and off
the tracker. 
#### Ultrasonic Sensor
The ultrasonic sensor is used to measure movement
before the dog exits the door. This is due to the
fact that the webcam is inside and if only an
accelerometer was used I could not identify which 
dog has left the house. 

This sensor is measure distance. This distance
is passed to python. I found two tutorial for 
using the ultrasonic detector. These tutorial used
a delay for time on and time off. I switch this to a
non-block programming to prevent the ultrasonic 
detector delay from effect the accelerometer. 

#### Other Files
The reset of these files are the same that is used 
during lab 1-7. 
