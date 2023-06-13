#include <iostream>
using namespace std;

struct Person {
    char name[32];
    int age;

    // ...
};

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
}

// const Person& => 참조하는 변수를 변경할 수 없습니다.
void PrintPerson3(const Person& person)
{
    cout << person.name << ", " << person.age << endl;
}

int main()
{
    cout << sizeof(Person) << endl;

    Person person = { "Tom", 42 };
    PrintPerson(person);

    PrintPerson2(&person);
    PrintPerson2(NULL);

    PrintPerson3(person);
}
