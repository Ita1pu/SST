#include <Arduino.h>
#include "Servo.h"

// #include <BLEDevice.h>
// #include <BLEUtils.h>
// #include <BLEScan.h>
// #include <BLEAdvertisedDevice.h>

int scanTime = 5; //In seconds
// BLEScan* pBLEScan;

// class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
//     void onResult(BLEAdvertisedDevice advertisedDevice) {
//       Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
//     }
// };

Servo myServo(16, 50, 0, 10);
void setup() {
  Serial.begin(9600);  
  // Serial.println("Scanning...");

  // BLEDevice::init("");
  // pBLEScan = BLEDevice::getScan(); //create new scan
  // pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  // pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  // pBLEScan->setInterval(100);
  // pBLEScan->setWindow(99);  // less or equal setInterval value
}
void loop() {
  String duty = Serial.readString();
  if(duty.length() > 1){
    myServo.goToPosition(duty.toInt());
    Serial.print(duty);
  }
  // // put your main code here, to run repeatedly:
  // BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  // Serial.print("Devices found: ");
  // Serial.println(foundDevices.getCount());
  // Serial.println("Scan done!");
  // pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory
  delay(2000);
}