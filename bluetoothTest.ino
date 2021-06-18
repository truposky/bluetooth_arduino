#include <HardwareBLESerial.h>//todavia no se usa
#include <ArduinoBLE.h>

void setup() {
  //blink
  pinMode(LED_BUILTIN, OUTPUT);
 if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }
  BLE.setDeviceName("arduino");

  // ...  

  // start advertising
  BLE.advertise();
  Serial.println("Esto es una prueba");
}

void loop() {
  if (BLE.connected()) {
    // …
    for(int i=0;i<10;i++){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);    // wait for a second
    }
   
  }
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();//necesito esto para saber la direccion del dispositivo que se conecta
  
  // if a central is connected to peripheral:
  if (central) {//cuando se conecta despues de un tiempo se pierde la conexion, tiene que ver con algo de crear un servicio de bluetooth
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());
    
  }
}
