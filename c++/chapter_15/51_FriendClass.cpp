#include <iostream>
using namespace std;

class Storage{
private:
    int m_value1{};
    int m_value2{};
public:
    Storage(int value1, int value2) : m_value1(value1), m_value2(value2) {}

    // Declare the friend class
    friend class Display;

};

class Display{
private:
    // Private members of Display can be added here if needed
    
public:
    // Friend function to display the values of Storage
    void showValues(const Storage &storage) {
        cout << "Value 1: " << storage.m_value1 << ", Value 2: " << storage.m_value2 << endl;
    }
};
int main() {
    Storage storage(10, 20);
    Display display;

    // Call the friend function to show values
    display.showValues(storage);

    return 0;
}