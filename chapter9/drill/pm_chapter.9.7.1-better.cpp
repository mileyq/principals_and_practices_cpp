
// Modified by Pat. M
// This is example code from Chapter 9.7.1 "Argument types" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

// This "year" class is pointless: but it was already written. PM.
//------------------------------------------------------------------------------

class Year {        // year in [min:max) range
    static const int min = 1800;
    static const int max = 2200;
public:
    class Invalid { };
    Year(int x) : y(x) { if (x<min || max<x) throw Invalid(); }
    int year() { return y; }
private:
    int y;
};

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(Year yy, Month mm, int dd) : y(yy), m(mm), d(dd) // check for valid date and initialize
    {
        y={yy};
        // ...
    }
    void add_day(int n);
    void print_day();
    void set_day(int y, int m, int d);
    // ...
private:
    Year y;
    Month m;
    int d;   // day
};
void Date::set_day(int y, int m, int d){
if(1<=m && m<=12 && 1<=d && d<=31){
        Date::y = Year{y};
        Date::m = static_cast<Month>(m);
        if (1<=d&&d<=31){
            Date::d = d;
        }
        else throw runtime_error("bad day in set-day initialization");
    }
    else throw runtime_error("invalid init date");
}

void Date::print_day(){
    cout << Date::m << " " << Date::d << " " << Date::y.year() << endl;
}
void Date::add_day(int n){
    n = Date::d + n;
    while(n>31){
        n=n-31;
        if(Date::m==dec){
            Date::m=jan;
            y = {y.year()+1};
        }
        else{
            Date::m = Month(static_cast<Month>(m)+ 1);
        }
    }
    Date::d = n;
}
//------------------------------------------------------------------------------

int main()
try
{
    //Date dx1(Year(1998), 4, 3);         // error: 2nd argument not a Month
    //Date dx2(Year(1998), 4, Date::mar); // error: 2nd argument not a Month
    //Date dx2(4, Date::mar, Year(1998)); // error: 1st argument not a Year
    //Date dx2(Date::mar, 4, Year(1998)); // error: 2nd argument not a Month
    Date dx3(Year(1998), Date::mar, 30);  // ok
    dx3.print_day();
    Date y (Year{2000}, Date::dec, 1); 
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

    //This weird and unlikely error would still not be caught until run-time:
    // Date dx5(Year(4), Date::mar, 1998);   //  run-time error: Year::Invalid
}
catch (Year::Invalid&) {
    cerr << "error: Invalid year\n"; 
    return 1;
}
catch(exception& e){
    cerr << e.what() << endl;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
