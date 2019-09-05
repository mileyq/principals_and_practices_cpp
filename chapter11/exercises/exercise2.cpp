#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// the function appears to ignore capital letters, which is probably a feature of string:find() function, 
// could definitely be improved but I shall move on!

void fword_finder(ifstream &ifs_i, string wrd){
    if(!ifs_i)throw runtime_error("file not opened correctly");
    int line_n{1}; //line counter
    for(string s; getline(ifs_i, s);){
        int n_word=0;
        int w_pos = s.find(wrd, 0);
        if(w_pos!= s.npos){ 
            n_word=1;
            for(int i=w_pos+1, j=0; i!=s.npos+1; ){ // this is a bit of a hack solution so could have been improved but its time for me to move on,
                j=s.find(wrd, i);
                i=j+1;
                n_word++;    
            }
        }
        if (n_word>0) cout << "line " << line_n << ", " << n_word << " x " << wrd << endl;
        n_word=0; // reset to zero for next iteraton of loop
        line_n++; // increment
    }
}

int main(){
    ifstream ifs{"exercise2test.txt"};
    if(!ifs)throw runtime_error("exercise2test.txt didn't open correctly");
    fword_finder(ifs, "pat");
}