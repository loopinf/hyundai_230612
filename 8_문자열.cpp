// 8_문자열.cpp
#include <iostream>
using namespace std;

#include <cstring> // strcmp

// C 문자열
// : '\0' 으로 끝나는 char 배열
// 1) 문자열의 연산을 함수를 통해서 처리해야 합니다.
// 2) 문자열을 위한 메모리 관리를 직접 해야 합니다.

#if 0
int main(void)
{
    char str1[32] = "hello";
    char str2[32] = "hello";

    if (strcmp(str1, str2) == 0) {
        printf("같은 문자열.\n");
    }

    char str3[32];
    // str3 = "hello";
    strcpy(str3, "hello");
    printf("%s\n", str3);

    strcat(str3, " world");
    printf("%s\n", str3);
}
#endif

// C++ 문자열
// => std::string

#include <string>

// 1) 문자열의 연산을 연산자를 이용할 수 있습니다.
// 2) 메모리 관리가 자동적으로 수행됩니다.
//  => 안전하게 사용할 수 있습니다.

int main()
{
    string s1 = "hello";
    string s2 = "hello";

    if (s1 == s2) {
        cout << "동일한 문자열.." << endl;
    }

    string s3 = s1;
    cout << s3 << endl;

    s3 += " world";
    cout << s3 << endl;
}
