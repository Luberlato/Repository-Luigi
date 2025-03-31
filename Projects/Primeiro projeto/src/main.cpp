#include <Arduino.h>
#define pinLED 2
#define pinBotao 0

void setup() {
    pinMode(pinLED,OUTPUT);
    pinMode(pinBotao,INPUT);
}
bool estadoBotao;
void loop() {
    estadoBotao = digitalRead(pinBotao);
    if(!estadoBotao)
        digitalWrite(pinLED,HIGH);
    else
        digitalWrite(pinLED,LOW);
}


