#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = 0;
float tempC;
void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, INPUT);
lcd.begin(16, 2);
}
void loop() {
tempC = get_temperature(sensorPin);
lcd.setCursor(0,0);
lcd.print("Temperatura: "); 
lcd.setCursor(0,1);
lcd.print (tempC, 1); lcd.print(" "); lcd.print("C");
delay(200);

 if (tempC <= 36){
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(13, LOW);
    noTone(9);
   
  }
 else(tempC > 37){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(13, HIGH);
    tone(9, 440, 250);
    delay(500);
    
  }
 
}
float get_temperature(int pin) {
float temperature = analogRead(pin);
float voltage = temperature * 5.0;
voltage = voltage / 1024.0;
return ((voltage - 0.5) * 100);
}
