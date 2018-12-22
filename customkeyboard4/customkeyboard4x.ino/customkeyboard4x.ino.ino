#include "Keyboard.h"

const int keyNum = 2;

const int inputPin[keyNum] = { 3, 4 };
const char keyMap[keyNum]  = { "osewaninatteorimasu.", "otukaresamadesu." };

bool currentState[keyNum];
bool beforeState[keyNum];

int i;

void setup() {
  for( i = 0; i < keyNum; i++){
    pinMode(inputPin[i],INPUT);
    currentState[i] = LOW;
    beforeState[i] = LOW;
  }

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for( i = 0; i < keyNum; i++){
    currentState[i] = digitalRead(inputPin[i]);

    if ( currentState[i] != beforeState[i] ){
      Serial.print("key");
      Serial.print(i);
      if ( currentState[i] == HIGH){
        Serial.println(" Push!");
        Keyboard.write( keyMap[i] );
      } else {
        Serial.println(" Release!");
        Keyboard.release( keyMap[i] );
      }
    beforeState[i] = currentState[i];
    }
  }
}

