#include <iostream>
using namespace std;

int main(){
    int *ptr {new (std::nothrow) int{5}};
    if (ptr) {
        cout << "Value: " << *ptr << endl;
        delete ptr; // Free the allocated memory
    } else {
        cout << "Memory allocation failed." << endl;
    }
    return 0;
}