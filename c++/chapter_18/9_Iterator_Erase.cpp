#include <bits/stdc++.h>
using namespace std;

int main(){
    vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto it{v.begin()}; // Iterator to the first element
    ++it;
    cout<<"2nd element: "<<*it<<endl; // Output: 2nd element: 2
    it = v.erase(it); // Erase the 2nd element and get an iterator to the next element
    cout<<"After erasing 2nd element, iterator points to: "<<*it<<endl; // Output: After erasing 2nd element, iterator points to: 3
    
    return 0;
}