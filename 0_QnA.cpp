// 0_QnA.cpp
#include <iostream>
using namespace std;

struct Person {
    char name[32];
    int age;
};

void PrintPeron(Person person)
{
    cout << person.name << ", " << person.age << endl;
}

void PrintPerson2(Person* person)
{
    cout << (*person).name << ", " << (*person).age << endl;

    cout << person->name << ", " << person->age << endl;
}

int main()
{
    Person person = { "Tom", 42 };
    PrintPeron(person);

    PrintPeron(&person);
}
