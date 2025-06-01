#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
void printElement3(const std::vector<T> &arr)
{
    std::cout << "Inside function printElement3() --------------------\n";
    assert(arr.size() == 5); // assert that the size of the vector is 5
    for (const auto it : arr)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector arr{9, 7, 5, 3, 1};
    printElement3(arr);

    return 0;
}