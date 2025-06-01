// std::vector has an explicit constructor (explicit std::vector<T>(std::size_t))
// that takes a single std::size_t value defining the length of the std::vector

#include <vector>
#include <iostream>

void passByreference(std::vector<int> &vec)
{
    std::cout << "Inside function passByreference() --------------------\n";
    for (int it : vec)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::cout << "Initializing vector of length --------------------\n";
    std::vector<int> vec(5);                        // vector of length 5
    std::vector<int> vec1(5, 10);                   // vector of length 5 with all elements initialized to 10
    std::vector<int> vec2{1, 2, 3, 4, 5};           // vector of length 5 with elements initialized to 1, 2, 3, 4, 5
    std::vector vec_char{'a', 'b', 'c', 'd', 'e'};  // vector of length 5 with elements initialized to 'a', 'b', 'c', 'd', 'e'
    std::vector vec_float{1.1, 2.2, 3.3, 4.4, 5.5}; // vector of length 5 with elements initialized to 1.1, 2.2, 3.3, 4.4, 5.5

    std::cout << "Acessing vector elements --------------------\n";
    std::cout << "vec[0] = " << vec[0] << '\n'; // 0

    std::cout << " using  at() function vec.at(0) = " << vec.at(0) << '\n'; // 0
#if 0
        std::cout << " using  at() function vec.at(5) = " << vec.at(5) << '\n'; // Will throw an exception
        // libc++abi: terminating due to uncaught exception of type std::out_of_range: vector
        //  using  at() function vec.at(5) = [1]    4390 abort      ./1_ConstructingVectorOfSpecificLength
#endif

    std::cout << " using  data() function vec.data()[0] = " << vec.data()[0] << '\n'; // 0

    std::cout << " Passing vector to function --------------------\n";
    std::vector<int> vec_prime{2, 3, 5, 7, 11}; // vector of length 5 with elements initialized to 2, 3, 5, 7, 11
    passByreference(vec_prime);                 // pass by reference
    return 0;
}