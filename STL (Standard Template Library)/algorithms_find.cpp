// Algorithms
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person
{
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age)
        : name{name}, age{age} {}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Find an element in a container
void find_test() {
    std::cout << "\n===================================" << std::endl;

    std::vector <int> vec{1,2,3,4,5};

    auto loc = std::find(std::begin(vec), std::end(vec), 1);

    if (loc != std::end(vec))
        std::cout << "Found the number : " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20});
    if (loc1 != players.end())
        std::cout << "Found Moe" << std::endl;
    else
        std::cout << "Moe not found" << std::endl;
};

// Replace occurrences of elements in a container
void replace_test() {
    std::cout << "\n=========================================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,1,2,1};
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i:vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
};

// Check occurences of elements in a container
void all_of_test() {
    std::vector<int> vec1 {1,2,3,4,7,9,1,2,13,19,5};
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) {return x > 10; }))
        std::cout << "All the elements are > 10 "<< std::endl;
    else
        std::cout << "Not all the elements are > 10:" << std::endl;

    if (std::all_of(vec1.begin(), vec1.end(), [](int x) {return x < 20; }))
        std::cout << "All the elements are < 20" << std::endl;
    else
        std::cout << "Not all the elements are < 20" << std::endl;
}
int main() {
    find_test();
    replace_test();
}