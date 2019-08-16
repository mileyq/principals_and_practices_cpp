
//Modified by Pat. M

// This is example code from Chapter 9.4.3 "Keep details private" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

// simple Date (control access):
class Date {
    int y, m, d;                      // year, month, day
public:
    Date(int y, int m, int d);        // check for valid date and initialize
    void add_day(int n);              // increase the Date by n days
    int month() { return m; }
    int day()   { return d; }
    int year()  { return y; }
    void set_day(int y, int m, int d);
    void print_day();
};

//------------------------------------------------------------------------------

Date::Date(int y, int m, int d) : y(y), m(m), d(d) {set_day(y, m, d);}

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

// Some test code by Pat. M
int main()
{
    Date birthday(1970, 12, 30);      // ok
    //birthday.m = 14;                // error: Date::m is private
    cout << birthday.month() << endl; // we  provided a way to read m
    Date y (2000, 11, 1); 
    y.add_day(60);
    y.print_day();
    y.add_day(2);
    y.print_day();
    y.add_day(29);
    y.print_day();
    y.add_day(2);
    y.print_day();
    y.set_day(2332, 23, 225);
    y.print_day();
}

//------------------------------------------------------------------------------
