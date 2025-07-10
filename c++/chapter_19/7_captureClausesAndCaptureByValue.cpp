#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
using namespace std;

int main(){
    constexpr array<string_view,6> Buckets = {"Red", "Blue", "Green", "Yellow", "Black", "White"};

    std::cout << "Enter a color: to search for in the buckets: ";
    string searchColor;
    cin >> searchColor;
    // Generic lambda to search for a color in the buckets
    auto foundColor{                            // variable 
        find_if(Buckets.begin(),Buckets.end(),[searchColor](const auto &str){
            return str.find(searchColor)!=string_view::npos;
        })
    };
    if(foundColor!=Buckets.end()){
        cout<<searchColor<<" Colour found\n";
    }else{
        cout << searchColor << " Colour  not found\n";
    }
    /*
        The capture clause is used to (indirectly) give a lambda access to variables available in the surrounding scope that it normally would not have access to.
        All we need to do is list the entities we want to access from within the lambda as part of the capture clause. 
        In this case, we want to give our lambda access to the value of variable search, so we add it to the capture clause:
    */

    /*
        When a lambda definition is executed, for each variable that the lambda captures, a clone of that variable is made (with an identical name) inside the lambda.
        These cloned variables are initialized from the outer scope variables of the same name at this point.
    */

    /*
        actually objects that can be called like functions (these are called functors).
        When the compiler encounters a lambda definition,
        it creates a custom object definition for the lambda. Each captured variable becomes a data member of the object.

        At runtime, when the lambda definition is encountered, the lambda object is instantiated, 
        and the members of the lambda are initialized at that point.
    */

    
    return 0;
}