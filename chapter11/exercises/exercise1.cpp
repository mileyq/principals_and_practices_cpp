#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    ifstream myfile{"samplefile.txt"}; //put this file into directory and add random letters and see them converted into all small letters
    
    if(!myfile) cout << "file didn't open"<< endl;
    ofstream myprocessedfile("processed_samplefile.txt");
    if(!myprocessedfile)cout << "output file didn't open" << endl;
    for(char i; myfile.get(i);){ // get doesn't skip whitespace so maintains the file
        myprocessedfile << static_cast<char> (tolower(i)); 
    }
    char get_c;
    cin >> get_c;
}