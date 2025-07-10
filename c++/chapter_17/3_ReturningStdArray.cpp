/*
    passing a std::array to a function is conceptually simple -- pass it by (const) reference.
    But what if we have a function that needs to return a std::array?
    Things are a little more complicated. Unlike std::vector, std::array is not move-capable,
    so returning a std::array by value will make a copy of the array. The elements inside the array will be moved if they are move-capable,
    and copied otherwise.

    Returning a std::array by value:

    It is okay to return a std:array by value when all of the following are true:

    -   The array isn’t huge.
    -   The element type is cheap to copy (or move).
    -   The code isn’t being used in a performance-sensitive context.
*/

#include <array>
#include <iostream>

template <typename T, auto S>
std::array <T,S> get_Arr(){
    std::array <T,S> arr{};
    size_t index{0};
    while(index<S){
       std::cin>>arr[index];
        index++;
    }
    return arr;
}
int main(){
    std::array <int , 5> arr {get_Arr<int,5>()};
    for(const auto &element : arr){
        std::cout<<element<<" ";
    }
    std::cout<<"\n";
}