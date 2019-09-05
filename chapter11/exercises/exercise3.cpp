// remove all vowels from a file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isvowel(char c){
    switch (c){
        case 'a': 
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U': return true;
        break;
        default: return false;
    }
}

void fvowel_remover(ifstream &ifs_i, ofstream &ofs_i){
    if(!ifs_i)throw runtime_error("file not opened correctly");
    if (!ofs_i)throw runtime_error("output file stream didn't open");
        for(string s; getline(ifs_i, s);){
            for(char c : s){
                if (!isvowel(c))ofs_i.put(c); 
            }
    }  
}

int main(){
    ifstream ifs{"exercise3test.txt"};
    if(!ifs)throw runtime_error("exercise3test.txt didn't open correctly");
    ofstream ofs{"exercise3testoutput.txt"};
    if(!ifs)throw runtime_error("exercise3output.txt didn't open correctly");
    fvowel_remover(ifs, ofs);
}