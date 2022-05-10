
#include <HCSR04.h> //inclui o diretorio sensor ultrassônico
float x;
HCSR04 hc(1,2);//initialisation class HCSR04 (trig pin , echo pin)
int led_vermelho = 4;//coloquei o relé na entra 4
int led_amarelo = 5;

void setup()
  {
    pinMode(led_vermelho, OUTPUT);//coloquei o relé como saida
    pinMode(led_amarelo, OUTPUT);//coloquei o relé como saida
    Serial.begin(9600);
}
void loop()

  { Serial.println( hc.dist() ); 
  x=( hc.dist() );
  if (x <=7){//dei o valor do x para menor ou igual a 7cm, no caso coloquei uma distância minima
  digitalWrite(led_vermelho,HIGH);
  digitalWrite(led_amarelo,LOW);// quando o valor de x ou seja quando um objeto estiver a 7cm de distância no minimo ele vai acionar a entrada de energia do relé assim ligando a torneira
  delay(500);}//delay de 2 segundos para a torneira ira ficar ligada caso o valor de x seja maior que 7cm
  else if (x >7 && x<10){
  digitalWrite(led_amarelo,HIGH);//aqui o relé ira desligar a torneira quando o valor de x for maior que 7cm
  digitalWrite(led_vermelho,LOW);
  delay(500);
}

}
