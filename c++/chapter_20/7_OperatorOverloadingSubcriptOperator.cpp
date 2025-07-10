#include <bits/stdc++.h>
using namespace std;
class ArrayBucket{
private:
    int m_arr[10]{};
public:
    int *getArrayBucket(){return m_arr;}

    void printArray(){
        cout << "Array: ";
            for (int i{0}; i < 10; i++){
                cout<<m_arr[i]<<" ";
            }
            cout << endl;
    }
    // best way we can overload a operator
    int &operator[](int index){
        return m_arr[index];
    }
};
int main(){
    ArrayBucket arr{};
    for(int i{0};i<10;i++){
        arr.getArrayBucket()[i]=i;
    }
    arr.printArray();
    arr[5] = 10;
    cout<<arr[5]<<endl;
    return 0;
}