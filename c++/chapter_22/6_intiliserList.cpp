/*
    std::initializer_list lives in the <initializer_list> header.

    There are a few things to know about std::initializer_list. Much like std::array or std::vector, you have to tell std::initializer_list what type of data the list holds using angled brackets, unless you initialize the std::initializer_list right away. Therefore, you’ll almost never see a plain std::initializer_list. Instead, you’ll see something like std::initializer_list<int> or std::initializer_list<std::string>.

    Second, std::initializer_list has a (misnamed) size() function which returns the number of elements in the list. This is useful when we need to know the length of the list passed in.

    Third, std::initializer_list is often passed by value. Much like std::string_view, std::initializer_list is a view. Copying a std::initializer_list does not copy the elements in the list.


*/

#include <iostream>
#include <initializer_list>
#include <cassert>
#include <algorithm>

using namespace std;

class IntArray {
private:
    int m_length{};
    int *m_data{};
public:
    IntArray() = default;
    IntArray(int length) : m_length(length), m_data(new int[length]{}) {
        assert(length >= 0);
    }

    IntArray(std::initializer_list<int> list): IntArray(static_cast<int>(list.size())){
        std::copy(list.begin(),list.end(),m_data);
    }

    ~IntArray(){
        delete []m_data;
    }

    IntArray(const IntArray &) = delete;                // to avoid shallow copies
    IntArray &operator=(const IntArray &list) = delete; // to avoid shallow copies

    int& operator[](int index){
        return m_data[index];
    }

    int getSize(){
        return m_length;
    }
};

int main(){
    IntArray arr{11,22,33,44,55};
    for(int i = 0; i<arr.getSize();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}