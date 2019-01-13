#include "Keyboard.h"

const int rowNum = 2;
const int colNum = 2;

const int rowPin[rowNum] = { 4, 5 };
const int colPin[colNum] = { 6, 7 };
String keyMap[rowNum][colNum]  = {
  { "yorosikuonegaisimasu. ", "osewaninatteorimasu. " },
  { "otukaresamadesu. " , "otesuudesuga, " }
};

bool currentState[rowNum][colNum];
bool beforeState[rowNum][colNum];

int i,j;

void setup() {

TIMSK0= 0;

  for( i = 0; i < rowNum; i++){
    pinMode(rowPin[i],OUTPUT);
  }

  for( i = 0; i < colNum; i++){
    pinMode(colPin[i],INPUT_PULLUP);
  }

  for( i = 0; i < rowNum; i++){
    for( j = 0; j < colNum; j++){
      currentState[i][j] = HIGH;
      beforeState[i][j] = HIGH;
    }
    digitalWrite(rowPin[i],HIGH);
  }

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for( i = 0; i < rowNum; i++){
    digitalWrite( rowPin[i], LOW );

    for( j = 0; j < colNum; j++){
      currentState[i][j] = digitalRead(colPin[j]);

      if ( currentState[i][j] != beforeState[i][j] ){

        Serial.print("key(");
        Serial.print(i);
        Serial.print(",");
        Serial.print(j);
        Serial.print(")");

        if ( currentState[i][j] == LOW){
          Serial.println(" Push!");
          Keyboard.print( keyMap[i][j] );
        } else {
          Serial.println(" Release!");
          delay(10);
        }
      beforeState[i][j] = currentState[i][j];
      }
    }
    digitalWrite( rowPin[i], HIGH );
  }
}
