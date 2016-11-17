int ledPin = 2;
void setup() {
pinMode(ledPin,OUTPUT);
  }

void loop() {
digitalWrite(ledPin,OUTPUT);
delay(800);
digitalWrite(ledPin,LOW);
delay(800);
}
