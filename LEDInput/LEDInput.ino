// Timothy Kheang and Saarthak Ahlawat
// Created for Hackpoly 2017
#include <avr/io.h>
#include <avr/wdt.h>

int previousPosition;
int currentPosition;
int serialInput;

void setup() 
{
  Serial.begin(9600); // Listen for input
  for(int i = 2; i < 13; i++)
    pinMode(i, OUTPUT);
}

void loop() 
{
  if(Serial.available())
  {
    serialInput = Serial.read();
    if(serialInput < 13 && serialInput != currentPosition)  // default mode
    {      
      previousPosition = currentPosition;
      currentPosition = serialInput;
      digitalWrite(currentPosition, HIGH);
      delay(50);
      digitalWrite(previousPosition, LOW);
    }
    else if(serialInput == 'A' && serialInput != currentPosition) // mode 1
    {
      for(int i = 2; i < 13; i++)
      {
        digitalWrite(i, HIGH);
        delay(50);
        digitalWrite(i, LOW);
      }
      wdt_enable(WDTO_15MS);
      while(1)
      {
      }
    }
    else if(serialInput == 'B' && serialInput != currentPosition) // mode 2
    {
      for(int i = 12; i >= 0; i--)
      {
        digitalWrite(i, HIGH);
        delay(50);
        digitalWrite(i, LOW);
      }
      wdt_enable(WDTO_15MS);
      while(1)
      {
      }
    }
    else if(serialInput == 'C' && serialInput != currentPosition) // mode 3
    {
      digitalWrite(2, HIGH); digitalWrite(12, HIGH);
      delay(50);
      digitalWrite(2, LOW); digitalWrite(12, LOW);
      digitalWrite(3, HIGH); digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(3, LOW); digitalWrite(11, LOW);
      digitalWrite(4, HIGH); digitalWrite(10, HIGH);
      delay(50);
      digitalWrite(4, LOW); digitalWrite(10, LOW);
      digitalWrite(5, HIGH); digitalWrite(9, HIGH);
      delay(50);
      digitalWrite(5, LOW); digitalWrite(9, LOW);
      digitalWrite(6, HIGH); digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(6, LOW); digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
      delay(50);
      digitalWrite(7, LOW);
      wdt_enable(WDTO_15MS);
      while(1)
      {
      }
    }
    else if(serialInput == 'D' && serialInput != currentPosition) // mode 4
    {
      digitalWrite(7, HIGH);
      delay(50);
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH); digitalWrite(8, HIGH);
      delay(50);
      digitalWrite(6, LOW); digitalWrite(8, LOW);
      digitalWrite(5, HIGH); digitalWrite(9, HIGH);
      delay(50);
      digitalWrite(5, LOW); digitalWrite(9, LOW);
      digitalWrite(4, HIGH); digitalWrite(10, HIGH);
      delay(50);
      digitalWrite(4, LOW); digitalWrite(10, LOW);
      digitalWrite(3, HIGH); digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(3, LOW); digitalWrite(11, LOW);
      digitalWrite(2, HIGH); digitalWrite(12, HIGH);
      delay(50);
      digitalWrite(2, LOW); digitalWrite(12, LOW);    
      wdt_enable(WDTO_15MS);
      while(1)
      {
      }
    }
    else
    {
      for(int i = 2; i < 13; i++)
        digitalWrite(i, LOW);
    }
    delay(10);
  }
}


