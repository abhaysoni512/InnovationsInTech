#include <bits/stdc++.h>
using namespace std;

class Stack{
private:
    int m_size{};   // to store size
    int m_top{};    // m_to
    int *m_st{};
public:
    Stack(int size):m_size(size){
        m_top = -1;
        m_st = new int[m_size];

        cout<<"Created a stack of size "<<m_size <<"\n";;
    }
    ~Stack(){
        delete [] m_st;
        cout<<"Deleted stack\n";
    }

    bool push(const int &x){
        if(m_top == m_size-1) {
            cout<<"Stack is full\n";
            return false;
        }
        m_st[++m_top]=x;
        return true;
    }
    int pop(){
        int x = -1;
        if(m_top == -1) {
            cout<<"Stack is empty\n";
            return x;
        }
        x = m_st[m_top--];
        return x;
    }
    // we will have position from user it starts from top
    int peek(const int &pos) const{
        int index = m_top - pos +1;
        if(index<0 || index >m_size){
            cout << "Enter a valid index\n";
        }
        return m_st[index];
    }

};

int main(){
  
    Stack st(10);
    st.push(11);
    st.push(22);
    st.push(33);
    cout<<"1st position element on stack : "<<st.peek(1)<<endl;
    st.peek(1111);
    return 0;
}