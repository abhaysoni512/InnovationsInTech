#include <iostream>
#include <functional>
int main()
{
    int i{0};

    // Create a new lambda named count
    auto count{[i]() mutable
               {
                   std::cout << ++i << '\n';
               }};

    count(); // invoke count

    auto otherCount{std::ref(count)}; // create a copy of count

    // invoke both count and the copy
    count();
    otherCount();

    return 0;
}

/*
    Output

1
2
2
Rather than printing 1, 2, 3, the code prints 2 twice. When we created otherCount as a copy of count, we created a copy of count in its current state. 
count‘s i was 1, so otherCount‘s i is 1 as well.
 Since otherCount is a copy of count, they each have their own i.

 //to solve above problem use standard refernece

*/