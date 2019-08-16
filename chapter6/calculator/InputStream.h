#ifndef INPUTSTREAM_H
#define INPUTSTREAM_H
#include <string>
#include <vector>
#include "Token.h"
class InputStream {
  // start with getting input from cin (passes over whitespace)
  // interpret and validate input using grammar rules
  // save input, and handle input properly (vector token_stream)
  public:
  InputStream ();
  Token get();
  void put_back(Token t);
  void insert(std::string s); // push words into token_stream one at a time, from cin
  void print_all();
  void set_stream();
  enum :int{type, number, str, keyword, operation, mult, div, add, sub, r_brkt, l_brkt,  };

  private:
  std::vector<Token> token_stream; 
  Token buffer;
  bool buffer_empty;
  
};

#endif