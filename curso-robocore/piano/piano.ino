// Definição das portas relacionadas aos botões
const int botao1 = 13;
const int botao2 = 12;
const int botao3 = 11;

// Definição da porta do buzzer
const int buzzer = 8;

// Definição das portas relacionadas aos leds
const int ledVermelho = 3;
const int ledAmarelo = 2;
const int ledVerde = 4;

// Frequencias de cada nota musical
const int c = 261; // Dó
const int d = 293; // Ré
const int e = 329; // Mi

// Variaveis para a leitura de status do botão (apertado ou solto)
bool estado1, estado2, estado3;

//Função que apaga todos os leds e faz com que o buzzer pare de apitar
void desligaTudo(){
  noTone(buzzer);
  digitalWrite(ledVermelho, 0);
  digitalWrite(ledAmarelo, 0);
  digitalWrite(ledVerde, 0);
}

void setup() {
  Serial.begin(9600);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  //Verifica os estados dos botões (apertado ou solto)
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);
  estado3 = digitalRead(botao3);

  desligaTudo();

  //Se o primeiro botão for apertado, toca a nota dó e ascende o led vermelho por 1s
  if(estado1 == 0){
    tone(buzzer, c);
    digitalWrite(ledVermelho, 1);
    delay(1000);
  }
  //Se o primeiro botão for apertado, toca a nota ré e acende o led amarelo por 1s
  if(estado2 == 0){
    tone(buzzer, d);
    digitalWrite(ledAmarelo, 1);
    delay(1000);
  }
  //Se o primeiro botão for apertado, toca a nota mi e acende o led verde por 1s
  if(estado3 == 0){
    tone(buzzer, e);
    digitalWrite(ledVerde, 1);
    delay(1000);
  }
}
