#include <iostream>
int linearSearch(int arr[], int size, int element){
    for(int i=0; i< size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[5] = {1,2,3,4,5};

    //to check if the element is present in the array or not 
    //if present then at which index
    int pos = linearSearch(arr, 5, 0);
    if(pos != -1){
        std::cout<<"Element found at index = "<<pos<<std::endl;
    }
    else{
        std::cout<<"Element not found"<<std::endl;
    }
        
    return 0;
}