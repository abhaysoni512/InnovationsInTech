#include <bits/stdc++.h>
using namespace std;

class Stack{
private:
    int m_size{};   // to store size
    int m_top{};    // m_to
    char *m_st{};
public:
    Stack(int size):m_size(size){
        m_top = -1;
        m_st = new char[m_size];
        cout<<"Created a stack of size "<<m_size <<"\n";;
    }
    ~Stack(){
        delete [] m_st;
        cout<<"Deleted stack\n";
    }

    bool push(const char &x){
        if(m_top == m_size-1) {
            cout<<"Stack is full\n";
            return false;
        }
        m_st[++m_top]=x;
        return true;
    }
    char pop(){
        char x = '\0';
        if(m_top == -1) {
            cout<<"Stack is empty\n";
            return x;
        }
        x = m_st[m_top--];
        return x;
    }
    bool IsStackEmpty(){
        if(m_top==-1) return true;
        return false;
    }
    bool IsParathensisMatching(const string &str){
    for(int i{};str[i]!='\0';i++){
        if(str[i]=='('){
            push(str[i]);
        }else if(str[i]==')'){
            if(!IsStackEmpty()){
                pop();
            }
            else{
                return false;
            }
        }
    }
    return IsStackEmpty()?true:false;
}

};


int main(){
  
 
    Stack st(10);
    string s;
    cin>>s;
    if(st.IsParathensisMatching(s)){
        cout<<s<<" is valid paraenthesis \n";
    }else{
        cout<<s<<" isn't valid paraenthesis \n";
    }
    return 0;
}