#include <iostream>
#include <iterator> // for std::size and std::ssize

int main(){
    char arr[20];
    std::cout << "Enter a string: ";
    std::cin.getline(arr, std::size(arr)); // Read a line of input into arr, ensuring it doesn't exceed the size of arr
    /*
     This call to cin.getline() will read up to 254 characters (including whitespace) into rolls.
     Any excess characters will be discarded.
     Because getline() takes a length, we can provide the maximum number of characters to accept. 
     */
    std::cout << "You entered: " << arr << '\n'; // Output the string entered by the user
    std::cout << "Size of arr: " << std::ssize(arr) << '\n'; // Display the size of the array
}