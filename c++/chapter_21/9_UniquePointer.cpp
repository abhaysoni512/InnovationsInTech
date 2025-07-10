#include <bits/stdc++.h>
#include <memory>       //std::unique_ptr
#include <utility>      //std::move
using namespace std;
class Resource{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};
int main(){
    std::unique_ptr<Resource> res1 {new Resource()};
    std::unique_ptr<Resource> res2{};

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    // // res2 = res1; // Won't compile: copy assignment is disabled
    // let's check std::move
    res2 = std::move(res1); //  res2 assumes ownership, res1 is set to null

    /*
        Because std::unique_ptr is designed with move semantics in mind, copy initialization and copy assignment are disabled. If you want to transfer the contents managed by std::unique_ptr, you must use move semantics. In the program above, we accomplish this via std::move (which converts res1 into an r-value, which triggers a move assignment instead of a copy assignment).
    */
    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");
    return 0;
}