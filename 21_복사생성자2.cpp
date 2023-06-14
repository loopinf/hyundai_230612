// 21_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }

    ~Sample() { cout << "~Sample()" << endl; }
};

// 복사 생성자
// 1) 함수의 인자로 객체가 call by value로 전달될 때
// 해결 방법
//  => const&로 전달해야 합니다.
// void foo(Sample s)
#if 0
void foo(const Sample& s)
{
}

int main()
{
    Sample s; // Sample();

    cout << "----------" << endl;
    foo(s);
    cout << "----------" << endl;
}
// ~Sample();
#endif

// 2) 함수가 객체를 값으로 반환할 때
//  > 유효한 메모리의 객체라면, 참조를 반환하면 됩니다.

Sample s;
// Sample foo()

Sample& foo()
{
    return s; // '반환용 임시 객체'가 생성되서 전달됩니다.
}

int main()
{
    cout << "--------" << endl;
    foo();
    cout << "--------" << endl;
}
