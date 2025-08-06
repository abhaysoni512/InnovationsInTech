#include <bits/stdc++.h>
using namespace std;
class C_Queue
{
private:
    int m_size{};
    int m_front{0};
    int m_rear{0};
    int *m_data{};

public:
    C_Queue(int size) : m_size(size)
    {
        m_data = new int[m_size];
    }
    ~C_Queue()
    {
        delete[] m_data;
    }
    bool IsQueueFull(){
        if((m_rear+1)%m_size == m_front) return true;
        return false; 
    }
    bool IsQueueEmpty(){
        if((m_front=m_rear)==0) return true;
        return false;
    }
    bool enqueue(int x)
    {
        if (IsQueueFull())
        {
            cout << "C_Queue is full\n";
            return false;
        }
        m_rear = (m_rear+1)%m_size;
        m_data[m_rear] = x;
        return true;
    }
    bool dequeue()
    {
        if (IsQueueEmpty())
        {
            cout << "C_Queue is empty\n";
            return false;
        }
        m_front = (m_front+1)%m_size;
        m_data[m_front]=-1;
        return true;
    }

    void display()
    {
        for (int i{1}; i <= m_rear; i++)
        {
            cout << m_data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    C_Queue q(7);
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(22);
    q.display();
    return 0;
}