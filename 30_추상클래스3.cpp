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
// => 교체 가능한 유연한 설계!
//   DIP(Dependency Inversion Principle, 의존 관계 역전 원칙)
//   : 클래스는 구체적인 타입에 의존하는 것이 아니라,
//     추상클래스/인터페이스에 의존해야 합니다.

//                    <<interface>>
//     Car ------------> BlackBox
//                          |
//                       ------------
//                       |          |
//                    Camera    FHDCamera

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

// 3) 카메라의 제작자는 BlackBox의 인터페이스를 기반으로
//    카메라를 제작해야 합니다.

// - "Camera는 BlackBox를 상속합니다" 라고 하지 않고,
//   "Camera는 BlackBox를 인터페이스를 구현합니다." 라고 합니다.
// Java
//  상속: class Camera extends BlackBox
//  구현: class Camera implements BlackBox

class Camera : public BlackBox {
public:
    void StartRecording() override { cout << "Start Recording" << endl; }
    void StopRecording() override { cout << "Stop Recording" << endl; }
};

class FHDCamera : public BlackBox {
public:
    void StartRecording() override { cout << "FHDCamera Start Recording" << endl; }
    void StopRecording() override { cout << "FHDCamera Stop Recording" << endl; }
};

int main()
{
    FHDCamera camera;
    Car car(&camera);

    car.Start();
}
