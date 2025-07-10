
#include <bits/stdc++.h>
#include <mdspan>

using namespace std;
bool containsNut(const std::string_view& str){
    return (str.find("nut") == std::string_view::npos) ? false : true;
}
int main(){
    // std::string::npos is a constant representing the largest possible value for size_t
    // It is often used to indicate that a substring was not found in a string.
    constexpr std::array<std::string_view, 3> arr = {"apple", "banana", "nut"};

    auto found { find_if(arr.begin(), arr.end(), containsNut)};
    if (found != arr.end()) {
        cout << "Found a string containing 'nut': " << *found << '\n';
    } else {
        cout << "No string containing 'nut' found.\n";
    }

    // Now, let's study the lambda function
    // A lambda expression (also called a lambda or closure) allows us to define an anonymous function inside another function. 
    // The nesting is important, as it allows us both to avoid namespace naming pollution, and to define the function as close to where it is used as possible (providing additional context).
    // The syntax for a lambda expression is:
    // [capture](parameters) -> return_type { body }
    // where:
    // - capture: specifies which variables from the surrounding scope are accessible inside the lambda.
    // - parameters: the input parameters for the lambda, similar to a regular function.
    // - return_type: the type of value the lambda returns (optional, can be inferred
    // - body: the code that defines what the lambda does.

    auto foundLambda{
       std::find_if(arr.begin(), arr.end(), [](const std::string_view& str) {
           return str.find("nut") != std::string_view::npos; // Check if "nut" is found in the string
       })
    };
    if (foundLambda != arr.end()) {
        cout << "Found a string containing 'nut' using lambda: " << *foundLambda << '\n';
    } else {
        cout << "No string containing 'nut' found using lambda.\n";
    }

    // In actuality, lambdas aren’t functions (which is part of how they avoid the limitation of C++ not supporting nested functions).
    // They’re a special kind of object called a functor.
    // Functors are objects that contain an overloaded operator() that make them callable like a function.
    // Although we don’t know the type of a lambda, there are several ways of storing a lambda for use post-definition.
    // If the lambda has an empty capture clause (nothing between the hard brackets []), we can use a regular function pointer. 
    // std::function or type deduction via the auto keyword will also work (even if the lambda has a non-empty capture clause).

    // exampple 1 using regular function pointer
    double (*addNumhers)(double, double) {
        [](double a, double b) {
            return a + b;
        }
    };
    cout << "Sum of 3.5 and 2.5 using function pointer: " << addNumhers(3.5, 2.5) << '\n';

    // example 2 using std::function
    std::function<double(double, double)> addNumbersFunc = [](double a, double b) {       //prior to C++ 17
        return a + b;
    };
    cout << "Sum of 4.5 and 1.5 using std::function: " << addNumbersFunc(4.5, 1.5) << '\n';

    // example 2 .1  using std::function
    std::function addNumbersFunc1{
        [](double a, double b) {       // C++ 17 onwards
            return a + b;
        }
    };
    cout << "Sum of 5.5 and 2.5 using std::function: " << addNumbersFunc1(5.5, 2.5) << '\n';

    // using auto
    auto addNumbersFunc2{
        [](double a, double b){
            return a+b;
        }
    };
    cout << "Sum of 5.5 and 2.5 using std::function: " << addNumbersFunc2(6.5, 2.5) << '\n';

    // Generic Lambdas :
    // For the most part, lambda parameters work by the same rules as regular function parameters.
    // One notable exception is that since C++14 we’re allowed to use auto for parameters
    // (note: in C++20, regular functions are able to use auto for parameters too). 
    // When a lambda has one or more auto parameter, the compiler will infer what parameter types are needed from the calls to the lambda.
    //Because lambdas with one or more auto parameter can potentially work with a wide variety of types, they are called generic lambdas.
    return 0;
}
