/*
    The part (member) is part of the object (class)
    The part (member) can only belong to one object (class) at a time
    The part (member) has its existence managed by the object (class)
    The part (member) does not know about the existence of the object (class)
     a composition is the relationship between a person’s body and a heart

     Composition relationships are part-whole relationships where the part must constitute part of the whole object. For example, a heart is a part of a person’s body. The part in a composition can only be part of one object at a time. A heart that is part of one person’s body can not be part of someone else’s body at the same time.
    And finally, the part doesn’t know about the existence of the whole. Your heart operates blissfully unaware that it is part of a larger structure. We call this a unidirectional relationship, because the body knows about the heart, but not the other way around.
*/

#include <bits/stdc++.h>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }
};
int main(){
    
    return 0;
}