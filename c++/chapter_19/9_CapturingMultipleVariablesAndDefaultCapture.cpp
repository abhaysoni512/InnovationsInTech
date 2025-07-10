#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    std::array Areas {100,25,48,50,90};

    int width{};
    int height{};

    std::cout << "Enter width and height: ";
    std::cin >> width >> height;
    /*
        Having to explicitly list the variables you want to capture can be burdensome. 
        If you modify your lambda, you may forget to add or remove captured variables.
        Fortunately, we can enlist the compiler’s help to auto-generate a list of variables we need to capture.

        A default capture (also called a capture-default) captures all variables that are mentioned in the lambda. 
        Variables not mentioned in the lambda are not captured if a default capture is used.

        To capture all used variables by value, use a capture value of =.
        To capture all used variables by reference, use a capture value of &.


    */
    auto foundArea{
        find_if(Areas.begin(),Areas.end(),[&](int knownArea){
            return width*height != knownArea;
        })
    };
    if(foundArea!=Areas.end()){
        cout<<*foundArea<< " is known\n";
    }else{
        cout<<"Area is unknown\n";
    }

}