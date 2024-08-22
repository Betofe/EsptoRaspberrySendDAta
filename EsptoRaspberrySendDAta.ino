/*
 Name:		EsptoRaspberrySendDAta.ino
 Created:	4/5/2023 3:53:45 PM
 Author:	Imami Joel Betofe
*/

#include <HardwareSerial.h>

// Define serial port
HardwareSerial espSerial (1);
int myInt = 42;
byte packedInt[4];

void setup() {
    // Open serial port
    Serial.begin(115200);
    // initialize the software serial port at 9600 baud
    espSerial.begin(9600, SERIAL_8N1, 18, 19);
    

}

void loop() {
    // Integer to send


    // Pack integer as 4-byte binary string

    for (int i = 0; i < 2; i++) {
        //packedInt[i] = (myInt >> (i * 8)) & 0xFF;
        packedInt[i] = highByte(myInt);
        Serial.println(packedInt[i], BIN);
        packedInt[i] = lowByte(myInt);
        Serial.println(packedInt[i], BIN);
    }
   
    // Send packed integer over serial port
    espSerial.write(packedInt, 4);

    // Wait for a bit before sending the next integer
    delay(1000);
}

