#include <iostream>
#include <iomanip> // doesn't say it in the book but this is needed for setw()
#include <sstream>
using namespace std;
// yet another drill, nothing to see here

int main(){
    int birth_year = 1993;
    cout << showbase <<  dec << birth_year << "\tdecimal" << endl;
    cout << hex << birth_year << "\thexadecimal\n";
    cout << oct << birth_year << "\toctal" << endl;
    cout << dec << birth_year << endl;
    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d;
    //input 1234 1234 1234 1234, explain results
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
    // output should be 1234, 668, 4460, 4460, 
    // I am supposed to explain the results but the results are obvious. the input flags are sticky
    double f = 1234567.89;
    cout << defaultfloat << f << " " << fixed << f << " " << scientific << f << endl;
    cout << setw(16) << "First name" << setw(16) << "last name" << setw(16) << "Phone number" << setw(16) << "Email address" << endl;
    cout << setw(16) << "Patrick" << setw(16) << "McLellan" << setw(16) << "123-456-7890" << setw(16) << "Email address" << endl;
    cout << setw(16) << "Paddy" << setw(16) << "McLellan" << setw(16) << "123-456-7890" << setw(16) << "Email address" << endl;
    cout << setw(16) << "Patricia" << setw(16) << "McLellan" << setw(16) << "123-456-7890" << setw(16) << "Email address" << endl;
    cout << setw(16) << "Miley" << setw(16) << "McLegglan" << setw(16) << "123-456-7890" << setw(16) << "Email address" << endl;
    cout << setw(16) << "Patrick" << setw(16) << "McLellan" << setw(16) << "123-456-7890" << setw(16) << "Email address" << endl;

    cin >> a; // keep window open
    }