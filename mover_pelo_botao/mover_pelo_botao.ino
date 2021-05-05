const int Botao = 7;  //botão no pino 2
const int Botao2 = 8; //botão no pino 3

const int ena = 2; //habilita o motor
const int dir = 3; //determina a direção
const int pul = 4; //executa um passo
const int intervalo = 350;   //intervalo entre as 
                             // mudanças de estado do pulso

//Quanto maior o intervalo em microsegundos, mais lento o motor ira girar

boolean pulso = LOW; //estado do pulso

int estado;   //Variavel para ler o estado do pushbutton
int estado2;  //Variavel para ler o estado do pushbutton 2

void setup() {

  //Setando os meus pinos 7 e 8 como inputs para os botões
  pinMode(Botao, INPUT);
  pinMode(Botao2, INPUT);

  //Setando os pinos que o driver dos motores irão utilizar como OUTPUT
  pinMode(ena, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(pul, OUTPUT);
  
  digitalWrite(ena, LOW); //habilita em low invertida 
  digitalWrite(dir, HIGH); // low CW / high CCW 
  digitalWrite(pul, HIGH); //borda de descida


}

void loop() {
  estado = digitalRead(Botao);
  estado2 = digitalRead(Botao2);

   /*--------------------------------------------------------------------
   *  ANDAR PARA FRENTE QUANDO O BOTÃO FOR APERTADO
   * 
   * -------------------------------------------------------------------*/

  //Verificando o estado do botao 1
  if (estado == HIGH && estado2 == LOW) //camada de segurança para não ficar mudando o sentido de giro do motor direto
  {

    // Determinando um sentido horário para o motor
    digitalWrite(dir, HIGH); // low CW / high CCW

    
    pulso = !pulso; //inverte o estado da variável
    digitalWrite(pul, pulso); //atribui o novo estado à porta
    delayMicroseconds(intervalo); 
  }
  else
  {

  }

  /*--------------------------------------------------------------------
   * ANDARA PARA ATRÁS QUANDO O BOTÃO FOR APERTADO
   * 
   * -------------------------------------------------------------------*/

  //Verificando estado do botao 2
  if (estado2 == HIGH && estado == LOW) //camada de segurança para não ficar mudando o sentido de giro do motor direto
  {
    // Determinando um sentido horário para o motor
    digitalWrite(dir, HIGH); // low CW / high CCW
    
    pulso = !pulso; //inverte o estado da variável
    digitalWrite(pul, pulso); //atribui o novo estado à porta
    delayMicroseconds(intervalo); 
  }
  else
  {

  }

}
