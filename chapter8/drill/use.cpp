#include "my.h"
#include <iostream>
using std::cin;
int foo;
int main(){
    foo = 7;
    print_foo();
    print(99);

    int x = 7;
    int y = 9;
    swap_v(x,y);
    std::cout << x << " " << y << std::endl;
    swap_r(x,y);
    std::cout << x << " " << y << std::endl;
//    swap_cr(x,y);
    swap_v(7,9);
//    swap_r(7,9);
//    swap_cr(7,9);
    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
    std::cout << cx << " " << cy << std::endl;
//    swap_r(cx,cy);
//    swap_cr(cx, cy);
    std::cout << cx << " " << cy << std::endl;
    swap_v(7.7, 9.9);
//    swap_r(7.7, 9.9);
//    swap_cr(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx, dy);
    std::cout << dx << " " << dy << std::endl;
//    swap_r(dx, dy);
//    swap_cr(dx, dy);
    std::cout << dx << " " << dy << std::endl;
    char cc;
    cin >> cc;
    
    return 0;
}