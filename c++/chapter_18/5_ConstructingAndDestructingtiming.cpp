#include <iostream>

class Time{
private:
    int m_id{};
public:
    Time(int id):m_id(id){
        std::cout<<"Constructing "<< m_id << " No"<<std::endl;
    }
    ~Time(){
        std::cout << "Desstructing " << m_id << " No" << std::endl;
    }
    
};

int main(){
    Time t1{1};

    Time *t2{new Time{2}};

    delete t2;
}