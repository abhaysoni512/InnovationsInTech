#include <iostream>

using namespace std;

// A friend function is a function (member or non-member) that can access the private and protected members of a class as though 
// it were a member of that class. In all other regards, the friend function is a normal function.

class Accumulator {
private:
    int m_sum {0};
public:

    void add(int &value) {
        m_sum += value;
    }
    // Declare a non-member function as a friend of this class
    friend void printSum(const Accumulator &acc);
};

// Non-member function that can access private members of Accumulator
void printSum(const Accumulator &acc) {
    cout << "Sum: " << acc.m_sum << endl;
}

int main(){
    Accumulator acc;
    int value1 = 10;
    int value2 = 20;

    acc.add(value1);
    acc.add(value2);

    // Call the friend function to print the sum
    printSum(acc);

    return 0;
}