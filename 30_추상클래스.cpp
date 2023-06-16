// 30_추상클래스.cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() { }
    virtual void Draw() const { cout << "Draw Shape" << endl; }
};

int main()
{
}
