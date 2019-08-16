#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Token{
  // we use only string to represent tokens and we then convert everything to datatypes later
  // so we use stringstream
  public:
  
  Token();
  Token(string t, string v);
  Token(char t, char v);
  string get_type();
  string get_value();
  void set_token(string type, string value);
  bool inline is_empty();

  private:
  string type {}; // string representing type of token
  string value {}; // string representing value
  
};

#endif