#include "std_lib_facilities.h"

void print_until_s(const vector<string>& s, const string quit){
    // improved by adding const reference
    const int end_count = 2;
    int count {0};
    for(string i : s){
        if(i == quit){
            count++;
            if(count == end_count){
                cout.clear();
                return;
            }
        }
        cout << i << endl;
    }
}

int main(){
    vector<string> v {"rAQBc", "Wsa1xVPfvJcr", "end", "YwTiizs2t", "QF69AzBlax3", "F3",  "DN", "m3soLBPh71Y", "xuie", "oEiIgxIX4a", "dREbbSqWy6yh", "IDCdJOyapn", "rpMCARCr4", "end"};
    print_until_s(v, "end");
}