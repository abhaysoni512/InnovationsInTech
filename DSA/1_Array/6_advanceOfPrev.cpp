#include <iostream>

template <typename T, int size>
void reverseArray(T (&arr)[size])
{ // arr is a reference to an array
    for (int i = 0; i < size / 2; i++)
    {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

template <typename T, int size>
void printArray(T (&arr)[size])
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printArray(arr);
    reverseArray(arr);
    printArray(arr);
    
}   
