// 33_예외2.cpp
#include <iostream>
using namespace std;

// 반환값을 통한 오류 처리의 문제점
// 1) 오류 처리를 강제할 수 없습니다.
// 2) 반환값이 결과이지, 오류인지 모호할 수 있습니다.
//   : atoi

// 예외
// 1) 결과는 return, 오류는 throw 합니다.
// 2) 오류를 처리(catch)하지 않으면, 프로그램은 비정상 종료합니다.

int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        // return -1;
        throw -1;
    }

    return 0;
}

int main()
{
    try {
        OpenFile(nullptr);
    } catch (int& error) {
        cout << error << endl;
    }

    cout << "main 종료" << endl;
}
