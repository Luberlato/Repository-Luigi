#include <Arduino.h>
#define canalA 5
#define canalB 18

const int8_t tabelaTransicao[4][4] = {
  { 0,  1, -1,  0},
  {-1,  0,  0,  1},
  { 1,  0,  0, -1},
  { 0, -1,  1,  0}
};

void setup() {
  pinMode(canalA, INPUT);
  pinMode(canalB, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool leituraCanalA = digitalRead(canalA);
  bool leituraCanalB = digitalRead(canalB);
  int estadoAtualEncoder = ((leituraCanalA << 1) | leituraCanalB);

  static int estadoAnteriorEncoder = 3;
  static int posicao = 0;
  static int contagem = 0;
  static int ultimaContagem = 0;

  posicao = posicao - tabelaTransicao[estadoAnteriorEncoder][estadoAtualEncoder];
  if (posicao % 4 == 0 && posicao != ultimaContagem) {
    contagem++;
    ultimaContagem = posicao;
    Serial.println(contagem);
  }

  estadoAnteriorEncoder = estadoAtualEncoder;
}




