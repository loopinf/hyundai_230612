#include <iostream>
using namespace std;

struct Person {
    char name[32];
    int age;

    // ...
};

// 사용자 정의 타입은 값으로 전달하는 것은 복사의 비용이 발생할 수 있습니다.
void PrintPerson(Person person)
{
    cout << person.name << ", " << person.age << endl;
}

// 포인터는 유효성 여부를 반드시 판단해야 합니다.
void PrintPerson2(const Person* person)
{
    if (person == NULL) {
        return;
    }

    cout << person->name << ", " << person->age << endl;

    // person->age = 100;
}

// const Person& => 참조하는 변수를 변경할 수 없습니다.
void PrintPerson3(const Person& person)
{
    cout << person.name << ", " << person.age << endl;

    // person.age = 100;
}
// 레퍼런스는 반드시 초기화가 필요하고, NULL 레퍼런스를 지정할 수 없습니다.

int main()
{
    cout << sizeof(Person) << endl;

    Person person = { "Tom", 42 };
    PrintPerson(person);

    PrintPerson2(&person);
    PrintPerson2(NULL);

    PrintPerson3(person);
}
