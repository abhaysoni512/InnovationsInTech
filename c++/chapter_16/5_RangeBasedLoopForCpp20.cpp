#include <iostream>
#include <vector>
#include <ranges> // C++20 header for ranges

int main(){
    std::vector<std::string_view> words{"hello", "world", "C++", "ranges"};
    // Using a range-based for loop with C++20 ranges
    for(const auto &word: std::views::reverse(words)){
        std::cout << word << " ";
    }
    std::cout << std::endl;
}