#include <utility>
#include <iostream>
using namespace std;
int main(){
    pair<int, int> p1;
    p1 = make_pair(1, 2);
    cout << p1.first << " " << p1.second << endl;
    pair<int, int> p2(3, 4);
    cout << p2.first << " " << p2.second << endl;
    pair<int, int> p3 = {5, 6};
    cout << p3.first << " " << p3.second << endl;

    pair<int,pair<int, int>> p4 {7, {8, 9}};
    cout << p4.first << " " << p4.second.first << " " << p4.second.second << endl;

    pair <int,int> p5[]{{1, 2}, {3, 4}, {5, 6}};
    cout << p5[0].first << " " << p5[0].second << endl;
    cout << p5[1].first << " " << p5[1].second << endl;
    cout << p5[2].first << " " << p5[2].second << endl;
    cout << p5[0].first + p5[1].first + p5[2].first << " " << p5[0].second + p5[1].second + p5[2].second << endl;
}