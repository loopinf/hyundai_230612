// 2_namespace2.cpp
#include <iostream>

// namespace를 사용하는 방법 3가지
// 1) 전체 이름을 명시하는 방법

// 전역 이름 공간의 함수
void Play() { std::cout << "Global Play" << std::endl; }

namespace audio {
void Play() { std::cout << "Audio Play" << std::endl; }

// 같은 이름 공간의 함수를 암묵적으로 호출할 수 있습니다.
// void Init() { Play(); }

void Init() { ::Play(); }
//           Global namespace - ::
}

int main()
{
    std::cout << "Hello, C++" << std::endl;
    audio::Play();
    audio::Init();
}
