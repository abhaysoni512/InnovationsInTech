struct Rectangle
{
    double length{};
    double width{};
};

int main()
{
    const Rectangle unit{1.0, 1.0};
    const Rectangle zero{}; // value-initialize all members
    const Rectangle two;  // value-initialize all members that's why it's working

    return 0;
}