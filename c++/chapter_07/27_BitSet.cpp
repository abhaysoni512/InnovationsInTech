#include <iostream>
#include <bitset>
#include <iomanip>

int main()
{
    int num = 10;
    std::bitset<8> binary(num);

    // Ensure uniform output width by setting `std::setw` for each column and using `std::left` for alignment
    std::cout << std::left << std::setw(25) << "Binary representation:" << binary << std::endl;      // binary representation
    std::cout << std::left << std::setw(25) << "Bit set (0th index):" << binary.set(0) << std::endl; // Set bit at index 0
    std::cout << std::left << std::setw(25) << "Bit read (0th index):" << binary[0] << std::endl;    // Read bit at index 0
    std::cout << std::left << std::setw(25) << "Bit 3 has value: " << binary.test(3) << '\n';
    
    return 0;
}
