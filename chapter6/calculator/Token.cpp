#include <iostream>
#include <vector>
#include <string>
#include "Token.h"

using namespace std;

Token::Token(){
    set_token("", "");
  };

Token::Token(string t, string v){
    set_token(t, v);
  };

Token::Token(char t, char v){
  set_token(string(1, t), string(1, v));
}

bool inline Token::is_empty(){
  if(type=="" && value==""){
    return true;
  }
  else return false;
}
void Token::set_token(string t, string v){
    Token::value = v;
    Token::type = t;
}
  string Token::get_type(){
      return Token::type;
  }
  
  string Token::get_value(){
      return Token::value;
  }
