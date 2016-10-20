/*
* Arduino code for SN754410 H-bridge
* motor driver control.
*Control the speed of the motor using the Serial Terminal!
* copyleft Feb. 2010, Fabian Winkler
*
*/
int speedPin = 3; // H-bridge enable pin for speed control
int motor1APin = 6; // H-bridge leg 1
int motor2APin = 7; // H-bridge leg 2
int ledPin = 13; // status LED
int speed_value_motor1; // value for motor speed
int enteredSpeed=0;


void setup() {
  // set digital i/o pins as outputs:
  pinMode(speedPin, OUTPUT); // set the speed control pin as an output
  pinMode(motor1APin, OUTPUT);// set direction control pin 1 as an output
  pinMode(motor2APin, OUTPUT);// set direction control pin 2 as an output(You need two direction pins!)
  pinMode(ledPin, OUTPUT);//setting LED pin to HIGH for forward direction, and off for Reverse
  
  Serial.begin(9600);// opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
                // control the speed by entering 0- 255 on the serial terminal            
    
                // read the entered value in the serial terminal
                enteredSpeed = Serial.read();

                // print the entered value to the terminal!
                Serial.print("The entered speed is: ");
                Serial.println(enteredSpeed, DEC);
        }
  
  digitalWrite(ledPin, HIGH); // status LED is always on
  
  // put motor in forward motion
  digitalWrite(motor1APin, LOW); // set leg 1 of the H-bridge low
  digitalWrite(motor2APin, HIGH); // set leg 2 of the H-bridge high
  // just invert the above values for reverse motion,
  // i.e. motor1APin = HIGH and motor2APin = LOW
  
  // control the speed 0- 255
  analogWrite(speedPin, enteredSpeed); // output speed as
  // PWM value
}
