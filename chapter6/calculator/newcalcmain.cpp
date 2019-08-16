#include "Token.h"
#include "InputStream.h"
#include <iostream>
#include <string>

int main(){
    Token t;
    InputStream i;

    i.insert("222.22912222");
    i.insert("(");
    i.insert("+");
    i.insert("blahhhhh");
    i.insert("rarrr barggghhhhh fachaaa aiya");
    i.print_all();
    int x;
    cin >> x;
    return 0;
}