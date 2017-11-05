#ifndef _ExpressionClass_h
#define _ExpressionClass_h

#include "Arduino.h"

class ExpressionClass {
  public:
    ExpressionClass();
    int expression(const char *s, double *v);
    int expression(String line, double *v);
  private:
    int get(void);
    double expr(const char *s);
    void debug(String method,String message);
};

#endif
