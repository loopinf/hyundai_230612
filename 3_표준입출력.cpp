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
