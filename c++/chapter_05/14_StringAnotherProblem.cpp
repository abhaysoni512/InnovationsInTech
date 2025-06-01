#include <iostream>
#include <string>

int main()
{
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice; // After user select choice 1 or 2 by pressing enter then enter will be treated as "\n"
                        // new line character . to tackle it use - std::cin.ignore()
    
    std::cin.ignore(); //
                
    std::cout << "Now enter your name: ";
    std::string name{};
    std::getline(std::cin, name); // note: no std::ws here

    std::cout << "Hello, " << name << ", you picked " << choice << '\n';

    return 0;
}