#include <iostream>
#include <list>
using std::list;
void displayPlayers(std::string title, list<int> players){
    std::cout<<title<<": ";
    for(list<int>::iterator it = players.begin(); it!=players.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    list<int> allPlayers = {1,2,6,7,5,4,3,8,9,10};
    list<int> begginers; // rating 1-5
    list<int> proplayer; // rating 6-10

    for(list<int> :: iterator it = allPlayers.begin(); it!=allPlayers.end(); it++){
        if(*it<=5){
            begginers.push_back(*it);
        }else{
            proplayer.push_back(*it);
        }
    }
    displayPlayers("All Players",allPlayers);
    displayPlayers("Begginers",begginers);
    displayPlayers("Pro Players",proplayer);
    


}