#include <iostream>
#include <typeinfo>
using namespace std;

class Shape { public: virtual ~Shape() {}; };
class Circle : public Shape {};
class Square : public Shape {};
class Other {};

int main(int argc, const char * argv[]) {
    
    Circle c;
    Shape* s = &c;   //Upcast
    s = static_cast<Shape*>(&c); // More explicit bu unnecessary
    Circle* cp = 0;
    Square* sp = 0;
    //Static Nav of class hierarchies
    //requires extra type information:
    if(typeid(s) == typeid(cp))
        cp = static_cast<Circle*>(s);
    if(typeid(s) == typeid(sp))
        sp = static_cast<Square*>(s);
    if(cp != 0)
        cout << "It's a circle!" << endl;
    if(sp != 0)
        cout << "It's a square!" << endl;
}
