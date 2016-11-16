/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-10 .: Temperature :. (TMP36 Temperature Sensor) |
 *     ---------------------------------------------------------
 *   
 *  A simple program to output the current temperature to the IDE's debug window 
 * 
 *  For more details on this circuit: http://tinyurl.com/c89tvd 
 */

//TMP36 Pin Variables
int temperaturePin = 0;
const int ledPins[ ] = {6,7};
const int buttonPins[ ] = {0,1};






void setup()
{
  Serial.begin(9600);  //Start the serial connection with the copmuter
                       //to view the result open the serial monitor 
                       //last button beneath the file bar (looks like a box with an antenae)
  pinMode(ledPins[6],OUTPUT);
  pinMode(ledPins[7],OUTPUT);
  pinMode(buttonPins[0], INPUT);
  pinMode(buttonPins[1], INPUT);
  
}
 
void loop()                    
{
 float temperature = getVoltage(temperaturePin);  
 temperature = (((temperature - .5) * 100) * 1.8) + 32;          
                                                  


 int heating = false;
 int cooling = false;

 int targetTemp = 80;
 int x = 0;
 
                                        
 Serial.println(temperature);                     
 Serial.println("Degrees F, CURRENT TEMP");
 Serial.println(targetTemp);
 Serial.println("Degrees F, TARGET TEMP"); 
 delay(2000);                                     


 int buttonState0 = digitalRead(buttonPins[0]);
 int buttonState1 = digitalRead(buttonPins[1]);


/*
  if (buttonState1 == LOW) {
    for (x=0; x < 100; x = x + 2) {
   digitalWrite(ledPins[0], HIGH);
   digitalWrite(ledPins[1], LOW);
    }
}
else {
   digitalWrite(ledPins[0], LOW);
}
 if (buttonState0 == LOW) {
  x = x+1;
  for (x=1; x < 100; x = x + 2) {
     digitalWrite(ledPins[1], HIGH);
     digitalWrite(ledPins[0], LOW); 
  }
}
else {
     digitalWrite(ledPins[1], LOW);
}
*/
 
  if (buttonState1 == LOW) {     
    targetTemp = 75;    
    Serial.println("target Temp 75"); 
    delay(2000);                          
  }


  if (buttonState0 == LOW) {
    targetTemp = 85;
    Serial.println("target Temp 85");
    delay(2000); 
  }


if (temperature < targetTemp -3) {
  cooling = true;
  heating = false;
  Serial.println("COOLING, not heating");
  delay(2000);
}
 else if (targetTemp + 3 < temperature) {
  cooling = false;
  heating = true;
  Serial.println("HEATING, not cooling");
  delay(2000);
 }
 else {
  cooling = false;
  heating = false;
  Serial.println("no heating or cooling");
  delay(2000);
 }

  
  if (cooling == true) {
    digitalWrite(ledPins[0], HIGH);
  }
  else {
    digitalWrite(ledPins[0], LOW);
  }


  if (heating == true) {
    digitalWrite(ledPins[1], HIGH);
  }
  else {
    digitalWrite(ledPins[1], LOW);
  }

}


float getVoltage(int pin){
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}




