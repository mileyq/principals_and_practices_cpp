// by Pat M. Using the text book provided code then added my own to it
// mostly just hacked code for one time usage, on to the next exercise!
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct Point
{
    int x;
    int y;
    Point(){};
    Point(int a, int b):x{a},y{b}{
        x = a;
        y = b;
    }
    friend istream& operator>>(istream& ist, Point& p)
    {
        char a,b,c;

        if ((ist >> a >> p.x >> b >> p.y >> c) && !(a == '(' && b == ',' && c == ')'))
            throw runtime_error("Invalid format");

        return ist;
    }

    friend ostream& operator<<(ostream& ost, const Point& p)
    {
        return ost << '(' << p.x << ',' << p.y << ')' << endl;
    }
};


int main() // code is 
try
{
    vector<Point> original_points{};
    cout << "please enter 7 points (x, y):" << endl;

    for (int i=0; i<7; i++){ // same as in struct Point operator>>() but wrote by Pat M.
        Point P;
        char c;
        cin >> c;
        if(c!='('||!cin) break;
        cin >> P.x >> c;
        if(!cin||c!=',') break;
        cin >> P.y >> c;
        if(!cin || c!=')') break;
        original_points.push_back(P);
    }

    for(int i=0; i<original_points.size(); i++){ // same as in struct Point operator<<() but written by Patm 
        cout << '(' << original_points[i].x << ", " << original_points[i].y << ')' << endl;
    }

    string name; 

    Point p;
    vector<Point> points{};    

    ofstream ost(string("mydata.txt").c_str());    // ost is an output stream for a file named name
    for (int i=0; i<original_points.size(); ++i)
        ost << '(' << original_points[i].x << ',' << original_points[i].y << ")\n";
    if (!ost) throw runtime_error("can't open output file");
    ost.close();
    ifstream ist("mydata.txt");
    if(!ist)throw runtime_error("can't open input file");
    vector<Point> processed_points{};
    while(ist>>p){
        processed_points.push_back(p);
    }
    for(Point i: processed_points){
        cout << i; // uses the struct Point operator>>(ostream&, Point&)
    }
    cout << endl;

    // these following vectors are not used, I used them temperarily to check if the for loop below worked. It does.
    vector<Point> test = original_points;
    vector<Point> test2{Point(1,1), Point(1, 4), Point(11,4), Point(41,4), Point(1, 14), Point(11,4), Point(151,15)};

    for(int i = 0; i<original_points.size(); i++){ 
        // this code checks if the ifstream and ofstream vectors are different
        // they shouldn't be different
        int opy, opx, ppy, ppx;
        opx = original_points.at(i).x;
        opy = original_points.at(i).y;
        ppx = processed_points.at(i).x;
        ppy = processed_points.at(i).y;
        if (opx != ppx){
            cout << "original point[" << i << "].x " << opx << " not equal " 
            << "processed point[" << i << "].x " << ppx << endl;
        }
        if (opy != ppy){
            cout << "original point[" << i << "].y " << opy << " not equal " 
            << "processed point[" << i << "].y " << ppy << endl;
        }
    }

    cin >> name; // keep terminal open
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}