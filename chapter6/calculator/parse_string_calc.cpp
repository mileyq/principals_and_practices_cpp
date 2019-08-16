#include "std_lib_facilities.h"
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


    
};

int main( ){
    try
    {
            // cout << str_to_number("-0.000000.343") << endl;
    string my_dub;
    
    cout << str_to_number("-000000034.3") << endl;

while(1){
    cout << "input a str_to_number:  ";

    cin >> my_dub;

    cout << str_to_number(my_dub);
}
    keep_window_open();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}