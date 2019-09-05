// binary, hexidecimal, octal, decimal converter
// using iostream facilities
// this is partly finished, I changed the plan partway to something easier, I might not return to fix this
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

enum class ntype{
INT, OCT, DEC, BIN
};

struct n_type{
    // has a number and  a type
    int n;
    ntype nt;
};

ntype interpret_word(string s){
    // read word and find out if
}

int convert_word(string s, ntype ntype){
    stringstream i;
    i.unsetf(ios::dec);
    i.unsetf(ios::hex);
    i.unsetf(ios::oct);
    int x;
    i << s;
    i >> x;
    return x;
    switch (ntype){
        case ntype::INT:
    
        break;
        case ntype::DEC:
        case ntype::BIN:
        case ntype::OCT:
        break;
    }
}

int main(){
    cout << convert_word("011110", ntype::DEC);
    int x;
    cin >> x;
}