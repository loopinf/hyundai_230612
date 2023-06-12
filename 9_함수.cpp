// 9_함수.cpp
#include <iostream>
using namespace std;

// 파라미터 기본값
// 정의: 함수의 파라미터의 기본값을 지정할 수 있습니다.
// 원리: 함수를 호출할 때, 전달된 인자가 없는 경우
//     기본값을 컴파일러가 자동으로 전달합니다.

// 주의사항
// 1) 뒤에서부터 지정해야 합니다.
// 2) 선언부에만 작성해야 합니다.

// 함수 선언 - 헤더 파일
int Add(int a, int b, int c = 0, int d = 0);

int main()
{
    cout << Add(10, 20, 30, 40) << endl;
    cout << Add(10, 20, 30) << endl;
    cout << Add(10, 20) << endl;

    // cout << Add(10, 20, 30, 0) << endl;
    // cout << Add(10, 20, 0, 0) << endl;
}

// 함수 정의 - 소스 파일
int Add(int a, int b, int c /* =0 */, int d /* =0 */)
{
    return a + b + c + d;
}
