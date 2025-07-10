#include <iostream>
using namespace std;

class Storage; // Forward declaration of Storage class

class Display
{
private:
    // Private members of Display can be added here if needed
    int x = 10;
    
public:
    // Friend function to display the values of Storage
    void showValues(const Storage &storage);
};

class Storage
{
private:
    int m_value1{};
    int m_value2{};

public:
    Storage(int value1, int value2) : m_value1(value1), m_value2(value2) {}

    // instead of making the entire class a friend, we can make a specific member function a friend
    /*
        friend void Display::showValues(const Storage &storage);
        this won't work because the Display class is not defined yet.
        There is two ways to fix this:
        1. Forward declaration of the Display class:
        2. Declare the Display class before the Storage class.
    */
    friend void Display::showValues(const Storage &storage); // Declare the showValues function as a friend of Storage
};

void Display::showValues(const Storage &storage)
{
    cout << "Value 1: " << storage.m_value1 << ", Value 2: " << storage.m_value2 << endl;
}
int main()
{
    Storage storage(10, 20);
    Display display;

    // Call the friend function to show values
    display.showValues(storage);

    return 0;
}
