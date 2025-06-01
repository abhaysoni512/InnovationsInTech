#include <iostream>
#include <string>

class Yogurt
{
    std::string m_flavor{"vanilla"};

public:
    void setFlavor(std::string_view flavor)
    {
        m_flavor = flavor;
    }

    const std::string &getFlavor() const { return m_flavor; }
};

// Best: non-member function print() is not part of the class interface
const void print(const Yogurt &y)
{
    std::cout << "The yogurt has flavor " << y.getFlavor() << '\n';
}

int main()
{
    Yogurt y{};
    y.setFlavor("cherry");
    print(y);

    return 0;
}