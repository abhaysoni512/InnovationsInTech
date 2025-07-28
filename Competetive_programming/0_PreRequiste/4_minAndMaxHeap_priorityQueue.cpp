#include <iostream>
#include <queue>

using namespace std;

int main(){
    // Priority Queue
    // max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    cout << "Max Heap: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    cout << "Min Heap: ";
    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;

}