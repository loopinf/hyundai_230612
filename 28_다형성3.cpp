// 28_다형성3.cpp
#include <iostream>
using namespace std;

// 동적 배열 - STL, vector
//  : 크기가 동적으로 늘어나는 동적 배열입니다.
#include <vector>

class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };

// 2. 동종을 보관하는 컨테이너
int main()
{
    vector<Animal*> animals;

    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Dog);
}

#if 0
int main()
{
    vector<Cat*> cats;
    cats.push_back(new Cat);
    cats.push_back(new Cat);
    cats.push_back(new Cat);
    cats.push_back(new Cat);

    vector<Dog*> dogs;
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
    dogs.push_back(new Dog);
}
#endif
