// Modified by Pat. M
#include "std_lib_facilities.h"
// This is example code from Chapter 9.4.2 "Member functions and constructors" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

// simple Date:
// guarantee initialization with constructor
// provide some notational convenience
struct Date {
    int y, m, d;                        // year, month, day 
    Date(int y, int m, int d);          // check for valid date and initialize
    void add_day(int n);                // increase the Date by n days
    void print_day();
    void set_day(int y, int m, int d);
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {
    set_day(y, m, d);
}

void Date::set_day(int y, int m, int d){
if(1<=m && m<=12 && 1<=d && d<=31){
        Date::y = y;
        Date::m = m;
        Date::d = d;
    }
    else throw runtime_error("invalid init date");
}

void Date::add_day(int n){
    n = Date::d + n;
    while(n>31){
        n=n-31;
        if(Date::m==12){
            Date::m=1;
            Date::y++;
        }
        else{
            Date::m += 1;
        }
    }
    Date::d = n;
}

void Date::print_day(){
    cout << Date::m << " " << Date::d << " " << Date::y << endl;
}

//------------------------------------------------------------------------------

int main()
try{
    //Date my_birthday;                 // error: my_birthday not initialized
    Date today(2007, 12, 24);             // oops! run-time error 
    Date last(2000, 12, 31);            // ok (colloquial style)
    Date christmas = Date(1976,12,24);  // also ok (verbose style)

    //We can now try to use our newly defined variables:
    today.print_day();
    last.print_day();
    christmas.print_day();

    Date y (2000, 11, 1);
    
    y.add_day(60);
    y.print_day();
    y.add_day(2);
    y.print_day();
    y.add_day(29);
    y.print_day();
    y.add_day(2);
    y.print_day();

    last.add_day(1);
    
    last.set_day(2011, 23, 244);
    last.print_day();
    return 0;
}
catch (exception& e){
    cerr << e.what() << endl;
}

//------------------------------------------------------------------------------
