#include <iostream>
#include <array>
template <typename T, auto S>
void getFilledarr(std::array <T,S> &arr){
    int index{0};
    std::cout<<"Enter "<<S <<" elements:\n";
    
    while(index<S){
        std::cin>>arr[index];
        index++;
    }
} 

int main()
{
    std::array <int , 5> arr{};
    getFilledarr(arr);
    for(const auto &elem : arr){
        std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
}