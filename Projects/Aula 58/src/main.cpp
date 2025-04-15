#include <Arduino.h>
#include <BluetoothSerial.h>
#define pinLED 2
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  if (!SerialBT.begin("MasterLuigi", true)){
    Serial.println("Erro ao iniciar o Bluetooth no modo master"); //Se a comunicaçao bluetooth master falhar retorna essa mensagem
  }
  else{
    Serial.println("Your bluetooth device is ready to pair");
  }
  if (!SerialBT.connect("SlaveLuigi")){
    Serial.println("Erro ao se conectar ao slave");
  }
  else{
  Serial.println("Your Bluetooth device is connected successfully.");
  }
}

void loop() {
  
  if(Serial.available()){
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    Serial.println(comando);
  }
  if(SerialBT.available()){
    String comando = Serial.readStringUntil('\n');
    comando.trim();
    Serial.println(comando);
}
}


