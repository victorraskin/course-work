#include <iostream>
#include <string>

using namespace std;

int main() {
 cout << "Input data" << endl;
 char c;
 string output = "";
 int numeral_sum = 0;
 int simbol_counter = 0;
 while (numeral_sum <= 100) {
  cin >> c;
  if ('0' <= c && c <= '9') {
   int digit = c - '0';
   numeral_sum += digit;
  }
  if (c != ' ' && c != '\n' && c != '\t') {
   simbol_counter++;
  }
  if (simbol_counter <= 100) {
   output += c;
  }
 }
 cout << "Sum of digits in your data more than 100. Input stoped." << endl;
 cout << "The handled output is:" << endl;
 cout << output << endl;
 cout << "The handled output printed." << endl;
 return 0;
}
