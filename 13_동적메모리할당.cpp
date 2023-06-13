// 13_동적메모리할당.cpp
#include <iostream>
using namespace std;

#include <cstdlib>

// 1. malloc / free
//   void* malloc(size_t size)
//   void free(void* p)

// 2. malloc은 void*를 반환하기 때문에,
//    명시적인 캐스팅이 필요합니다. - static_cast

// 3. malloc은 함수이지만,
//    C++은 new 연산자를 통해 동적 메모리 할당을 수행할 수 있습니다.
//    - 크기를 전달하는 것이 아니라, 타입을 전달합니다.
//    - 전달한 타입의 주소 타입을 반환하기 때문에,
//      별도의 캐스팅이 필요하지 않습니다.

// 4. delete 연산자를 통해 new를 통해 할당한 메모리를 해지할 수 있습니다.

int main()
{
    int* p = new int;

    *p = 42;
    cout << *p << endl;

    delete p;
}

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));

    *p = 42;
    cout << *p << endl;

    free(p);
}
#endif
