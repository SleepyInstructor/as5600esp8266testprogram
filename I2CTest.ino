#include "Wire.h"
//Copyright: Kim Lam
//Description: Test program for nodeMCU board.
//This program demonstrates simultanous connections to 3 i2C busses using the 8266 wire library.
// Notes provided are the the NodeMCU board, in which not all the pins can be used for i2c operation

//Pins D1,D2 can be used for i2c
//     D3,D4 can be used for i2c
//     D5,D6 can be usef ro i2c
//     D7 can also be used, but D8 cause problem for some reason.
//     D0, does not work for some reason.
//     Connecting D8 to a pull down interfere with device programming.

const int deviceAddress = 0x36;
const byte angleAddress = 0x0E;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Send address
 
  
}

int readDataFromChip(int sca, int scl){
   Wire.begin(sca,scl);
  Wire.beginTransmission(deviceAddress);
  Wire.write(angleAddress);
  Wire.endTransmission();
  delay(1);
 
  Wire.requestFrom(deviceAddress,2);
  byte data1;
  byte data2;
  int angle;
  if(Wire.available() == 2){
    data1 = Wire.read();
    data2 = Wire.read();
    angle = data1;
  } else{
    Serial.println("Error");
  }
  return data1; 
}
void loop() {
  // put your main code here, to run repeatedly:

  int sensor1 = readDataFromChip(D1,D2);
  int sensor2 = readDataFromChip(D3,D4);
  int sensor3 = readDataFromChip(D7,D8);
  Serial.print("Angle 1:");
  Serial.print(sensor1);
  Serial.print(" Angle 2:");
  Serial.print(sensor2);
  Serial.println(" Angle 3:");
  Serial.println(sensor3);
  delay(100);
}
