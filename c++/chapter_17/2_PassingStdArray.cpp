#include <array>
#include <iostream>

void passByRef(const std::array<int, 5> &arr) // we must explicitly specify <int, 5> here
{
    std::cout << arr[0] << '\n';
}
// Using function templates to pass std::array of different element types or lengths
template <typename T, std::size_t N>
void passByRefTemplate(const std::array<T, N> &arr){
    for(const auto &elem : arr) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}
// Auto non-type template parameters C++20
template <typename T, auto N>
void passByRefTemplateAuto(const std::array<T, N> &arr){
    for(const auto &elem : arr) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}
int main()
{
    std::array arr{9, 7, 5, 3, 1}; // CTAD deduces type std::array<int, 5>
    passByRef(arr);
    passByRefTemplate(arr); // Using function template to pass std::array
   

    std::array<double, 3> arr2{1.1, 2.2, 3.3}; // CTAD deduces type std::array<double, 3>
    passByRefTemplate(arr2); // Using function template to pass std::array with different type

    std::array arr3{1.11, 2.22, 3.33, 4.44, 5.55}; // CTAD deduces type std::array<double, 5>
    passByRefTemplate(arr3); // Using function template to pass std::array with different type and length

    passByRefTemplateAuto(arr); // Using function template with auto non-type template parameter

    return 0;
}