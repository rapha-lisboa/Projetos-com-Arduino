//Portas referentes aos leds do circuito
const int ledVermelho = 13;
const int ledAmarelo = 12;
const int ledVerde = 11;
const int ledPvermelho = 10;
const int ledPverde = 9;

//Array booleana que guarda o estado de cada um dos 3 leds: a casa 0 indica o vermelho, a casa 1 indica o amarelo e a casa 2 indica o verde
//a respeito do sinal de pedestres, eles acendem sincronizadamente baseados no estado do led vermelho
bool estados[3] = {false, false, false};

void setup(){
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledPvermelho, OUTPUT);
  pinMode(ledPverde, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  //Código referente ao led vermelho do sinal de carros e os leds do sinal de pedestres
  estados[0] = !estados[0];
  digitalWrite(ledVermelho, estados[0]);
  digitalWrite(ledPverde, estados[0]);
  digitalWrite(ledPvermelho, !estados[0]);
  delay(1000);
  estados[0] = !estados[0];
  digitalWrite(ledVermelho, estados[0]);
  digitalWrite(ledPverde, estados[0]);
  delay(1000);

//Código referente ao led amarelo do sinal de carros  
  estados[1] = !estados[1];
  digitalWrite(ledAmarelo, estados[1]);
  digitalWrite(ledPvermelho, !estados[0]);
  delay(1000);
  estados[1] = !estados[1];
  digitalWrite(ledAmarelo, estados[1]);
  digitalWrite(ledPvermelho, !estados[0]);
  delay(1000);

  //Código referente ao led verde do sinal de carros
  estados[2] = !estados[2];
  digitalWrite(ledVerde, estados[2]);
  digitalWrite(ledPvermelho, !estados[0]);
  delay(1000);
  estados[2] = !estados[2];
  digitalWrite(ledVerde, estados[2]);
  digitalWrite(ledPvermelho, !estados[0]);
  delay(1000);
}