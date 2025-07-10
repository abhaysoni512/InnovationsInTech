#include <bits/stdc++.h>
using namespace std;
class Cents{
private:
    int m_cents{};
public:
    Cents(int cents):m_cents(cents){}
    Cents operator-() const;
    int getCents(){
        return m_cents;
    }
};
Cents Cents::operator-() const{
    return -m_cents;
}
int main()
{   
    Cents c1{10};
    cout<<-c1.getCents()<<endl;
    return 0;
}