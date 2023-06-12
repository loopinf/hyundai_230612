// 2_namespace.cpp
#include <iostream>

// 1. C 에서는 이름 충돌의 문제를 해결할 수 있는 기능이 제공되지 않습니다.
// a.c
// void video_init() {}

// b.c
// void audio_init() {}

// audio.cpp
namespace audio {
void Init() { std::cout << "Audio Init" << std::endl; }
}

// video.cpp
namespace video {
void Init() { std::cout << "Video Init" << std::endl; }
}

int main()
{
    audio::Init();
    video::Init();
}
