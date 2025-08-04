#include <bits/stdc++.h>
using namespace std;
class Person{


public:
    string m_name{};
    int m_age{};
    Person(string_view name = "", int age = 0) : m_name(name), m_age(age) {}
    void setName(std::string &name){
        m_name = name;
    }
    void setAge(int age){
        m_age = age;
    }
};

class Employee : public Person{ 

private:
    long m_empID{};
    double m_salary{};
public:
    Employee(int empID = 0, double salary = 1):m_empID(empID),m_salary(salary){}

    void printEmployeeDetails(){
        cout<<"Employee Name: "<< m_name<<" Employee age: "<<m_age<<"\n";
    }

};
int main(){
    Employee Frank{1,1.11};
    Frank.m_name = "Frank";
    Frank.m_age = 29;

    Frank.printEmployeeDetails();
    return 0;
}