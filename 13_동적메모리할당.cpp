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
// 5. 연속된 메모리를 해지할 때는,
//    delete[] 연산자를 사용해야 합니다.

#if 0
int main()
{
    int* p = new int;

    *p = 42;
    cout << *p << endl;
    delete p;

    int* arr = new int[10]; // 40 byte
    arr[0] = 10;
    arr[9] = 42;
    cout << arr[0] << ", " << arr[9] << endl;

    // 주의: 연속된 메모리를 해지할 때,
    //      delete[] 연산자를 이용해야 합니다.
    delete[] arr;
}
#endif

#if 0
int main()
{
    int* p = static_cast<int*>(malloc(sizeof(int)));
    *p = 42;
    cout << *p << endl;
    free(p);

    int* arr = static_cast<int*>(malloc(sizeof(int) * 10));
    arr[0] = 10;
    arr[9] = 42;

    cout << arr[0] << ", " << arr[9] << endl;

    free(arr);
}
#endif

int main()
{
    // int* p = static_cast<int*>(malloc(sizeof(int)));
    // malloc은 초기화되지 않은 메모리를 반납합니다.

    // int* p = static_cast<int*>(calloc(1, sizeof(int)));
    // calloc은 0으로 초기화된 메모리를 반납합니다.

    // int* p = new int;
    // 초기화되지 않은 메모리를 반납합니다 - 쓰레기값

    int* p1 = new int(42);
    cout << *p1 << endl;

    int* p2 = new int { 42 };
    cout << *p2 << endl;

    delete p1;
    delete p2;

    // int* p3 = new int[3];
    // 초기화되지 않은 메모리를 반납합니다.

    int* p3 = new int[3] { 10, 20, 30 };
    for (int i = 0; i < 3; ++i) {
        cout << p3[i] << endl;
    }

    delete[] p3; // !!!
}
