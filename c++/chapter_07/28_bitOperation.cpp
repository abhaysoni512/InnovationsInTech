#include <iostream>
#include <bitset>

int main()
{
    std::bitset<4> b1(0b0110);
    std::bitset<4> b2(0b0111);

    std::bitset<4> result = b1 | b2; // Perform bitwise OR operation
    std::cout << b1 << " || " << b2 << " = " << result << std::endl;

    return 0;
}
