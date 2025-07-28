#include <iostream>

template <typename T>
bool swap(T &a, T &b)
{
    if (a == b)
        return false;
    T temp = a;
    a = b;
    b = temp;
    return true;
}

template <typename T, int size>
bool reverseArray(T arr[])
{
    if(size==0) return false;
    for(int i=0; i<size/2; i++){
        if(!swap(arr[i], arr[size-i-1])) continue;
    }
    return true;
}


template <typename T>
void printArray(T arr[], int size){
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    double arr[5]={1.1,2,3,4,1.1};
    if(!reverseArray<double,5>(arr)){
        std::cout<<"Array is empty"<<std::endl;
    }
    printArray(arr, 5);
}