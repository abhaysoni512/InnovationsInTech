// Nested type also known as member type
#include <iostream>

class Fruit
{
public:
    enum Type
    {
        Apple,
        Banana,
        Orange
    };

private:
    Type m_type;

public:
    Fruit(Type type) : m_type(type)
    {
    }

    void printType() const
    {
        switch (m_type)
        {
        case Type::Apple:
            std::cout << "Apple" << std::endl;
            break;
        case Type::Banana:
            std::cout << "Banana" << std::endl;
            break;
        case Type::Orange:
            std::cout << "Orange" << std::endl;
            break;
        }
    }

    Type getType() const
    {
        return m_type;
    }
    void setType(Type type)
    {
        m_type = type;
    }
    bool isApple() const
    {
        return m_type == Apple;
    }
};

int main()
{
    Fruit apple(Fruit::Apple);
    if (apple.isApple())
    {
        std::cout << "This is an apple." << std::endl;
    }
    else
    {
        std::cout << "This is not an apple." << std::endl;
    }

    return 0;
}
