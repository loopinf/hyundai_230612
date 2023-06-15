// 26_참조반환.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class User {
    string name;
    int age;
    string address;
    string job;

public:
    // Setter
    void SetName(const std::string& s) { name = s; }
    void SetAge(int a) { age = a; }
    void SetAddress(const std::string& s) { address = s; }
    void SetJob(const std::string& s) { job = s; }
};

int main()
{
    User user;

    user.SetName("Bob");
    user.SetAddress("Seoul");
    user.SetAge(42);
    user.SetJob("Student");
}
#endif

#if 0
class User {
    string name;
    int age;
    string address;
    string job;

public:
    // Setter
    User* SetName(const std::string& s)
    {
        name = s;
        return this;
    }

    User* SetAge(int a)
    {
        age = a;
        return this;
    }

    User* SetAddress(const std::string& s)
    {
        address = s;
        return this;
    }

    User* SetJob(const std::string& s)
    {
        job = s;
        return this;
    }
};

int main()
{
    User user;

    user.SetName("Bob");
    user.SetAddress("Seoul");
    user.SetAge(42);
    user.SetJob("Student");

    user.SetName("Bob")->SetAddress("Seoul")->SetAge(42)->SetJob("Student");
}
#endif

class User {
    string name;
    int age;
    string address;
    string job;

public:
    // Setter
    User& SetName(const std::string& s)
    {
        name = s;
        return *this;
    }

    User& SetAge(int a)
    {
        age = a;
        return *this;
    }

    User& SetAddress(const std::string& s)
    {
        address = s;
        return *this;
    }

    User& SetJob(const std::string& s)
    {
        job = s;
        return *this;
    }

    void Print() const
    {
        cout << name << ", " << age << endl;
    }
};

// foo(User user)
void foo(const User& user)
{
    user.Print();
}

void goo(User& user)
{
    user.SetAddress("Suwon");
}

int main()
{
    User user;

    user.SetName("Bob");
    user.SetAddress("Seoul");
    user.SetAge(42);
    user.SetJob("Student");

    // 자기 자신의 참조를 반환 하면 Chaining을 통해 기능을 이용할 수 있습니다.
    user.SetName("Bob")
        .SetAddress("Seoul")
        .SetAge(42)
        .SetJob("Student");
}
