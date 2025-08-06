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
        if(m_top == m_size-1){
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
    bool IsParathensisMatching(const string &infix){
    for(int i{};infix[i]!='\0';i++){
        if(infix[i]=='('){
            push(infix[i]);
        }else if(infix[i]==')'){
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
    // thought 1 : operand hai to postifix m dalnege wrna usee hum stack m daalenge
    bool IsOperand(const char x){
            if(x == '+' || x == '-' || x == '*' || x == '/'){
                return false;
            }
        return true;
    }
    // for codding we will think of precendece as per rule we need to push on stack abhi to bool kyuinki two types of symbol le rhe comparesion ke liye i.e (+-) // (*/)
    bool precendence(const char x){
        if(x=='+' || x =='-'){
            return false;            //0 means lower presendence
        }else{
            return true;              // 1 means higher presendence
        }
    }

    string convertToPostfix(string &infix){
        string postfix{};

        int i=0;
        while (infix[i]!='\0')
        {
            if(IsOperand(infix[i])){
                postfix.push_back(infix[i]);
                i++;
            }else{
                if(precendence(infix[i])>precendence(m_st[m_top])){
                    push(infix[i]);
                    i++;
                }else{
                    postfix.push_back(infix[i]);
                }
            }
        }
        while (IsStackEmpty())
        {
           postfix.push_back(pop()); 
        }
        return postfix;
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
    cout<< st.convertToPostfix(s)<<endl;
    return 0;
}