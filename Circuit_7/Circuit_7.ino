int ledPin = 9;
int up = 3;
int down = 2;
int val = 10;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(up, INPUT);
pinMode(down, INPUT);
}

void loop() {
if (digitalRead(up)) {
  val += 1;
}
if (digitalRead(down)) {
  val -= 1;
}
analogWrite(ledPin,val);
if (val>17 && val<22) {
  digitalWrite(13,HIGH);
} else {
  digitalWrite(13,LOW);
}
delay(50);
}
