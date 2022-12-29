const int botao1 = 13;
const int botao2 = 12;
const int botao3 = 11;
const int botao4 = 10;
const int buzzer = 8;
const int ledVermelho = 5;
const int ledBranco = 4;
const int ledAmarelo = 3;
const int ledVerde = 2;

#define NOTE_D4  294
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_A5  880
#define vitoria 2000

static bool luzes[4] ={false, false, false, false};
static int sequencia[100];
static int jogadas[100];
static int pos = 0;
static int ultimaPos;
static int ind = 0;
static int estado1;
static int estado2;
static int estado3;
static int estado4;

int aleatorio;
int rodada = 1;
int tempo = 1000;
bool apertou = false;
bool perdeu = false;

void leBotoes(){
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);
  estado3 = digitalRead(botao3);
  estado4 = digitalRead(botao4);
}

void apagaTudo(){
  digitalWrite(ledVermelho, 0);
  digitalWrite(ledBranco, 0);
  digitalWrite(ledAmarelo, 0);
  digitalWrite(ledVerde, 0);
}

void acendeTudo(){
  digitalWrite(ledVermelho, 1);
  digitalWrite(ledBranco, 1);
  digitalWrite(ledAmarelo, 1);
  digitalWrite(ledVerde, 1);
}

void piscaTudo(){
  acendeTudo();
  delay(400);
  apagaTudo();
  delay(400);
}

void fazBarulho(){
  if(luzes[0]){
    tone(buzzer, NOTE_D4);
  } else if (luzes[1]){
    tone(buzzer, NOTE_G4);
  } else if (luzes[2]){
    tone(buzzer, NOTE_A4);
  } else if (luzes[3]) {
    tone(buzzer, NOTE_A5);
  }
}

void acendeLuz(int num){
  luzes[num] = true;

  fazBarulho();

  digitalWrite(ledVermelho, luzes[0]);
  digitalWrite(ledBranco, luzes[1]);
  digitalWrite(ledAmarelo, luzes[2]);
  digitalWrite(ledVerde, luzes[3]);
  delay(tempo);

  luzes[num] = false;

  apagaTudo();
  noTone(buzzer);

  delay(300);
}

void guardaSequencia(int num){
  sequencia[pos] = num+1;
  //Serial.println(sequencia[pos]);
  pos++;
  ultimaPos++;
}

void leSequencia(){
  for(int s = 0; s < ultimaPos; s++){
    acendeLuz(sequencia[s]-1);
  }
}

void jogadaNova(int num){
  guardaSequencia(num);
  acendeLuz(num);
}

void guardaJogada(int ind){
  if(estado1 == 0){
    jogadas[ind] = 1;
    acendeLuz(0);
  } else if(estado2 == 0){
    jogadas[ind] = 2;
    acendeLuz(1);
  } else if(estado3 == 0){
    jogadas[ind] = 3;
    acendeLuz(2);
  } else if(estado4 == 0){
    jogadas[ind] = 4;
    acendeLuz(3);
  }
}

void setup(){
  Serial.begin(9600);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(botao4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledBranco, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  randomSeed(analogRead(A0));

}

void loop(){
  ind = 0;
  if(perdeu == false){
    //Sorteia um numero novo
    aleatorio = random(4);

    //Le a sequencia que ja foi jogada em rodadas anteriores
    leSequencia();

    //Cria mais uma jogada aleatoria
    jogadaNova(aleatorio);

    Serial.println(jogadas[rodada-1]);

    //Espera o jogador jogar
    while(jogadas[rodada-1] == 0){
      while(apertou == false){
        leBotoes();

        if(estado1 == 0 || estado2 == 0 || estado3 == 0 || estado4 == 0){
          Serial.print("apertou algum");
          apertou = true;
        }
      }

      apertou = false;
      guardaJogada(ind);

      if(jogadas[ind] != sequencia[ind]){
        perdeu = true;
        break;
      }

      ind++;
    }
  }

  if(perdeu == false){
    piscaTudo();
    rodada++;
    
    if(tempo != 500){
      tempo = (((-250)*rodada)+7250)/7;
    }
  } else {
    digitalWrite(ledVermelho, 1);
    tone(buzzer, 150);
    delay(600);
    digitalWrite(ledVermelho, 0);
    noTone(buzzer);
    delay(1000);    
  }
}