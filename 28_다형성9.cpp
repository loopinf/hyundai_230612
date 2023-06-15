// 28_다형성9.cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    int type; // 0: Rect, 1: Circle, 2: Triangle

    virtual ~Shape() { }

    virtual void Draw() const { cout << "Draw Shape" << endl; }
    virtual Shape* Clone() const { return new Shape(*this); }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
    Shape* Clone() const override { return new Rect(*this); }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Draw Circle" << endl; }
    Shape* Clone() const override { return new Circle(*this); }
};

int main()
{
    vector<Shape*> shapes;

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        }

        else if (cmd == 0) {
            // 도형을 복제하는 기능
            int index;
            cout << "몇번째 도형: ";
            cin >> index;

            Shape* copy = shapes[index]->Clone();
            shapes.push_back(copy);
            // 문제점: type에 의존하는 코드는 OCP를 만족하지 않습니다.
            //       Replace type code with polymorphism => Refactoring

            // 리팩토링(마틴 파울러), 1판: Java, 2판: Javascript(객체 지향 + 함수형)
            //  - 유지보수성을 떨어뜨리는 코드 => 냄새

            // 클린 코드(로버트 C 마틴, 엉클 밥)
            // => 테스트

            // 객체의 복제를 다형성으로 구현하는 설계
            //  => Prototype Pattern
#if 0
            // shapes[index] // Rect?? Circle???
            int type = shapes[index]->type;
            if (type == 0) {
                // 사각형 복사해서 추가
            } else if (type == 1) {
                // 원을 복사해서 추가
            } // ..
#endif

        }

        else if (cmd == 9) {

            for (auto e : shapes) {
                e->Draw();
                // e->Draw()   ---> Rect  -> Rect::Draw
                //                 Circle -> Circle::Draw
                //                  ....
            }
        } else {
            break;
        }
    }

    // 모든 도형의 메모리를 해지합니다.
    for (auto e : shapes) {
        delete e;
    }
}
