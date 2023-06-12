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

namespace mp3 {
    void Play() { std::cout << "Mp3 Play" << std::endl; }
}

namespace mp4 {
    void Play() { std::cout << "Mp4 Play" << std::endl; }
}
}

// audio_play.cpp
namespace audio {
// ...
}

// video.cpp
namespace video {
void Init() { std::cout << "Video Init" << std::endl; }
}

// 2. namespace
// - 이름 충돌 해결
// - 프로그램의 각 요소를 관련된 요소끼리 그룹화할 수 있습니다.

int main()
{
    audio::Init();
    video::Init();

    audio::mp3::Play();
    audio::mp4::Play();
}
