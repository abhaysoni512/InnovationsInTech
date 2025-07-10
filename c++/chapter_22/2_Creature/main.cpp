#include <bits/stdc++.h>

#include "Creature.h"
using namespace std;

int main(){
    string Creature_name;
    cout<<"Enter Creature name: ";
    cin>>Creature_name;

    Creature creature{Creature_name,{4,7}};

    while(1){
        // print name and location of creature
        std::cout<<creature;

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x{0};
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y{1};
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x,y);
    }
    cout<<"Program finished\n";

    return 0;
}