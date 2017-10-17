/*

This code was written by Olivier Spliethoff for the blinker project.
It uses a MPU6050 with gy521
In addision it uses 2 HC-SR04 sonor detectors
An OLED blue and Yellow display
An adafruit virbration motor

CONNECTIONS:

*/

#include <Wire.h>
#include "U8glib.h"
#include <SoftwareSerial.h>

const int trigPin = 15;
const int echoPin = 16;

const int trigPin2 = 7;
const int echoPin2 = 6;

long duration;
int distance;

long duration2;
int distance2;



///////////////////////////////// this is to draw OLED
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST); // Fast I2C / TWI
void draw(void) {
  // graphic commands to redraw the complete screen should be placed here    
  u8g.setFont(u8g_font_6x10);
  u8g.drawStr( 0, 12, "Dist:");
  u8g.drawStr( 0, 23, "Dist2:");
}
/////////////////////////end drawing oled 


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;


  Serial.print("Distance: ");
  Serial.println(distance); 






  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;

  Serial.print("Distance2 Juan: ");
  Serial.println(distance2); 



   //////////////////////////////////////////                 Picture loop of oled life data
  
  u8g.firstPage();  
  do {  
  u8g.setFont(u8g_font_6x10);
  u8g.setPrintPos(32, 13);
  u8g.print(distance);
  u8g.setPrintPos(36, 24);
  u8g.print(distance2); 
  draw();  
  } while( u8g.nextPage() );
  // rebuild the picture after some delay
  delay(50);
  
  //////////////////////////////////////////                End of oled picture loop 



delay(10); 
}

