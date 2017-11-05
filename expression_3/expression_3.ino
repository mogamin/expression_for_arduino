// coding: utf-8

#include "ExpressionClass.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    String line = Serial.readStringUntil(';');
    ExpressionClass ec = ExpressionClass();
    ec.exec_expression(line);
  }
}


