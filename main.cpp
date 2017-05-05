#include <iostream>
#include <string>
#include <locale>
#include <sstream>

using namespace std;

class InputStopChecker {
 public:
  virtual bool checkStopCondition() {return true;};
  virtual void addCharacter(char & c) {};
};

class InputHandler {
 public:
  virtual void addCharacter(char & c) {};
  virtual string getOutput() { return "";};
};

class InputStopChecker22: public InputStopChecker {
 private:
  locale loc;
  int numeral_sum = 0;
 public:
  bool checkStopCondition() {
   if (numeral_sum > 100) {
    return true;
   } else {
    return false;
   }
  }
  void addCharacter(char & character) {
   if (isdigit(character, loc)) {
    int digit = atoi(&character);
    numeral_sum = numeral_sum + digit;
   }
  }
};

class InputHandler23: public InputHandler {
 private:
  int simbol_counter = 0;
  string output = "";
 public:
  void addCharacter(char & c) {
   if (simbol_counter < 100) {
    output += c;
    if (!isspace(c)) {
     simbol_counter++;
    }
   }
  }
  string getOutput() { return output; }
};

void handleInput(istream & istream, ostream & ostream, InputStopChecker* checker, InputHandler* handler) {
 char c;
 while (!checker->checkStopCondition()) {
  istream >> c;
  checker->addCharacter(c);
  handler->addCharacter(c);
 }
 ostream << handler->getOutput();
}

int main() {

 InputStopChecker22 checker1;
 InputHandler23 handler1;

 InputStopChecker * checker = &checker1;
 InputHandler * handler = &handler1;

 handleInput(cin, cout, checker, handler);

 return 0;
}
