#include <bits/stdc++.h>
using namespace std;
class Person
{
private:
    string m_name{};
    weak_ptr<Person> m_person{};
public:
    Person(std::string_view name);
    ~Person();
    friend void partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2){
        p1 -> m_person = p2;
        p2-> m_person = p1;
        cout<<p1->m_name<<" is partnered with "<<p2->m_name<<endl;
    }

    std::shared_ptr<Person> getPartner() const {
        return m_person.lock();
    }

    const std::string_view getName() const
    {
        return m_name;
    }
};

Person::Person(std::string_view name):m_name(name)
{
    cout<<m_name <<" person has been created\n";

}

Person::~Person()
{
    cout<<m_name<<" person has been deleted\n";
}

int main(){

    auto lucky {std::make_shared<Person>("Lucky")};
    auto ricky { std::make_shared<Person>("Ricky") };

    partnerUp(lucky, ricky);


    auto ptr = ricky->getPartner();

    std::cout<<ricky->getName()<<"'s name is : "<<ptr->getName()<<" \n";
    return 0;
}