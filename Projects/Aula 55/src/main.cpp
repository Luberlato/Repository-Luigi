#include <Arduino.h>
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#define pinLED 2
String palavra = "";

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP DO LUIGI");
  SerialBT.print("Escolha um LED ENTRE 1 E 4");

  pinMode(pinLED, OUTPUT);
}

void loop() {
  while (SerialBT.available()) {
    char caractere = SerialBT.read();
    char numeroPino = SerialBT.read();
    SerialBT.printf("Você digitou o caractere: %c\r\n", caractere);

    if (caractere == '\n') { 
      SerialBT.print("Você escolheu o LED: ");
      SerialBT.println(palavra);
      palavra = "";

      
      
    }
    
    else if (caractere != '\r') { 
      palavra += caractere;
    }
  }
}

