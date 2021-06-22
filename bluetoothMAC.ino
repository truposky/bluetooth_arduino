
#include <ArduinoBLE.h>


void setup() {
  Serial.begin(9600);
  while (!Serial);


  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }
}


void loop() {
  
  BLE.setConnectable(true);
  String address = BLE.address();
  
  Serial.print("Local address is: ");
  Serial.println(address);
    
}
