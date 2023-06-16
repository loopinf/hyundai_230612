// 32_연산자오버로딩8.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// Image*
//  포인터 역활을 수행하는 클래스
//   => 스마트 포인터
//  핵심: 포인터 객체가 파괴될 때, 참조하는 자원을 자동으로 해지합니다.
#if 0
class Ptr {
    Image* obj;

public:
    inline Ptr(Image* p = nullptr)
        : obj(p)
    {
    }

    inline ~Ptr() { delete obj; }

    inline Image& operator*() { return *obj; }
    inline Image* operator->() { return obj; }
};
#endif

template <typename T>
class Ptr {
    T* obj;

public:
    inline Ptr(T* p = nullptr)
        : obj(p)
    {
    }

    inline ~Ptr() { delete obj; }

    inline T& operator*() { return *obj; }
    inline T* operator->() { return obj; }
};

// 표준 라이브러리에 스마트 포인터가 제공됩니다.
#include <memory>
//  1) shared_ptr
//   : 참조 계수, 소유권 공유

//  2) unique_ptr
//   : 복사 금지, 소유권 독점

int main()
{
    shared_ptr<Image> p1(new Image);
    p1->Draw();

    unique_ptr<Image> p2(new Image);
    p2->Draw();
}

#if 0
int main()
{
    Ptr<Image> p = new Image;

    (*p).Draw();
    // (p.operator*()).Draw()

    p->Draw();
    //         p.operator->()Draw()
    // 컴파일러: p.operator->()->Draw()
}
#endif

#if 0
int main()
{
    Image* p = new Image;
    p->Draw();

    delete p;
}
#endif
