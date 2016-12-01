    /* JY-MCU Bluetooth Wireless Serial Port module for Arduino®
    
    ON and OFF Control of a LED thru Bluetooth .
    The code example will switch ON or OFF on board LED by sending command ‘B’
    or any other character thru the Bluetooth paired PC or Laptop.
    
    The pins used are designed are for JY-MCU Bluetooth Wireless Serial Port
    module with Arduino® Uno Board available from:
    
  https://core-electronics.com.au/attachments/guides/Product-User-Guide-JY-MCU-Bluetooth-UART-R1-0.pdf
    
    This example code is in the public domain.
    
    */ 
    // Declaration of constants and variable to used by program
    
    
    char recd_dat; // variable for receiving data from bluetooth serial port
    int on_brd_led = 13; // On-board LED pin detail
    
    void setup()
    {
        // initialize the serial communications:
        // serial communication is used to receive the data from
        // Bluetooth module
        
        Serial.begin(9600);//start serial communication  so the arduino will communicate over Serial
        //the key here is that the arduino is no longer communicating with a PC using Serial communication
        //It is now communicating with the bluetooth module using Serial. The bluetooth module recieves bluetooth
        //commands from another bluetooth device (IE a mobile phone) interprets the commands, and sends them 
        //to the arduino over serial.
        
        // Onboard LED pin as output
        pinMode(on_brd_led, OUTPUT);
        
        // The initial state of led is defined here.
        // HIGH on PIN will switch on the LED
        // LOW on PIN will switch off the LED
        digitalWrite(on_brd_led, LOW);
    }
    
    void loop() 
    {
       if( Serial.available() ) // if serial data is available to read 
       {
           recd_dat = Serial.read(); //read data & store it in ‘recd_dat’ 
       }
       if(recd_dat == 'B' ) // if 'B' was received
       {
           digitalWrite(on_brd_led, HIGH); // turn ON LED
        }
        else
        {
           digitalWrite(on_brd_led, LOW); // otherwise switch OFF 
        } 
        delay(10); 
        // Just wait 150ms for next reading 
    }
      
