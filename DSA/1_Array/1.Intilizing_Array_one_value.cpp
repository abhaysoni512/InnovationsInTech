// Problem Statement: Write a program to initialize an array with one value and print the value.
#include <iostream>
#include <algorithm>

int main(){
    //Initialize an array with one value
    int arr[5] = {0};
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    //Fill the array with one value
    std::fill(arr, arr+5, 5);
    for(int i=0; i<5; i++){
        std::cout<<arr[i]<<" ";
    }
}