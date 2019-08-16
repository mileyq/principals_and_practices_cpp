
// MODIFIED BY PAT M. ADDED (SIMPLE) TEST CASES
#include "std_lib_facilities.h"
// This is example code from Chapter 9.4.1 "Struct and functions" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date (too simple?):
struct Date {
    int y; // year
    int m; // month in year
    int d; // day of month
};

//------------------------------------------------------------------------------

// helper functions:

void init_day(Date& dd, int y, int m, int d)
{
    if (1 <= m && m <= 12&& 1<=d && d<=31){
        dd.m = m;
        dd.d = d;
        dd.y = y;
    }
    else throw runtime_error("invalid date");
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
}

//------------------------------------------------------------------------------

void add_day(Date& dd, int n)
{
    n = dd.d + n;
    while(n>31){
        n=n-31;
        if(dd.m==12){
            dd.m=1;
            dd.y ++;
        }
        else{
            dd.m += 1;
        }
    }
    dd.d = n;
    // increase dd by n days
}

void print_day(const Date& d){
    cout << d.m << " " << d.d << " " << d.y << endl;
}

//------------------------------------------------------------------------------

void f()
{
    Date today;
    init_day(today, 12, 24, 2005); // oops! (no day 2005 in year 12)
    add_day(today,1);
}

// MAIN FUNCTION BY PAT M

int main()
try {
    Date today; // a Date variable (a named object)

    today.y = 1978;
    today.m = 7;
    today.d = 25;

    print_day(today);

    Date y;

    init_day(y, 2000, 11, 1);
    print_day(y);
    add_day(y, 60);
    print_day(y);
    add_day(y, 2);
    print_day(y);
    add_day(y, 29);
    print_day(y);
    add_day(y, 2);
    print_day(y);
    init_day(y, 2000, 14, 341);
    print_day(y);
    
    return 0;


}
catch(exception& x){
    cerr << x.what() << endl ;
}

//------------------------------------------------------------------------------
