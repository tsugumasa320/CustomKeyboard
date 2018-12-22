#include "Keyboard.h"

const int inputPin1 = 3;
const int inputPin2 = 4;
const int inputPin3 = 5;
const int inputPin4 = 6;

bool currentState1 = LOW;
bool beforeState1 = LOW;
bool currentState2 = LOW;
bool beforeState2 = LOW;
bool currentState3 = LOW;
bool beforeState3 = LOW;
bool currentState4 = LOW;
bool beforeState4 = LOW;


void setup() {
  pinMode(inputPin1,INPUT);
  pinMode(inputPin2,INPUT);
  pinMode(inputPin3,INPUT);
  pinMode(inputPin4,INPUT);


  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  currentState1 = digitalRead(inputPin1);
  currentState2 = digitalRead(inputPin2);
  currentState3 = digitalRead(inputPin3);
  currentState4 = digitalRead(inputPin4);


  if ( currentState1 != beforeState1 ){
    if ( currentState1 == HIGH){
      Serial.println("1 Push!");
      Keyboard.print("osewaninatteorimasu. ");
    } else {
      Serial.println("1 Release!");
      Keyboard.releaseAll();
    }
  beforeState1 = currentState1;
  }

  if ( currentState2 != beforeState2 ){
    if ( currentState2 == HIGH){
      Serial.println("2 Push!");
      Keyboard.print("otukaresamadesu. ");
} else {
      Serial.println("2 Release!");
      Keyboard.releaseAll();
    }
  beforeState2 = currentState2;
  }

   if ( currentState3 != beforeState3 ){
    if ( currentState3 == HIGH){
      Serial.println("3 Push!");
      Keyboard.print("yorosikuonegaiitasimasu. ");
} else {
      Serial.println("3 Release!");
      Keyboard.releaseAll();
    }
  beforeState3 = currentState3;
  }

   if ( currentState4 != beforeState4 ){
    if ( currentState4 == HIGH){
      Serial.println("4 Push!");
  //    Keyboard.print("otesuudesuga, ");
} else {
      Serial.println("4 Release!");
      Keyboard.releaseAll();
    }
  beforeState4 = currentState4;
  }

}

