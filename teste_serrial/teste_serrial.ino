const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  char c = Serial.read();

  if (c == 'a')
  {
    digitalWrite(ledPin, HIGH);
  }

  if (c == 'b')
  {
    digitalWrite(ledPin, LOW);
  }

}
