#include <iostream>
#include <string_view>

int main()
{
    // we can use str.remove_prefix(i) by using string_view without modifying original string and not copying we had extracted one letter
    std::string_view str{"Peach"};
    std::cout << str << '\n';

    // Remove 1 character from the left side of the view
    str.remove_prefix(1);
    std::cout << str << '\n';

    // Remove 2 characters from the right side of the view
    str.remove_suffix(2);
    std::cout << str << '\n';

    str = "Peach"; // reset the view
    std::cout << str << '\n';

    return 0;
}