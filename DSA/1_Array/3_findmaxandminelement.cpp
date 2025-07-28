#include <iostream>
#include <string>

enum Type
{
    INVALID = std::numeric_limits<int>::min(),
    MAX,
    MIN
};

template <typename T, int size>
T maxormin(T arr[], Type s = INVALID)
{
    switch (s){
    case MAX:
    {
        T max = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
    case MIN:
    {
        T min = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }
    default:
        std::cout << "Invalid input :" ;
        return s; 
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << maxormin<int, 5>(arr, MAX) << std::endl;                   // Output: 5
    std::cout << maxormin<int, 5>(arr, MIN) << std::endl;                   // Output: 1
    std::cout << maxormin<int, 5>(arr, INVALID) << std::endl;               // Invalid input
    return 0;
}
