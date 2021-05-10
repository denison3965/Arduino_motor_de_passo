



//Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 9;
const int dirpin1 = 13;
const int dirpin2 = 11;
int x = 0;


const bool direcao = HIGH;

void setup() {
//Iniciando monitor serial
Serial.begin(9600);

//declaração de IO
pinMode(steppin1, OUTPUT);
pinMode(steppin2, OUTPUT);
pinMode(dirpin1, OUTPUT);
pinMode(dirpin2, OUTPUT);

}

void loop(){

char c = Serial.read();

 //parametros motores
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, HIGH);
  delay(100);

if (c == 'a')
{
 ;
  
  for(x = 0; x < 3600; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
  }


  x = 0;
}

c = 'b';


}
/*if (lsonic1 < 10.00) {
digitalWrite(7, LOW);
}
else
digitalWrite(7, HIGH);

if (lsonic2 < 10.00) {
digitalWrite(8, LOW);
}
else
digitalWrite(8 , HIGH);
*/
