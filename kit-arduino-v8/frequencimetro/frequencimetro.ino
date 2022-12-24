const int buzzer = 10;
const int botao1 = 8;
const int botao2 = 9;

bool estado1, estado2;
int frequencia = 2000;

void toca(int buzzer, int freq){
  tone(buzzer, freq);
  delay(500);
  noTone(buzzer);
  delay(500);
}

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
}

void loop() {
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);

  toca(buzzer, frequencia);

  if(estado1 == 0){
    frequencia -= 300;
    Serial.print("botao 1");
  }

  if(estado2 == 0){
    frequencia += 300;
    Serial.print("botao 2");
  }
}
