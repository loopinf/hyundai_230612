// 21_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample& rhs) { cout << "Sample(const Sample&)" << endl; }

    ~Sample() { cout << "~Sample()" << endl; }
};

// 주의 사항: 지역 객체의 참조를 반환하는 것은 미정의 동작입니다.
// > 지역 객체는 반드시 값으로 반환해야 합니다.
Sample& foo()
{
    Sample s;
    return s;
}

int main()
{
    cout << "--------" << endl;
    foo();
    cout << "--------" << endl;
}

#if 0
// 지역 변수의 주소를 반환하는 것은 미정의 동작입니다.
int* foo()
{
    int arr[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    return arr;
}

// 지역 변수의 참조를 반환하는 것은 미정의 동작입니다.
int& goo()
{
    int x = 42;
    return x;
}

int main()
{
    int& r = goo();
    cout << r << endl;

    // int* p = foo();
    // for (int i = 0; i < 10; i++) {
    //     cout << p[i] << endl;
    // }
}
#endif
