#ifndef _ExpressionClass_h
#define _ExpressionClass_h

#include "Arduino.h"

class ExpressionClass {
  public:
    ExpressionClass();
    exec_expression(String line);
  private:
    int expression(const char *s, int *v);
    int get(void);
    double expr(const char *s);
    void info(String method,String message);
    void error(String method,String message);
    void debug(String method,String message);
};

#endif
