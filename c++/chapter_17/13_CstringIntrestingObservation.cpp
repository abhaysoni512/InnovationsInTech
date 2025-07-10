#include <iostream>

int main()
{
    int narr[]{9, 7, 5, 3, 1};
    char carr[]{"Hello!"};
    const char *ptr{"Alex"};

    std::cout << narr << '\n'; // narr will decay to type int*
    std::cout << carr << '\n'; // carr will decay to type char*
    std::cout << ptr << '\n';  // name is already type char*
    /*The answer is that the output streams (e.g. std::cout) make some assumptions about your intent.
    If you pass it a non-char pointer, it will simply print the contents of that pointer (the address that the pointer is holding).
     However, if you pass it an object of type char* or const char*, it will assume you’re intending to print a string*/

    char c{'Q'};
    std::cout << &c;
    /*
    On the author’s machine, this printed :

        Q╠╠╠╠╜╡4¿■A
    */
    std::cout << std::endl
              << (int *)&c << '\n';

    /*
        Why did it do this? Well, first it assumed &c (which has type char*) was a C-style string.
        So it printed the ‘Q’, and then kept going. Next in memory was a bunch of garbage.
        Eventually, it ran into some memory holding a 0 value, which it interpreted as a null terminator, so it stopped.
         What you see may be different depending on what’s in memory after variable c.
    */
    return 0;
}