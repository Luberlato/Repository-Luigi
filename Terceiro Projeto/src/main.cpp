#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#define pinButton 23
#define pinLed 5


void setup()
{
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);

  Serial.begin(9600);
}

void loop()
{
  static int count = 0;
  unsigned long currentTime = millis();
  bool stateButton = digitalRead(pinButton);
  static bool previousStateButton = 1;
  static bool lastAction = 1;
  const unsigned long debounceTime = 50;
  static unsigned long previousDebounceTime = 0;


  if (stateButton != previousStateButton)
  {
    previousDebounceTime = currentTime;
  }

  // Verifica se a mudanca de estado esta estavel a tempo suficiente
  if ((currentTime - previousDebounceTime) > debounceTime)
  {
    if (stateButton != lastAction) // Houve alteracao proposital no botao?
    {
      lastAction = stateButton;
      if (!stateButton)
      {
        count++; // O botao foi pressionado
        Serial.println(count);
      }
    }
  }
  previousStateButton = stateButton;
  switch (count){
    case 0:
    lcd.setCursor(0,0);
  	lcd.print("BEM VINDO AO");
    lcd.setCursor(0,1);
    lcd.print("HALL DOS CAMPEOES");
    lcd.setCursor(0,2);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    lcd.print("                    ");
    break;
    case 1:
    lcd.setCursor(0,0);
    lcd.print("1X CAMPEAO  ");
    lcd.setCursor(0,1);
    lcd.print("SAO CAETANO      ");
    lcd.setCursor(0,2);
    lcd.print("ULTIMO TITULO:2004 ");
    break;
    case 2:
    lcd.setCursor(0,0);
    lcd.print("2X CAMPEAO  ");
    lcd.setCursor(0,1);
    lcd.print("ITUANO      ");
    lcd.setCursor(0,2);
    lcd.print("ULTIMO TITULO: 2014");
    break;
    case 3:
    lcd.setCursor(0,0);
    lcd.print("3X CAMPEAO  ");
    lcd.setCursor(0,1);
    lcd.print("PORTUGUESA  ");
    lcd.setCursor(0,2);
    lcd.print("ULTIMO TITULO: 1973*");
    lcd.setCursor(0,3);
    lcd.print("*DIVIDO COM O SANTOS");
    break;
    case 4:
    lcd.setCursor(0,0);
    lcd.print("4X CAMPEAO ");
    lcd.setCursor(0,1);
    lcd.print("SP ATHLETIC CLUB");
    lcd.setCursor(0,2);
    lcd.print("ULTIMO TITULO: 1911 ");
    lcd.setCursor(0,3);
    lcd.print("                       ");
    break;
    case 11:
    lcd.setCursor(0,0);
    lcd.print("11X CAMPEAO       ");
    lcd.setCursor(0,1);
    lcd.print("PAULISTANO            ");
    lcd.setCursor(0,2);
    lcd.print("ULTIMO TITULO: 1929");
    break;
    case 22:
    lcd.setCursor(0,0);
    lcd.print("22X CAMPEAO       ");
    lcd.setCursor(0,1);
    lcd.print("SPFC E SANTOS        ");
    break;
    case(26):
    lcd.setCursor(0,0);
    lcd.print("26X CAMPEAO        ");
    lcd.setCursor(0,1);
    lcd.print("PALMEIRAS           ");
    lcd.setCursor(0,2);
    lcd.print("ULTIMO TITULO: 2024");
    break;
    case 31:
    lcd.setCursor(0,0);
    lcd.print("31X CAMPEAO      ");
    lcd.setCursor(0,1);
    lcd.print("CORINTHIANS        ");
    lcd.setCursor(0,2);
    lcd.print("ATUAL CAMPEAO        ");
    lcd.setCursor(0,3);
    lcd.print("VAI CORINTHIANS    ");
    digitalWrite(pinLed, HIGH);
    delay(100);
    digitalWrite(pinLed, LOW);
    break;
    case 32:
    lcd.setCursor(0,0);
    lcd.print("               ");
    lcd.setCursor(0,1);
    lcd.print("               ");
    break;
    default:
    lcd.setCursor(0,0);
    lcd.print("A GLORIA E ETERNA");
    lcd.setCursor(0, 1);
    lcd.print("MAS QUEM VAI LEVAR?");
    lcd.setCursor(0,2);
    lcd.print("                    ");
    lcd.setCursor(0,3);
    lcd.print("                 ");
    break;
    
              
  }
    if (count > 31)
      count = 0;
}



