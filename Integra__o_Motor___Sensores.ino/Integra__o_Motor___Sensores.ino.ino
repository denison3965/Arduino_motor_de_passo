 #include <Ultrasonic.h>

//Declarações para sensores ultrasônicos
Ultrasonic sonic1(3, 2);
Ultrasonic sonic2 (5, 4);
float lsonic1, lsonic2;

//Declarações para sensores LDR
const int LDR1 = A0;
const int LDR2 = A1;
const int LDR3 = A2;
const int LDR4 = A3;
int vLDR1 = 0;
int vLDR2 = 0;
int vLDR3 = 0;
int vLDR4 = 0;

//Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 12;
const int dirpin1 = 8;
const int dirpin2 = 13;


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
//Leitura LDR
vLDR1 = analogRead(LDR1);
vLDR2 = analogRead(LDR2);
vLDR3 = analogRead(LDR3);
vLDR4 = analogRead(LDR4);
Serial.print(vLDR1-240);
Serial.print(" ");
Serial.print(vLDR2);
Serial.print("     ");
Serial.print(vLDR3);
Serial.print(" ");
Serial.print(vLDR4);
Serial.print("           ");

//Leitura HC-SR04
long dsonic1 = sonic1.timing();
long dsonic2 = sonic2.timing();
lsonic1 = sonic1.convert(dsonic1, Ultrasonic::CM);
lsonic2 = sonic2.convert(dsonic2, Ultrasonic::CM);
Serial.print(lsonic1);
Serial.print("     ");
Serial.print(lsonic2);
Serial.println(" ");

//parametros motores
digitalWrite(dirpin1, LOW);
digitalWrite(dirpin2, HIGH);

for(int x = 0; x < 400; x++) {
digitalWrite(steppin1, HIGH);
digitalWrite(steppin2, HIGH);
delayMicroseconds(300);
digitalWrite(steppin1, LOW);
digitalWrite(steppin2, LOW);
delayMicroseconds(300);
}
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
