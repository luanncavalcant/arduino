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

// Variaveis para funcionamento do Buzzer
float seno;
int frequencia;

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

    if(distancia >20){
      Serial.print("ATENÇÃO");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledyellow, LOW);
      digitalWrite(ledRed, LOW);
      noTone(buzzer);
    }

    else if (distancia < 19 && distancia > 10){
      Serial.print("PERTO:");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledyellow, HIGH);
      digitalWrite(ledRed, LOW);
      }
    else{
      Serial.print("Muito perto");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledyellow, LOW);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer_1();
      }
  delay(100);
  
}


int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}

//Função para execução do Alarme Sonoro
void tocaBuzzer_1(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 2000+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}
}
