#include <iostream>
using namespace std;


class Demo{
private:
   int *m_arr{};
   size_t m_length{};
public:
    Demo(size_t length) : m_length(length){
        m_arr = new int[m_length];
        cout<<"Costructor called\n";
    }
    ~Demo(){
        delete [] m_arr;
        cout << "Destructor called\n";
    }

};
int main(){
    Demo d1{10};
}