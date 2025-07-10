#include <iostream>
#include <array>
using namespace std;
struct Student{
    int rollNo;
    string name;
};
struct Person{
    int age;
    int id;
};
int main(){
    array <Student,3> stud_array{};
    stud_array[0] = {1,"Abhay"};
    stud_array[1] = {2,"Rohit"};
    stud_array[2] = {3,"Suresh"};

    cout << "Student Details:\n";
    for(const auto &student : stud_array){
        cout << "Roll No: " << student.rollNo << ", Name: " << student.name << endl;
    }

    //ctad

    constexpr array stud_array2 {
        Student{4, "Amit"},
        Student{5, "Rahul"},
        Student{6, "Priya"}
    };

    cout << "Student Details from CTAD array:\n";
    for(const auto &student : stud_array2){
        cout << "Roll No: " << student.rollNo << ", Name: " << student.name << endl;
    }
    /*
        constexpr array <Person,3> person_array{
            {1,2},
            {3,4},
            {5,6}
        };

                5_StdArrInProgramDefined.cpp:38:9: error: excess elements in struct initializer
        38 |         {3,4},
            |         ^~~~~
        1 error generated.

        This happens because aggregate initialization for constexpr std::array requires each element to be explicitly constructed,
        especially in C++20 and later.
                To fix this, we need to explicitly construct each element of the array using the constructor of the struct.

        Refer : https://www.learncpp.com/cpp-tutorial/stdarray-of-class-types-and-brace-elision/

    */

    //Corrected version : use double brace initialization for maching c style initialization
    constexpr array <Person,3> person_array{
        {
            {1,2},
            {3,4},
            {5,6}
        }

    };
    cout << "Person Details array:\n";
    for(const auto &person : person_array){
        cout << "Age: " << person.age << ", ID: " << person.id << endl;
    }

    return 0;
}