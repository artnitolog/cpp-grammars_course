#include <list>
#include <iostream>
using namespace std;
struct A { 
A(){ cout << "A() "; } 
~A(){ cout << "~A() "; }
};

struct B:A { 
B(){ cout << "B() "; } 
~B(){ cout << "~B() "; } 
}; 

int main () {
    try { 
        //  A a; 
         B b;
    throw b; 
    }
    catch (A &y) { std::cout << "1"; }
    std::cout << "2";
}
