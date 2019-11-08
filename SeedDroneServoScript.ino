/*
  Written By Techfish3000
  

  Last revision at: 04:21 PM 7/11/2019
*/

#include <Servo.h> //Includes Servo Library

Servo CupServo; //Initiates Servo

int InputPin;
int OutputPin;
int TimeExtended;
int TimeUntilExtend;


void setup() {  // Sets up the servo and the arduino pins

  InputPin = 7 // The pin that the button is connected to. Default: 7
  OutputPin = 9 // The pin the servo is connected to. Default: 9
  TimeUntilExtend = 30 // Time between button press and extension, in seconds. Default: 30
  TimeExtended = 30 // Time between extension and retraction, in seconds. Default: 30
  
  pinMode(InputPin, INPUT);
  pinMode(OutputPin, OUTPUT); 
  CupServo.attach(OutputPin);
  CupServo.write(20); // Write 20 because numbers 1-10 and 180-190 vibrate
 }

void loop() { // Loops over and over
  if (digitalRead(InputPin) == HIGH){ // IF pressed,
  while (digitalRead(InputPin) == HIGH){ // Wait until it stops being pressed
    delay(10);  // So we don't overwork it
   
   }; // Once it's unpressed,
   delay(TimeUntilExtend * 1000); // Wait a var of Seconds
   CupServo.write(100); // Rotate 90 degrees (it doesn't make sense but it works, trust me.)
   delay(TimeExtended * 1000); // Wait another var of seconds
   
}; // Once that's over,
CupServo.write(20); // Reset back to default position
delay(100); // Wait 0.1 seconds so we don't overwork it
}
