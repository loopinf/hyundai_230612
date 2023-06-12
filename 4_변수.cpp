// 4_변수.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입
//  - struct / union / enum
struct Point {
    int x;
    int y;
};

union Job {
    char school[32];
    char company[32];
};

enum TaskState {
    TASK_RUNNING,
    TASK_STOPPED
};

#if 0
typedef struct Point POINT;
typedef union Job JOB;
typedef enum TaskState TASK_STATE;

int main()
{
    struct Point pt;
    union Job job;
    enum TaskState taskState;

    POINT pt2;
    JOB job2;
    TASK_STATE taskState2;
}
#endif

// C++은 태그를 타입으로 인식합니다.
int main()
{
    Point pt;
    Job job;
    TaskState taskState;
}
