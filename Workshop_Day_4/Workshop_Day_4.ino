/**********************************************************************************
Ardunio Workshop Day 4
Purpose: Use a potentiometer to perfotm an analog control of the speed of a motor.
***********************************************************************************/

int potPin = A0; //Potentiometer Pin
int motorPin = 9;  //MotorPin
int potValue = 0;   //ReadValue of Potentiometer state
int motorValue = 0;  //Analog state of Motor
void setup() {
 // initialize serial communications at 9600 bps:
 Serial.begin(9600);
 pinMode(potPin, INPUT); 
 pinMode(motorPin, OUTPUT);
 pinMode(potValue, OUTPUT);
}
void loop() {
 potValue = analogRead(potPin);  //Read Value of potentiometer state
 motorValue = map(potValue, 0, 1023, 0, 255); // Map potentiometer value (0, 1023) to (0, 255)
 analogWrite(motorPin, motorValue);  // Analog control of speed of the motor
 
 //Print out potentiometer value
 Serial.print("potentiometer = " );     
 Serial.print(potValue);
 
 //Print out motor value
 Serial.print("t motor = ");
 Serial.println(motorValue);
 
 delay(2);    //I need some time interval, but i won't delay your program.
}
