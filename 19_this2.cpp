// 19_this2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }

    // void Destroy(Sample* this)
    void Destroy()
    {
        delete this;
    }

private:
    ~Sample() { cout << "~Sample()" << endl; }
};

// private 소멸자
//  - 지역 객체 / 전역 객체 생성이 불가능합니다.
//  - 의도: 객체를 new를 통해서만 생성할수 있도록 제한하겠다.

int main()
{
    // Sample s; // Sample::Sample()

    Sample* p = new Sample;

    p->Destroy(); // Sample::Destroy(p);

    // delete p;

} // Sample::~Sample()
