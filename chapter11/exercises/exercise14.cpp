// similar to exercise5 that I got some code from
// making a class for the question although not necessary
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class CharCategory{
public:
CharCategory(string fn):filename{fn}, input_file{fn}{
    if(!input_file){
        cout << filename << " didn't open corretly, charcategory initializer";
    }
        process();
        print();
}
void process(){
    char cc;
    input_file.get(cc);
    if(data.empty())data.push_back(CharCateTuple{cc, 1});
    for(char c; input_file.get(c);){
        // this should use a dictionary data structure (which I don't use)
        short char_exist=0;
        for(CharCateTuple& i : data){
            if (i.c == c){
                i.quantity++;
                char_exist++;
                goto exit_loop;
            }
        }
        exit_loop:
        if(char_exist==0){
            data.push_back(CharCateTuple{c,1});
        }
    }
}
 void print(){
    if (data.empty()) cout << "no data, print member function" << endl;
    for(const CharCateTuple& i : data){
        cout << i.c << "x" << i.quantity << endl; 
    }
 }
enum class Categories{isspace, isalpha, isdigit, isxdigit, isupper, islower, isalnum, iscntrl, ispunct, isprint, isgraph};
struct CharCateTuple{
    CharCateTuple(char cx, short quant):c{cx}, quantity{quant}{

    }
    const char c;
    short quantity;
    int categories[11];
};

vector<CharCateTuple> data;
private:
ifstream input_file;
string filename;

};

int main(){
    // ofstream ofs{"ex14out.txt"};
    const string ifs_loc {"exercise14file.txt"};
    // ifstream ifs{ifs_loc};
    // if (!ifs) cout << ifs_loc << " didn't open correctly" << endl;

    CharCategory{ifs_loc};
}