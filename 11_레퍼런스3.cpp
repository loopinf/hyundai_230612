#include <iostream>
using namespace std;

struct Person {
    char name[32];
    int age;
};

void PrintPerson(Person person)
{
    cout << person.name << ", " << person.age << endl;
}

int main()
{
    Person person = { "Tom", 42 };
    PrintPerson(person);
}
