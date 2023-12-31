#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
    return (a < b) ? a:b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
};

int main() 
{
    Person p1 {"Curly", 50};
    Person p2 {"Moe", 30};

    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger " << std::endl;

     std::cout << min<int>(2,3) << std::endl;       //2
     std::cout << min(2,3) << std::endl;            //2
     std::cout << min('A', 'B') << std::endl;       //A
     std::cout << min(12.5, 9.2) << std::endl;      //9.2
     std::cout << min(5+2*2, 7+40) << std::endl;    //9

     func<int,int>(10,20);
     func(10,20);
     func<char, double>('A', 12.4);
     func('A', 12.4);
     func(1000, "Testing");
     func(2000, std::string{"Frank"});

}