#include <Arduino.h>
#define pinLED 2

void setup() {
  Serial.begin(115200);
  Serial.println("Comunicação Serial Iniciada");
  pinMode(pinLED, OUTPUT);
}

void loop() {
  static bool estadoLED = 0;
  static bool pisca;
  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;
  static unsigned long intervalo = 500;
  
  if(Serial.available()){
    String msg = Serial.readStringUntil('\n');
    msg.trim();
    if(msg.equalsIgnoreCase("liga")){
      Serial.println("LED LIGADO");
      estadoLED = 1;
    }
    else if (msg.equalsIgnoreCase("desliga")){
      estadoLED = 0;}
    else if (msg.equalsIgnoreCase("pisca")){
      pisca = 1;
    }
    else if (msg.equalsIgnoreCase("desligar o pisca")){
      pisca = 0;
    }
    if(msg.equalsIgnoreCase("ace")){
      intervalo -= 50;
      if(intervalo < 50){
        intervalo = 50;
        Serial.println("velocidade maxima atingida");
      }
    }
    else if(msg.equalsIgnoreCase("fre")){
      intervalo += 50;
      if(intervalo > 1000){
        intervalo = 1000;
        Serial.print("velocidade minima atingida");
      }
    }
  }
  if (pisca){
    if(tempoAtual - tempoInicial > intervalo){
      estadoLED = !estadoLED;
      tempoInicial = tempoAtual;
    }

    
  }
  
  

  digitalWrite(pinLED, estadoLED);
}

