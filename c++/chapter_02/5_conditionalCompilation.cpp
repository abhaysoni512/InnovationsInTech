#include <iostream>

//Use of macro identifier without substituting text
#define PRINT_ABHAY

int main(){

    #ifdef PRINT_ABHAY
        std::cout<<"Abhay\n";
    #endif

    #ifdef PRINT_SONI
        std::cout << "Soni\n";
    #endif

    return 0;
}