// 3_표준입출력.cpp
#include <iostream>
using namespace std;

// 표준 입출력
// 1) 표준 입력 - stdin
//   scanf
//   std::cin

// 2) 표준 출력 - stdout
//   printf
//   std::cout

// 3) 표준 에러 - stderr
//   fprintf(stderr, "...");
//   std::cerr

#if 0
int main()
{
    double n;
    scanf("%lf", &n);
    printf("n: %lf\n", n);

    cin >> n;
    cout << "n: " << n << endl;

    char str[32];
    scanf("%s", str);
    printf("%s\n", str);

    cin >> str;
    cout << str << endl;
}
#endif

#include <iomanip> // setw / setfill

int main()
{
    // int n = 0xFAFA;
    //      1111 1010 1111 1010

    // C++11, 2진수 상수를 표현할 수 있습니다.
    //   > 단일 따옴표를 통해 가독성을 높일 수 있습니다.
    int n = 0b11'1110'101'1111'010;

    printf("%x\n", n);
    cout << hex << n << endl; // IO 조정자(manipulator)

    printf("%X\n", n);
    cout << hex << uppercase << n << endl;

    printf("%010d\n", n);
    cout << setw(10) << setfill('0') << dec << n << endl;
}
