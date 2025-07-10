#include <bits/stdc++.h>
using namespace std;
class Resource
{
private:
    
public:
    Resource();
    ~Resource();
};

Resource::Resource()
{
    cout<<"Resource aquired\n";
}

Resource::~Resource()
{
    cout << "Resource released\n";
}

//return weak pointer

std::weak_ptr<Resource> getWeakPtr()
{
    auto ptr{std::make_shared<Resource>()};
    return std::weak_ptr<Resource>(ptr);
}

// Returns a dumb pointer to an invalid object
Resource *getDumbPtr()
{
    auto ptr{std::make_unique<Resource>()};
    return ptr.get();
} // ptr goes out of scope, Resource destroyed

int main(){
    auto dumb{getDumbPtr()};
    std::cout << "Our dumb ptr is: " << ((dumb == nullptr) ? "nullptr\n" : "non-null\n");

    auto weak{getWeakPtr()};
    std::cout << "Our weak ptr is: " << ((weak.expired()) ? "expired\n" : "valid\n");
    return 0;
}