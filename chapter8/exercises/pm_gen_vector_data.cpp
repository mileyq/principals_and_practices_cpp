#include "std_lib_facilities.h"
#include <random>
#include <time.h>
// some functions for generating test code


int random_int(){
    return rand();
}


string random_string(int len){
    string s{};
    s.resize(len);
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;
    return s;
}

string vector_of_strings(int n_calls){
    const int name_max_len = 18;
    string s{"vector<string> tmp {"};
    for(int i = 0; i < n_calls-1; i++){
        s += "\"";
        s += random_string(rand()%name_max_len);
        s += "\", ";
    }
    s += "\"";
    s += random_string(rand()%name_max_len);
    s += "\"};";
    return s;
}

int main(){
    // srand(time(NULL));
    string s = vector_of_strings(13);
    cout << s << endl;
}