// reads a string for each char outputs a table that shows the categories the char belongs

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

// because the character classification functions used below do redundant actions the library code will search for the character and get a number value for it
// then each of the hexidecimal number places will represent a different category the character belongs to
// for example 0x80 = hexidecimal number + 0x1 UPPER CASE + ect some of them are mutually exclusive then you can just use a bitwise filter on the number to get the answer and it returns non zero if true
/* 
#define _UPPER 0x1
#define _LOWER 0x2
#define _DIGIT 0x4
#define _SPACE 0x8

#define _PUNCT 0x10
#define _CONTROL 0x20
#define _BLANK 0x40
#define _HEX 0x80

#define _LEADBYTE 0x8000
#define _ALPHA (0x0100|_UPPER|_LOWER)
*/
void char_classification_table(string str){
    int len = str.length();
    cout << "char | isspace() | isalpha() | isdigit() | isxdigit() | isupper() | islower() | isalnum() | iscntrl() | ispunct() | isprint() | isgraph() |" << endl;
    
    for(char c : str){
        cout << setw(4) << c << " | " << setw(9) << isspace(c) << " | " << setw(9) << isalpha(c) << " | " << setw(9) << isdigit(c) << " | " << setw(10) << isxdigit(c) << " | " << setw(9) << isupper(c) << " | " << setw(9) << islower(c) << " | " << setw(9) << isalnum(c) << " | " << setw(9) << iscntrl(c) << " | " << setw(9) << ispunct(c) << " | " << setw(9) << isprint(c) << " | " << setw(9) << isgraph(c) << " | " << endl; 

    }
}

int main(){
    string s {"asdf93W@)axiUB&"}; // string to test
    char_classification_table(s);
}