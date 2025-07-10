// let's cover shallow copy and it's problem

#include <bits/stdc++.h>
using namespace std;
class Mystring{
private: 
    char * m_data{};
    int m_length{};
public:
    Mystring(const char *str =""){
        m_length = strlen(str) + 1;

        m_data = new char[m_length];

        for(int i{0};i<m_length;i++){
            m_data[i]=str[i];
        }
    }
    ~Mystring(){
        if(m_data == nullptr)
            return;
        cout << "Destructor called for " << m_data << endl;
        delete [] m_data;
        m_data = nullptr; // Avoid dangling pointer
    }
    int* getAddress(){
        return reinterpret_cast<int*>(m_data);
    }
    

};
int main(){

    Mystring s1{"Abhay"};
    Mystring s2{s1};
    cout << "s1 address: " << s1.getAddress() << endl;
    cout << "s2 address: " << s2.getAddress() << endl;
    
    return 0;
}