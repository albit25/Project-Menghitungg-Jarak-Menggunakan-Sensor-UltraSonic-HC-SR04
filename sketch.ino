

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  
#define echoPin 12 
#define trigPin 13

long duration, JARAK; 

const byte
RELAY1(2),
RELAY2(3),
RELAY3(4);

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);

  lcd.init(); 
  lcd.backlight();
  lcd.blink_on();
}

void loop() 
{
  delay(150);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
   
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  JARAK = duration/58.2;
   
   
  String disp = String(JARAK);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("JARAK:"); 
  lcd.setCursor(5, 1);
  lcd.print(disp);
  lcd.print(" cm");
  
  if (JARAK > 150)
  { 
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, LOW);
    digitalWrite(RELAY3, LOW);
  }

  if (JARAK <= 150 && JARAK >= 50)
  { 
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY3, LOW);
    digitalWrite(RELAY2, HIGH);
    delay(200);
    digitalWrite(RELAY2, LOW);
    delay(200);
    digitalWrite(RELAY2, HIGH);
    delay(200);
    digitalWrite(RELAY2, LOW);
    delay(200);
  }

  if (JARAK < 50)
  { 
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, LOW);
    digitalWrite(RELAY3, HIGH);
    delay(1000);
    digitalWrite(RELAY3, LOW);
    delay(0);
    digitalWrite(RELAY3, HIGH);
    delay(1000);
    digitalWrite(RELAY3, LOW);
    delay(0);
  }
}