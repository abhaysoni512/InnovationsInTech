#include <cassert>
#include <iostream>

bool issmallVowel(char ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }

}

int unitTest(){
    assert(issmallVowel('a') == true);
    assert(issmallVowel('b') == false);
    assert(issmallVowel('c') == false);
    assert(issmallVowel('d') == false);
    assert(issmallVowel('e') == true);
    assert(issmallVowel('f') == false);
    assert(issmallVowel('g') == false);
    assert(issmallVowel('h') == false);
    assert(issmallVowel('i') == true);
    assert(issmallVowel('j') == false);
    assert(issmallVowel('k') == false);
    assert(issmallVowel('l') == false);
    assert(issmallVowel('m') == false);
    assert(issmallVowel('n') == false);
    assert(issmallVowel('o') == true);
    assert(issmallVowel('p') == false);
    assert(issmallVowel('q') == false);
    assert(issmallVowel('r') == false);
    assert(issmallVowel('s') == false);
    assert(issmallVowel('t') == false);
    assert(issmallVowel('u') == true);
    assert(issmallVowel('v') == false);
    assert(issmallVowel('w') == false);
    assert(issmallVowel('x') == false);
    assert(issmallVowel('y') == false);
    assert(issmallVowel('z') == false);
    return 0;
}

int main()
{
    
    unitTest();
    std::cout << "All tests passed\n";
    return 0;
}