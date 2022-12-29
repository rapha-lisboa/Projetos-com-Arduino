//Variáveis de porta
const int buzzer = 10;
const int botao1 = 8;
const int botao2 = 9;

bool estado1, estado2; //Variaveis que guardam os estados dos botões (apertado ou nao)
int frequencia = 2000; //Variavel que garda a frequencia em Hz

//Função que faz o buzzer apitar
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
  estado1 = digitalRead(botao1); //Atribui à variavel estado1 se o botão 1 está apertado ou solto
  estado2 = digitalRead(botao2); //Atribui à variavel estado2 se o botão 2 está apertado ou solto

  toca(buzzer, frequencia); //Função que quando chamada faz o buzzer apitar

  //Caso o botão 1 esteja apertado, a frequencia diminui 300Hz
  if(estado1 == 0){
    frequencia -= 300;
  }

  //Caso o botão 2 esteja apertado, a frequencia aumenta 300Hz
  if(estado2 == 0){
    frequencia += 300;
  }
}
