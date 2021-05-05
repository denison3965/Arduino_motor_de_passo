const int ena = 2; //habilita o motor
const int dir = 3; //determina a direção
const int pul = 4; //executa um passo
const int intervalo = 350;   //intervalo entre as 
                             // mudanças de estado do pulso

//Quanto maior o intervalo em microsegundos, mais lento o motor ira girar

boolean pulso = LOW; //estado do pulso

const int counter = 30000;

void setup()
{
pinMode(ena, OUTPUT);
pinMode(dir, OUTPUT);
pinMode(pul, OUTPUT);
digitalWrite(ena, LOW); //habilita em low invertida 
digitalWrite(dir, HIGH); // low CW / high CCW 
digitalWrite(pul, HIGH); //borda de descida
}



// O PIN que executara o passo, vai ser chaveado pelo próprio void loop
void loop()
{

  // Determinando um sentido horário para o motor
  digitalWrite(dir, HIGH); // low CW / high CCW


  // Motor gira por alguns instantes em um sentido
  for(int i = 0; i < counter; i++)
  {
    pulso = !pulso; //inverte o estado da variável
    digitalWrite(pul, pulso); //atribui o novo estado à porta
    delayMicroseconds(intervalo); 
     
  }

  // Determinando sentido anti-horário
  digitalWrite(dir, LOW); // low CW / high CCW

  // Motor gira por alguns instantes em outro sentido
  for(int i = 0; i < counter; i++)
  {
    pulso = !pulso; //inverte o estado da variável
    digitalWrite(pul, pulso); //atribui o novo estado à porta
    delayMicroseconds(intervalo); 
  }
 

}
