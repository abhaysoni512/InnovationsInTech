#include <iostream>

int main(){
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl; // Output: -1
    return 0;
}
