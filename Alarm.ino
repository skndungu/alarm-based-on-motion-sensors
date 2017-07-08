#include <LiquidCrystal.h>
const int numRows =2;
const int numCols = 16;

LiquidCrystal lcd (1,2,4,8,9,10);
const int pirSensor1 = A0;
const int pirSensor2 = A1;
const int pirSensor3 = A2;
char first;
char second;

const int buzzerPin = 3;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int ledPin3 =7;
const int relayPin = 11;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

void setup ()
{
  Serial.begin(9600);
  lcd.begin(numCols,numRows);

  pinMode(buzzerPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop ()
{
  lcd.setCursor(0,1);
  firstPir();
  secondPir(second);
  do
  {
    sensorValue1 = analogRead(pirSensor1);
    sensorValue2 = analogRead(pirSensor2);
    sensorValue3 = analogRead(pirSensor3);
  }

   while (sensorValue1>100 && sensorValue2 >100 && sensorValue3 > 100);

}

char firstPir (first)
{
  do
  {
    sensorValue1 = (analogRead(pirSensor1) > 100) ? 1: 0 ;
  }

while(sensorValue1 == 1);
{
  lcd.clear ();
  lcd.setCursor(0,1);
  first =  lcd.print("attention the first pir !!");
  beep ();
}
}


char secondPir (second)
{
  do
  {
    sensorValue2 = (analogRead(pirSensor2) > 100 ) ? 1: 0 ;
  }

  while (sensorValue2 == 1);
  {
    lcd.clear();
    lcd.setCursor(0,1);
    second = lcd.print("attention the second pir !!");
    beep ();
  }

}


void beep ()
{
  digitalWrite(buzzerPin,HIGH);
  delay(1000);
  digitalWrite(buzzerPin,HIGH);
  delay(1000);
  digitalWrite(buzzerPin,LOW);
  delay(1000);

}

