/*
    Stack:

        Function Name    | Stack Operation     |    Behavior                                 | Notes
        -----------------|---------------------|---------------------------------------------|-------------------
        push_back        | Push                | Adds an element to the top of the stack     | O(1) amortized
        pop_back         | Pop                 | Removes the top element from the stack      | O(1)
        top              | Peek                | Returns the top element of the stack        | O(1)
        empty            | Is Empty            | Checks if the stack is empty                | O(1)
        size             | Size                | Returns the number of elements in the stack | O(1)
        clear            | Clear               | Removes all elements from the stack         | O(n)
        capacity         | Capacity            | Returns the number of elements that can be  | O(1)
                                               | stored in the stack without reallocating 
                                               | memory
        back             | Back                | Returns the last element of the stack       | O(1)
        front            | Front               | Returns the first element of the stack      | O(1)
        emplace_back     | Emplace             | Constructs an element in place at the top   | O(1) amortized
                                               | of the stack
        reserve          | Reserve             | Reserves space for a specified number of    | O(n)
                                               | elements in the stack without changing its
                                               | size or capacity
        shrink_to_fit    | Shrink to Fit       | Reduces the capacity of the stack to fit its| O(n)
                                               | current size
        at               | At                  | Accesses the element at a specific index    | O(1)
                                               | (not typically used for stack operations)
*/

#include <iostream>
#include <vector>

using namespace std;

void printStack(const vector <int> &st){
    if(st.empty()) cout<< "Stack is empty \n";
    else{
        cout << "Stack elements : ";
        for(const auto &val: st) cout << val <<",";

        cout << "    \tStack Capacity : "<< st.capacity() <<" \tStack length : "<< st.size()<<endl;
    }
}
int main(){
    vector <int> stack{};

    printStack(stack);
    stack.push_back(10);
    printStack(stack);
    stack.push_back(20);
    printStack(stack);

    stack.push_back(30);
    printStack(stack);

    cout << "Top element of stack : " << stack.back() << endl;

    stack.pop_back();
    printStack(stack);
    stack.pop_back();
    printStack(stack);
    stack.pop_back();
    printStack(stack);
    return 0;
}