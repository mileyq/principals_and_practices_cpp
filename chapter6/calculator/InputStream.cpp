#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Token.h"
#include "InputStream.h"

using namespace std;



InputStream::InputStream(){
  token_stream.clear();
  buffer = Token(); 
  buffer_empty = true;
};

void InputStream::print_all(){
  for(Token t : token_stream){
    cout << "> " << t.get_type() << "  " << t.get_value() << endl;
  }
};

void InputStream::set_stream(){
  // initialize
  token_stream.clear();
  buffer = Token(); 
  buffer_empty = true;
};

void InputStream::insert(std::string s){
  stringstream ss;
  string s1;
  double d;
  Token tok;
  ss << s;
  while(ss){
//    s1.clear(); // temperary value, make sure clear everytime.
    ss >> s1; // put front of ss into s1 to interpret what it says
    if (isalpha(s1.front())){

      token_stream.push_back(Token("Keyword", s1));
      s1.clear();
    }
    else{
    switch(s1.front()){
      case '0': case '1': case '2': case '3': case'4': case '5': case '6': case '7': case '8': case '9':
      ss >> s1;
      if(token_stream.empty()){
        token_stream.push_back(Token("double", s1));
        ss << s1;
        ss >> d;
      }
      else{
        InputStream::token_stream.push_back(Token("double", s1));
        ss << s1;
        ss >> d;
      }
      break;
      case '(': case ')': case '+': case '-' : case '/' : case '*':
      tok.set_token(string(1, s1.front()), string(1, s1.front()));
      InputStream::token_stream.push_back(tok);
      ss << s1;
      ss >> s1;
      break;
      default: cout << "error" << endl;
    }
  }
}

  // token_stream.push_back(s);
};

Token InputStream::get(){
  if(buffer_empty==true){
    buffer = token_stream.back();
    token_stream.pop_back();
    buffer_empty = false;
    return buffer;
  }
  else if(!buffer_empty){
    InputStream::buffer_empty = true;
    return InputStream::buffer;
  }
  else{
    throw runtime_error("inputstream::get() neither empty nor full");
  }
  return InputStream::buffer; // shoudlnt' happen
};

