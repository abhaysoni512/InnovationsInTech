#include <iostream>

enum class Pet
{
    cat,  // assigned 0
    dog,  // assigned 1
    pig,  // assigned 2
    whale // assigned 3
};

// Function to handle a Pet enum as a parameter
void printPet(Pet pet)
{
    switch (pet)
    {
    case Pet::cat:
        std::cout << "You selected a cat!" << std::endl;
        break;
    case Pet::dog:
        std::cout << "You selected a dog!" << std::endl;
        break;
    case Pet::pig:
        std::cout << "You selected a pig!" << std::endl;
        break;
    case Pet::whale:
        std::cout << "You selected a whale!" << std::endl;
        break;
    default:
        std::cout << "Unknown pet!" << std::endl;
        break;
    }
}

int main()
{
    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=whale): ";

    int input{};
    std::cin >> input; // input an integer

    // Cast the input integer to the Pet enum type
    Pet pet = static_cast<Pet>(input);

    // Call the function with the Pet enum
    printPet(pet);

    return 0;
}
