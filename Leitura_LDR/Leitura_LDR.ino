#include <Ultrasonic.h>

//Declarações para sensores ultrasônicos
Ultrasonic sonicF (22, 23);
Ultrasonic sonicL (24, 25);
Ultrasonic sonicR (26, 27);
Ultrasonic sonicB (28, 29);
float lsonicF, lsonicL, lsonicR, lsonicB;


//Declarações para sensores LDR
const int sensorEE = A0;
const int sensorED = A1;
const int sensorCE = A2;
const int sensorCD = A3;
const int sensorDE = A4;
const int sensorDD = A5;
int vsensorEE = 0;
int vsensorED = 0;
int vsensorCE = 0;
int vsensorCD = 0;
int vsensorDE = 0;
int vsensorDD = 0;

void setup() {
Serial.begin(9600);
}

void loop(){
  
//Leitura LDR
vsensorEE = analogRead(sensorEE);
vsensorED = analogRead(sensorED);
vsensorCE = analogRead(sensorCE);
vsensorCD = analogRead(sensorCD);
vsensorDE = analogRead(sensorDE);
vsensorDD = analogRead(sensorDD);
Serial.print(vsensorEE);
Serial.print(" ");
Serial.print(vsensorED);
Serial.print(" ");
Serial.print(vsensorCE);
Serial.print(" ");
Serial.print(vsensorCD);
Serial.print(" ");
Serial.print(vsensorDE);
Serial.print(" ");
Serial.print(vsensorDD);
Serial.print("           ");

//Leitura HC-SR04
long dsonicF = sonicF.timing();
long dsonicL = sonicL.timing();
long dsonicR = sonicR.timing();
long dsonicB = sonicB.timing();
lsonicF = sonicF.convert(dsonicF, Ultrasonic::CM);
lsonicL = sonicL.convert(dsonicL, Ultrasonic::CM);
lsonicR = sonicR.convert(dsonicR, Ultrasonic::CM);
lsonicB = sonicB.convert(dsonicB, Ultrasonic::CM);
Serial.print(lsonicF);
Serial.print(" ");
Serial.print(lsonicL);
Serial.print(" ");
Serial.print(lsonicR);
Serial.print(" ");
Serial.print(lsonicB);
Serial.println();
}
