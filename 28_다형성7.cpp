// 28_다형성7.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal {
public:
    Dog() { cout << "Dog()" << endl; }

    ~Dog() override { cout << "~Dog()" << endl; }
    // 부모의 소멸자가 가상이 아닌 경우, 컴파일 오류가 발생합니다.
};

// 1. 아래 코드에서 자식의 소멸자가 제대로 호출되지 않는 문제를 이해해야 합니다.
//  => 소멸자도 함수 이고, 정적 바인딩을 하기 때문입니다.
//  => 소멸자를 동적 바인딩
//    "가상 소멸자"

// 2. 가상 소멸자 필요한 이유
//  => 부모 포인터 타입을 통해 자식 객체를 delete 할때
//     자식의 소멸자가 제대로 호출되지 않는 문제를 해결하기 위해서
//   "부모 클래스의 소멸자는 반드시 가상이어야 합니다."

// 3. 가상 소멸자가 없는 클래스는 상속을 금지해야 합니다.
//  : class Car final { };

// 4. 부모의 소멸자가 가상이면, 자식의 소멸자도 가상입니다.

int main()
{
    Animal* p = new Dog;

    delete p;
}

#if 0
int main()
{
    Dog d;
}
#endif
