// calculator example they are programming in chapter 6. I will give my own attempt without simply copying theirs.
// Unfinished. Moved on in book. Will return.

/* psuedo code for my calculator:
1. read input from command line
2. calculate ansewr from input
3. print output to terminal
 */

#include "std_lib_facilities.h"

enum Kind{number, multiplication, division, addition, subtraction, lbracket, rbracket};

class Token{
public:
    Kind kind;
    double value;
};

Token parse_string_calc(string s){
    /* check if string is either a operand, a number, a bracket , etc then return a token*/ 
    switch(s.front()){
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        double var = strtod(s);
        break;
    }
}

auto str_to_number(string s){
    /* return a number (either double or int) if it is in correct format */
    /* not sure if can use auto return type */
    bool neg_flag = false; 
    int point_pos = -1; // indicate the position of the decimal point, if negative error
    int loop_pos = 0; // initialize variable (not the best way to do it I am sure.)
    bool not_number_flag = false; //flag if a non number is present character 
    double d_return;
    int i_return;
    stringstream ss; 
    for(char c: s){
        switch(c){
        case '-':
        if(neg_flag == true) throw runtime_error("str_to_number function : not a valid number: two '-' signs found");
        if(loop_pos != 0) throw runtime_error("str_to_number fn : the negative isn't the first char");
        neg_flag = true;
        break;

        case '.':
        if (point_pos >=0)throw runtime_error("str_to_number fn: there has already been a decimal position");
        point_pos = loop_pos;
        break;

        default:
        if(!isdigit(c)) throw runtime_error("str_to_number fn: a non digit is given, not - or ." ); 
        break;
    }
    loop_pos++;
    }
    ss << s;
    if(point_pos>= 0) {
        ss >> d_return;
        return d_return;
    }
    // else{
    //     ss >> i_return;
    //     return i_return;
    // }


    
}

vector<Token> read_calc_input(){
    // variable declaration
    Token thisToken;
    vector<Token> vect_t;
    vector<string> str;
    int i;
    double d;
    char c;
    string s;
    cout << "calculate input (put a space between different types of information): ";
    while(cin){ // collect one word at a time ignoring whitespace until a ctrl-z signal is sent
        cin >> s; // put everything from cin into s

        



        str.push_back(s);
        // if(stod(s)){ // this does not return t/f
        //     thisToken.kind = number;
        //     cin >> thisToken.value; // we only take double atm
        //     vect_t.push_back(thisToken);
        //     thisToken = {};
        // }
        // else if(stoi(s)){
        //     thisToken.kind = number;
        //     cin >> thisToken.value;
        //     vect_t.push_back(thisToken);
        //     thisToken = {};
        // }
        // else if(s.size()==1){
        //     s = c;
        //     switch(c){
        //         case '*':
        //             thisToken.kind = multiplication;
        //             vect_t.push_back(thisToken);
        //             break;
        //         case '\\': 
        //         case '/':
        //             thisToken.kind = division;
        //             vect_t.push_back(thisToken);
        //             break;
        //         case '+':
        //             thisToken.kind = addition;
        //             vect_t.push_back(thisToken);
        //             break;
        //         case '-':
        //             thisToken.kind = subtraction;
        //             vect_t.push_back(thisToken);
        //             break;
        //         case '(':
        //             thisToken.kind = lbracket;
        //             vect_t.push_back(thisToken);
        //             break;
        //         case ')':
        //             thisToken.kind = rbracket;
        //             vect_t.push_back(thisToken);
        //             break;
        //     }
        // }
    }

for(string t: str){
    cout << t << " , " << endl;
}
    return vect_t;
}


int main()
try
{
    cout << "calculator input: ";
    read_calc_input();
    keep_window_open();
    /* code */
    return 0;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception." << '\n';
    return 2;
}
