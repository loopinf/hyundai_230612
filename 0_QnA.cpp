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

#if 0
#include <string>
class Sample {
    string name;

public:
    Sample(const string& s)
        : name(s)
    {
        cout << "객체 생성: " << name << endl;
    }

    ~Sample() { cout << "객체 파괴: " << name << endl; }
};

int main()
{
    Sample s1("A");
    Sample s2("B");
}
#endif
