#include "std_lib_facilities.h"

void print(vector<int>& v, string label){
    for(int i : v){
        cout << label << " " << i << endl;
    }
}
void print(vector<string>& v, string label){
    for(string i : v){
        cout << label << " " << i << endl;
    }
}

int fibonacci(int, int);
void fibonacci(int x, int y, vector<int>& v, int n){
    v.resize(n+2);
    v[0]=x;
    v[1]=y;
    for(int i=0; i<n; i++){
        v[i+2]=fibonacci(v[i], v[i+1]);
    }
}

int fibonacci(int x, int y){
    return x + y;
}

// int main(){
//     vector<int> v;
//     fibonacci(1, 3, v, 14);
//     print(v, ":");
// }