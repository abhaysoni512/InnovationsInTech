struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee frank = {1, 32, 60000.0}; // copy-list initialization using braced list
    Employee joe{2, 28, 45000.0};      // list initialization using braced list (preferred)
    Employee alice(1,33,60000.0);      // direct initialization using parentheses
    // We recommend avoiding this last form as much as possible,
    // as it doesn’t currently work with aggregates that utilize brace elision (notably std::array).

    return 0;
}