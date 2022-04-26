#include <LiquidCrystal.h>

//INICIALIZA
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
    Serial.println("Configurando... ");
    
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Inicializando...");
    delay(3000);
    lcd.setCursor(6, 1);
    lcd.print("Ta indo...");  
    delay(2000);
    lcd.clear();
  
    Serial.println("PROJETO DISPLAY LCD");
  
    Serial.println("PROJETO");
    lcd.setCursor(0, 0);
    lcd.print("PROJETO");
    delay(1000);
    Serial.println("DISPLAY LCD");
    lcd.setCursor(4, 1);
    lcd.print("DISPLAY LCD");
    delay(2000);
    lcd.clear();
  
    Serial.println("Carregando... ");
  
  for (int i = 0; i <= 15; i++){
    lcd.setCursor(0, 0);
    lcd.print("Carregando... ");
    lcd.setCursor(i, 1);
    lcd.print("*");
    delay(200);
    lcd.clear();
  }
   
  Serial.println("## SETUP COMPLETO ##");


}

void montaTelaHello(){
  Serial.println("Configurando... ");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OLA");
    delay(1000);
    lcd.setCursor(8, 1);
    lcd.print("MUNDO...");
    delay(1000);
}

void montaTelaBlank() {
  Serial.println("called montaTelaClear()");
    lcd.clear();
    delay(1000);


}

void loop() {

  montaTelaHello();
  montaTelaBlank();


}
