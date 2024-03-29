// 19_this2.cpp
#include <iostream>
using namespace std;

#if 0
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
#endif

#if 1

// 객체를 생성하는 역활
// : Factory

// private 생성자
//  : 객체 생성의 정책을 제한하고 싶을 때
class Sample {
private:
    Sample() { cout << "Sample()" << endl; }

public:
    ~Sample() { cout << "~Sample()" << endl; }

    friend Sample* CreateSample();

    // 객체 생성을 하지 않아도, 정적 멤버 함수는 호출할 수 있습니다.
    // - static factory method
    static Sample& CreateSample()
    {
        static Sample s;
        return s;
    }
};

// Sample 객체는 CreateSample 함수를 통해서만 생성할 수 있습니다.

Sample* CreateSample()
{
    // return new Sample;
    static Sample s;
    return &s;
}

// Sample s;
int main()
{
    // Sample s2;
    // Sample* p = new Sample;

    Sample* s1 = CreateSample();
    Sample* s2 = CreateSample();

    Sample& s3 = Sample::CreateSample();

    cout << s1 << endl;
    cout << s2 << endl;
}

// Design Pattern: 설계 패턴
// => 잘 만들어진 소프트웨어의 설계적 공통점 23가지
#endif
