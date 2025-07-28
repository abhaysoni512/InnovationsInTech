#include <iostream>

template <typename T>
void printArray(T arr[],int size){
    for(int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    int arr[5] = {0};

    //how to calculate the size of an array
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);

    char Arr1[10] = {'a', 'b', 'c', 'd', 'e'};
    printArray(Arr1, 5);

    
    return 0;
}