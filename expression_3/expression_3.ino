// coding: utf-8

#include "ExpressionClass.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    String line = Serial.readStringUntil(';');
    Serial.println("input string=[" + line + "]");

    double calc_result = 0.00;
    int result =  ExpressionClass().expression(line, &calc_result);
    if (result == true) {
      Serial.println("calc_result=[" + String(calc_result, 2) + "]");
    } else {
      Serial.println("error_result=[" + String(result) + "]");
    }
  }

}

