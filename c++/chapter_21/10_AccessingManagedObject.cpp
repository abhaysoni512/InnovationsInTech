#include <iostream>
#include <memory> // for std::unique_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

std::ostream &operator<<(std::ostream &out, const Resource &) 
{
    out << "I am a resource";
    return out;
}

int main()
{
    std::unique_ptr<Resource> res{new Resource{}};

    if (res)                       // use implicit cast to bool to ensure res contains a Resource
        std::cout << *res << '\n'; // print the Resource that res is owning note: in orfer to access Resource object through res we are using *res

    return 0;
}