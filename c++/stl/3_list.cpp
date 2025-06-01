#include <iostream>
#include <list>
using std::list;
int main()
{
    list<int> l1;
    l1.push_back(5);
    l1.push_back(6);
    l1.push_front(4);
    l1.push_front(3);
    // now, list is 3,4,5,6

    //delete the third element
    list<int>::iterator it = l1.begin();
    l1.erase(++(++it));
    
    
    
    //lets print the list
    /*
    for(auto i : l1){
        std::cout<<i<<" ";
    }
    */
    for(list<int>::iterator it = l1.begin(); it!=l1.end(); it++){
        std::cout<<*it<<" ";
    }

    return 0;
}