#include <Arduino.h>
#include <BluetoothSerial.h>

#define pinLED 2
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("SlaveLuigi", false);
  pinMode(pinLED, OUTPUT);
  if (SerialBT.hasClient()) {
    Serial.println("bluetooth conectado");
  } 


}

void loop() {

  static bool estadoLED = false;
  bool pisca;
  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;
  unsigned long intervalo = 300;
  
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    Serial.println("Comando via USB: " + comando);
  }

  if (SerialBT.available()) {
    String comando = SerialBT.readStringUntil('\n');
    comando.trim();
    Serial.printf("Comando via Bluetooth: %s", comando);

    if (comando.equalsIgnoreCase("liga")) {
      estadoLED = true;
      Serial.println("LED ligado");
      SerialBT.println("LED ligado");
    } else if (comando.equalsIgnoreCase("desliga")) {
      estadoLED = false;
      Serial.println("LED desligado");
      SerialBT.println("LED desligado");
    }
    else if (comando.equalsIgnoreCase("Iniciar o pisca"))
    {
      if(tempoAtual - tempoInicial > intervalo){
        estadoLED = !estadoLED;
        tempoInicial = tempoAtual;
    }
    }
    else if (comando.equalsIgnoreCase("desligar o pisca")){
      pisca = 0;
    }
    
  }
 

  digitalWrite(pinLED, estadoLED);
}
