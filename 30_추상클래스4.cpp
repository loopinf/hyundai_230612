// 30_추상클래스4.cpp
#include <iostream>
using namespace std;

// 인터페이스
//  - 구현을 제공하지 않고, 사용 방법(약속)을 순수 가상 함수 형태로 제공합니다.
//  => 새로운 기능의 추가가 어렵습니다.

// 인터페이스
class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // 추가되는 기능
    //  : 인터페이스에서 기본 구현을 제공해야 합니다. / Java8(Modern Java): defender method
    virtual void PlayOneMinute()
    {
        Play();
        cout << "1분 후" << endl;
        Stop();
    }
};

class Car {
    MP3* mp3;

public:
    Car(MP3* p)
        : mp3(p)
    {
    }

    void PlayMusic()
    {
        // mp3->Play();
        // mp3->Stop();

        mp3->PlayOneMinute();
    }
};

// 각 버전별로 인터페이스를 구현하는 클래스를 제공해야 합니다.
class Player : public MP3 {
public:
    void Play() override { cout << "MP3 Play" << endl; }
    void Stop() override { cout << "MP3 Stop" << endl; }
};

class PlayerV2 : public MP3 {
public:
    void Play() override { cout << "[2] - MP3 Play" << endl; }
    void Stop() override { cout << "[2] - MP3 Stop" << endl; }
};

MP3* CreatePlayer(int version)
{
    if (version == 2) {
        return new PlayerV2;
    }

    return new Player;
}

int main()
{
    // PlayerV2 player;
    // Car car(&player);
    Car car(CreatePlayer(2));

    car.PlayMusic();
}
