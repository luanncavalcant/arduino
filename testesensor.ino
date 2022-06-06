//Leitura de distância com o sensor HC-SR04
#include <Ultrasonic.h>
 Ultrasonic ultrassom(2,3); // define o nome do sensor(ultrassom)
//e onde esta ligado o trig(2) e o echo(3) respectivamente
long cm;
int led_verde = 5;
int led_amarelo = 6;
int led_vermelho = 7;

int buzzer = 12;
// Esta função "setup" roda uma vez quando a placa e ligada ou resetada
 void setup() {
 Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.

  pinMode(led_verde,OUTPUT);
  pinMode(led_amarelo,OUTPUT);
  pinMode(led_vermelho,OUTPUT);
  
 
 }
// Função que se repete infinitamente quando a placa é ligada
 void loop()
 {
   cm = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
                                     // centímetros(CM) ou polegadas(INC)
   Serial.print(cm );//imprime o valor da variável distancia
   Serial.println("cm");
   delay(100);
    if(cm > 50){
   digitalWrite(led_verde, HIGH);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_vermelho, LOW);
    buzzer_led_verde();
  }
  else if (cm < 50 && cm > 30){
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_vermelho, LOW);
    buzzer_led_amarelo();
  }
  else{
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_vermelho, HIGH);
    buzzer_led_vermelho();
  }
 }

 void buzzer_led_verde(){
 tone(buzzer, 1000);
    delay(300);
    noTone(buzzer);
    delay(300);
}

void buzzer_led_amarelo(){
  tone(buzzer, 1000);
    delay(150);
    noTone(buzzer);
    delay(150);
}

void buzzer_led_vermelho(){
  tone(buzzer, 1000);
    delay(80);
    noTone(buzzer);
    delay(80);
}
