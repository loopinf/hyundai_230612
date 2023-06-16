// 30_추상클래스3.cpp
#include <iostream>
using namespace std;

// 1. Car ------> Camera
//    원인: Car가 Camera 구체적인 타입에 의존합니다.
//         "강한 결합"
//   문제점: 새로운 카메라가 나올 때마다, Car의 코드가 수정되어야 합니다.
//   "OCP"를 만족하지 않습니다.

// 2. 해결 방법
//   약한 결합 / 느슨한 결합

// 1) 카메라 제작자와 자동차의 제작자가 카메라의 인터페이스(사용 방법)를 약속합니다.
//    "인터페이스" / "프로토콜"

// > 인터페이스를 C++에서 제공하는 방법
class BlackBox {
public:
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 카메라의 인터페이스를 이용하는 코드를 작성합니다.
class Car {
    BlackBox* camera;

public:
    Car(BlackBox* p)
        : camera(p)
    {
    }

    void Start()
    {
        camera->StartRecording();
        cout << "자동차 주행 시작" << endl;
        camera->StopRecording();
    }
};

int main()
{
}
