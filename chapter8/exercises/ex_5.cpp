#include "std_lib_facilities.h"
#include "pm_print.cpp"

vector<int> reverse(vector<int> v){
//reverse a copy of the input vector
    const int size = v.size();
    int n = size/2;
    for(int i=0; i<n; i++){
        int swap=v[i];
        v[i]=v[size-i-1];
        v[size-i-1]=swap;
    }
    return v;
}

vector<int>& reverse2(vector<int>& v){
//reverse the input vector
    const int size = v.size();
    int n = size/2;
    for(int i=0; i<n; i++){
        std::swap(v[i], v[size-1-i]);
    }
    return v;
}

vector<string>& reverse2(vector<string>& v){
    const int size = v.size();
    const int n = size/2;
    for(int i=0; i<n; i++){
        std::swap(v[i], v[size-1-i]);
    }
    return v;
}

struct name_ages{
    string name;
    int ages;
    // friend bool operator<(const name_ages& a, const name_ages& b){
    //     return (a < b);
    // }
};

bool compare_name_ages(name_ages a, name_ages b){
    return a.name<b.name? true : false;
}

void sort_print_names_ages(vector<string>& names, vector<int>& ages){
    vector<name_ages> na{};
    for(int i=0; i<names.size(); i++){
        na.push_back(name_ages{names[i], ages[i]});
    }
    sort(na.begin(), na.end(), compare_name_ages);
    for(auto i: na){
        cout << i.name << " " << i.ages << endl;
    }
}



int main(){
    // vector<int> vv{2, 4, 6, 3, 25, 77, 3, 1, 1, 0, 43, 6, 3, 7, 3, 34};
    // vector<int> cc = reverse(vv); 
    // print(cc, ">");
    // cout << endl << endl;
    // vector<int> dd{};
    // print(reverse2(dd), ">");
    // cout << endl;
    // print(vv, ":");
    // cout << endl;
    // reverse2(vv); // modifies original vector
    // cout << endl;
    // print(vv, ":");

    vector<string> v{"a", "bs", "ddd", "efea", "eeddqqx", "ddeaab", "v", "e"};
    
    vector<int> v_ages(v.size());

    for(int i=0; i<v.size();i++){
        v_ages[i]=i; // sample data
    }
    print(v_ages, "-");
    std::cout << endl;

    sort_print_names_ages(v, v_ages);
    return 0;

}