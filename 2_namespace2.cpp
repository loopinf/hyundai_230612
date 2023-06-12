// 2_namespace2.cpp
#include <iostream>

// namespace를 사용하는 방법 3가지
// 1) 전체 이름을 명시하는 방법
#if 0
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
#endif

// 2) using 선언(Declaration)
#if 0
using std::cout;
using std::endl;

namespace audio {
void Play() { cout << "Audio Play" << endl; }
}
using audio::Play;

int main()
{
    cout << "Hello, C++" << endl;
    Play();
}
#endif

// 3) using 지시어(Directive)
// > 특정한 이름 공간의 모든 함수 / 변수를 암묵적으로 접근할 수 있습니다.
// - 주의해야 합니다.
//  => 이름 충돌의 문제의 가능성이 생깁니다.

namespace video {
void Play() { cout << "Video Play" << endl; }
}

namespace audio {
void Play() { cout << "Audio Play" << endl; }
}

using namespace std;
// using namespace audio;
// using namespace video;

using video::Play;

int main()
{
    cout << "Hello, C++" << endl;
    audio::Play();
    Play();
}
