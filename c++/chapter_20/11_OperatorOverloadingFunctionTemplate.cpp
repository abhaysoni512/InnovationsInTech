#include <bits/stdc++.h>
using namespace std;
class Cents{
private:
    int m_cents{};
public:
    Cents(int cents): m_cents(cents){}
    friend bool operator>(const Cents &c1, const Cents &c2){
        return c1.m_cents > c2.m_cents;
    }
    friend ostream& operator<< (ostream &ostr, const Cents &c){
        return ostr<<c.m_cents;
    }
};
template <typename T>
const T& max1(const T& x, const T& y){
    return (x>y)?x:y;
}
int main(){
    Cents nickle{5};
    Cents ounce {10};
    Cents whoIsBigger{max1(nickle,ounce)};
    cout<<whoIsBigger<<endl;
    return 0;
}