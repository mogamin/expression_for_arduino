// coding: utf-8

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    String line = Serial.readStringUntil(';');
    exec_expression(line);
  }
}


void exec_expression(String line)
{
  String method = "exec_expression";
  info(method, "input string=[" + line + "]");

  int calc_result = 0;
  const char* s = line.c_str();
  int result = expression(s, &calc_result);
  if (result == true) {
    info(method, "calc_result=[" + String(calc_result) + "]");
  } else {
    error(method, "error_result=[" + String(result) + "]");
  }
}

void info(String method,String message){
    Serial.println("INFO  | " + method + ":" + message);
}
void error(String method,String message){
    Serial.println("ERROR | " + method + ":" + message);
}
void debug(String method,String message){
    Serial.println("DEBUG | " + method + ":" + message);
}


// see: http://dixq.net/forum/viewtopic.php?f=3&t=10771
int c;  char *p, o[] = "+-*/^ ";

int expression(const char *s, int *v)
{
  p = (char *)s;
  *v = expr(o);
  return c == 0;
}

int get(void) {
  String method = "  get";

  do {
    c = *p++ & 0xff;
  } while (isspace(c));
  debug(method, "retrun c=[" + String(char(c)) + "]");
  return c;
}

double expr(const char *s)
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
  else if (c == '(') {
    debug(method, "(");
    v = expr(o), c == ')' ? get() : (c = 1);
  }
  else if (c == '+') {
    debug(method, "+");
    v = expr(s);
  }
  else if (c == '-') {
    debug(method, "-");
    v = -expr(s);
  }
  else {
    debug(method, "else");
    v = c = 1;
  }
  debug(method, "return v=[" + String(v) + "]");
  return v;
}


