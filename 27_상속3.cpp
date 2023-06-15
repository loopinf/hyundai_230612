// 27_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모의 private은 자식 클래스에서 접근이 불가능합니다.

// 2. protected
//    : 외부에서 접근이 불가능하지만, 자식 클래스는 접근이 가능한 접근 지정자

// 3. 접근 지정자
//  1) private: 외부 접근 불가능, friend 클래스 / 함수 접근 가능
//  2) protected: 외부 접근 불가능, 자식 클래스 접근 가능
//  3) public: 외부 접근 가능

// 4. 클래스의 멤버 데이터를 protected로 지정하는 것은 좋지 않습니다.
//    자식 클래스에서 부모의 멤버 데이터에 접근이 필요한 경우,
//    멤버 함수를 통해 접근하는 것이 좋습니다.

// 5. 상속은 부모 클래스와 자식 클래스의 강한 결합을 형성합니다.
//    "무분별한 상속은 위험하다."

class Animal {
private:
    // protected:
    int age_;

public:
    Animal()
        : age_(42)
    {
    }

protected:
    int GetAge() const { return age_; }
};

class Dog : public Animal {
    int color;

public:
    void PrintAge() const
    {
        // cout << age << endl;
        cout << GetAge() << endl;
    }
};

int main()
{
    Dog d;
    d.PrintAge();
}
