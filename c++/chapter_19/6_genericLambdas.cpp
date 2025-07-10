#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
using namespace std;

int main(){
    constexpr std::array months = {"January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December"};
    // Generic lambda to print the month names

    // Search for two consecutive months that start with the same letter.
    const auto sameLetter{std::adjacent_find(months.begin(), months.end(),
                                             [](const auto &a, const auto &b) // Generic lamda as using auto
                                             {
                                                 return a[0] == b[0];
                                             })};

    // Make sure that two months were found.
    if (sameLetter != months.end())
    {
        // std::next returns the next iterator after sameLetter
        std::cout << *sameLetter << " and " << *std::next(sameLetter)
                  << " start with the same letter\n";
    }
    else{
        std::cout << "Not found\n";
    }
    
}