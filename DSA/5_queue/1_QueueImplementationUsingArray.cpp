#include <bits/stdc++.h>
using namespace std;
class Queue{
private:
    int m_size{};
    int m_front{-1};
    int m_rear{-1};
    int *m_data{};
public:
    Queue(int size):m_size(size){
        m_data = new int[m_size];
    }
    ~Queue(){
        delete [] m_data;
    }
    bool enqueue(int x){
        if(m_rear==m_size-1) {
            cout<<"Queue is full\n";
            return false;
        }
        m_rear++;
        m_data[m_rear] = x;
        return true;
    }
    bool dequeue(){
        if(m_front==m_rear){
            cout<<"Queue is empty\n";
            return false;
        }
        m_front++;
        return true;
    }

    void display(){
       for(int i{};i<=m_rear;i++){
        cout<<m_data[i]<<" ";
       } 
       cout<<endl;
    }
    
};
int main(){
    Queue q(7);
    q.enqueue(5);
    q.display();
    return 0;
}