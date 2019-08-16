#include "std_lib_facilities.h"
// some reusable functions that I will now prefix with pm_
// print prints all the data from vectors... need to make more general
// need to make print print all public data from a struct/class in a vector

void print(vector<int>& v, string label){
    for(int i : v){
        cout << label << " " << i << endl;
    }
}

void print(const vector<int>& v){
    for(int i : v){
        cout << " " << i << endl;
    }
}

void print(vector<string>& v, string label){
    for(string i : v){
        cout << label << " " << i << endl;
    }
}

void print(vector<string>& v){
    for(string i : v){
        cout << " " << i << endl;
    }
}
