#include <Arduino.h>
#include "BluetoothSerial.h"
#define pinLED 2
BluetoothSerial BT;
String Texto = "";
void setup() {
 BT.begin("ESPluigi", false);
 Serial.begin(9600);
 Serial.println("esperando esp");
 pinMode(pinLED, HIGH);
}


void loop() {
   static bool primeira = false;
   if(BT.hasClient() != primeira)
   {
    Serial.print("conectado");
    primeira = !primeira;
   }

   if(BT.available())
   Texto = BT.readStringUntil('\r' || '\n');
   if(Texto.equalsIgnoreCase("LIGADO"))
   {
      digitalWrite(pinLED, HIGH);
      Serial.print("LED LIGADO");
   }
   else if(Texto.equalsIgnoreCase("DESLIGADO")){
      digitalWrite(pinLED, LOW);
      Serial.print("LED DESLIGADO");
   }
 }
