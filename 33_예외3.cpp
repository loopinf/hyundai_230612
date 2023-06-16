// 33_예외3.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. 각 오류마다 사용자 정의 타입을 제공합니다.
class FileNotFound { };
class PermissionDenied { };

void OpenFile(const string& filename)
{
    // 오류의 원인
    // 1) 파일이 존재하지 않습니다.
    // 2) 권한이 없습니다.
    // ...
    if (filename == "a.txt") {
        throw FileNotFound();
    }

    if (filename == "b.txt") {
        throw PermissionDenied();
    }

    throw 1;

    // ...
}

// catch를 통해 받지 않은 예외 타입은 비정상 종료가 발생합니다.

int main()
{
    try {
        OpenFile("c.txt");
    } catch (FileNotFound& e) {
        cout << "파일이 존재하지 않습니다." << endl;
    } catch (PermissionDenied& e) {
        cout << "권한이 없습니다." << endl;
    } catch (...) {
        cout << "알수없는 오류가 발생하였습니다." << endl;
    }
}
