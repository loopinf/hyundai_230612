// 30_추상클래스2.cpp
#include <iostream>
using namespace std;

// SRP(Single Responsibility Principle, 단일 책임 원칙)
// : 모든 클래스는 단 하나의 책임을 가져야 한다.

class Camera {
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Stop Recording" << endl; }
};

class FHDCamera {
public:
    void StartRecording() { cout << "FHDCamera Start Recording" << endl; }
    void StopRecording() { cout << "FHDCamera Stop Recording" << endl; }
};

class Car {
    // Camera* camera;
    FHDCamera* camera;

public:
    Car(FHDCamera* p)
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
    FHDCamera camera;
    Car car(&camera);

    car.Start();
}
