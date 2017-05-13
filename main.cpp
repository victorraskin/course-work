#include <iostream>
#include <string>
#include <locale>
#include <sstream>
#include <cstdlib>

using namespace std;

class InputStopChecker {
 public:
  virtual bool checkStopCondition() = 0;
  virtual void addCharacter(char & c) = 0;
};

class InputHandler {
 public:
  virtual void addCharacter(char & c) = 0;
  virtual string getOutput() = 0;
};

class InputStopChecker22: public InputStopChecker {
 private:
  locale loc;
  int numeral_sum;
 public:
  InputStopChecker22() {
   numeral_sum = 0;
  }
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
  int simbol_counter;
  string output;
 public:
  InputHandler23() {
   simbol_counter = 0;
   output = "";
  }
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
