

void setup()
{

  pinMode(9, OUTPUT);
}

void loop()
{

  analogWrite(9, 127);   // Turn on the LED

  delay(500);              // Wait for one second
  
  analogWrite(9, 0);    // Turn off the LED
  
  delay(500);              // Wait for one second

}

