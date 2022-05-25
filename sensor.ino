/******************************************************************************/
/*          Projeto: Protótipo Sensor para Estacionamento em Garagem          */
/*                     PontoCanal - Ponto Makers                              */
/******************************************************************************/




//Configurações de Portas do Arduino

//Sensor
const int TRIG = 2;
const int ECHO = 3;

//Demais componentes
const int ledGreen = 4;
const int ledRed = 5;
const int ledyellow = 6;
const int buzzer = 9;

void setup() {
  Serial.begin(9600);
  
  // Configurações do Sensor
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  // Configurações do LED
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledyellow, OUTPUT);

  //Configurações do Buzzer
  pinMode(buzzer, OUTPUT); 
  
}

void loop() {
  int distancia = sensor_morcego(TRIG,ECHO);

    if(distancia > 40){
      Serial.print("ATENÇÃO:");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledyellow, LOW);
      digitalWrite(ledRed, LOW);
      noTone(buzzer);
    }

    else if (distancia < 30 && distancia > 20){
      Serial.print("PERTO:");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledyellow, HIGH);
      digitalWrite(ledRed, LOW);
      tone(buzzer,3000);
      delay(500);
      tone(buzzer,0);
      delay(500);
      }
    else{
      Serial.print("MUITO PERTO:");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledyellow, LOW);
      digitalWrite(ledRed, HIGH);
      tone(buzzer,4000);
      delay(100);
      tone(buzzer,0);
      delay(100);
      }
}

int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
