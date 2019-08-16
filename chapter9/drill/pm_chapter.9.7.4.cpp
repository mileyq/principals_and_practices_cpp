
// Modified by Pat M. (9.4.1, 9.4.2, 9.4.3, 9.7.1, 9.7.4 were all very repetitive)
// This is example code from Chapter 9.7.4 "Const member functions" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) {}

    int   day()   const;         // const member: can't modify
    Month month() const;         // const member: can't modify
    int   year()  const;         // const member: can't modify

    void add_day(int n);         // non-const member: can modify
    void add_month(int n);       // non-const member: can modify
    void add_year(int n);        // non-const member: can modify
    void print_day();
    void set_day(int y, int m, int d);
private:
    int   y;                     // year
    Month m;
    int   d;                     // day of month
};

//------------------------------------------------------------------------------
void Date::print_day(){
    cout << Date::m << " " << Date::d << " " << Date::y << endl;
}
int Date::day() const
{
    //++d;        // error: attempt to change object from const member function
    return d;
}

// PM: not best function but I am just completed drill according to requirements ------------------------------------------------------------------------------
void Date::set_day(int y, int m, int d){
if(1<=m && m<=12 && 1<=d && d<=31){
        Date::y = y;
        Date::m = static_cast<Month>(m);
        if (1<=d&&d<=31){
            Date::d = d;
        }
        else throw runtime_error("bad day in set-day initialization");
    }
    else throw runtime_error("invalid init date");
}

void Date::add_day(int n) {
    n = Date::d + n;
    while(n>31){
        n=n-31;
        if(Date::m==dec){
            Date::m=jan;
            y ++ ;
        }
        else{
            Date::m = Month(static_cast<Month>(m)+ 1);
        }
    }
    Date::d = n;
}

//------------------------------------------------------------------------------

void some_function(Date& d, const Date& start_of_term)
{
    int a = d.day();             // ok
    int b = start_of_term.day(); // should be ok (why?)
    d.add_day(3);                // fine
    //start_of_term.add_day(3);  // error
}

//------------------------------------------------------------------------------

int main()
{
    Date d(2000, Date::jan, 20);
    const Date cd(2001, Date::feb, 21);

    cout << d.day() << " - " << cd.day() << endl;        // ok
    d.add_day(1);                // ok
    //cd.add_day(1);             // error: cd is a const
    some_function(d,cd);
    //some_function(cd,d);       // error: cd is a const
    Date y (2000, Date::dec, 1); 
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
    return 0;
}

//------------------------------------------------------------------------------
