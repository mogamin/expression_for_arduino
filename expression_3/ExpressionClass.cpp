#include "ExpressionClass.h"


int c;  char *p, o[] = "+-*/^ ";

ExpressionClass::ExpressionClass() {
}

int ExpressionClass::expression(String line, double *v)
{
  const char* s = line.c_str();
  return expression(s, v);
}

int ExpressionClass::expression(const char *s, double *v)
{
  p = (char *)s;
  *v = expr(o);
  return c == 0;
}

int ExpressionClass::get(void) {
  String method = "  get";
  do {
    c = *p++ & 0xff;
  } while (isspace(c));
  debug(method, "retrun c=[" + String(char(c)) + "]");
  return c;
}

double ExpressionClass::expr(const char *s)
{
  String method = " expr";
  debug(method, "const char *s=[" + String({s}) + "]");

  double v;
  if (*s) {
    debug(method, "c=[" + String(char(c)) + "],s=[" + String({s}) + "],s[0]=[" + String({s[0]}) + "],s[1]=[" + String({s[1]}) + "]");
    for (v = expr(s + 2); c == s[0] || c == s[1]; ) {
      if (c == '+') {
        debug(method, "c==+, (s + 2)="+String({s + 2}));
        v += expr(s + 2);
      }
      else if (c == '-') {
        debug(method, "c==-, (s + 2)="+String({s + 2}));
        v -= expr(s + 2);
      }
      else if (c == '*') {
        debug(method, "c==*, (s + 2)="+String({s + 2}));
        v *= expr(s + 2);
      }
      else if (c == '/') {
        debug(method, "c==/, (s + 2)="+String({s + 2}));
        v /= expr(s + 2);
      }
      else {
        debug(method, "c==else, (s)="+String({s}));
        v = pow(v, expr(s));
      }
    }
  }
  else if (get() == '.' || isdigit(c)) {
    debug(method, "p=[" + String({p-1}) + "]");
    v = strtod(p - 1, &p);
    get();
  }
  else {
    debug(method, "else");
    v = c = 1;
  }
  debug(method, "return v=[" + String(v) + "]");
  return v;
}

void ExpressionClass::debug(String method,String message){
    //Serial.println("DEBUG | " + method + ":" + message);
}

