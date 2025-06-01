#include <iostream>
#include <vector>

    #if 0
    void passByRef(const std::vector &arr) // compile error: CTAD can't be used to infer function parameters
    {
        std::cout << arr[0] << '\n';
    }

    int main()
    {
        std::vector primes{2, 3, 5, 7, 11}; // okay: use CTAD to infer std::vector<int>
        passByRef(primes);

        return 0;
    }

    Error : 2_CTADwithVecFunPar.cpp:12:5: error: no matching function for call to 'passByRef'
    12 |     passByRef(primes);
        |     ^~~~~~~~~
    2_CTADwithVecFunPar.cpp:4:6: note: candidate function not viable: no known conversion from 'std::vector<int>' to 'int &' for 1st argument
        4 | void passByRef(const std::vector &arr) // compile error: CTAD can't be used to infer function parameters
        |      ^         ~~~~~~~~~~~~~~~~~~~~~~
    2 errors generated.

    #endif

#if 0
//method 1
template <typename T>
void passByRef(const std::vector<T> &arr) // okay: use CTAD to infer std::vector<int>
{
    for(const auto it : arr)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}
#endif

//method 2
void passByRef(const auto &arr) // okay: use CTAD to infer std::vector<int>
{
    for(const auto it : arr)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector primes{2, 3, 5, 7, 11}; // okay: use CTAD to infer std::vector<int>
    passByRef(primes); // pass by reference
    std::vector primes1{2.12, 3.3, 5.0, 7.0, 11.0}; // okay: use CTAD to infer std::vector<double>
    passByRef(primes1); // pass by reference
    return 0;
}