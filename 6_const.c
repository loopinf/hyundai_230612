// 6_const.c

#include <stdio.h>

int main(void)
{
    const int c;
    // C는 초기화가 강제되지 않습니다.
    printf("%d\n", c);

    const char* s = "hello";
    // s[0] = 'x'; // 미정의 동작
}
