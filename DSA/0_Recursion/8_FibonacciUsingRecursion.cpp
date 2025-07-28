#include <bits/stdc++.h>
#include <functional>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
        return 1;
    }
    /*
        1. function<int(int)> fibonacci
        function<int(int)> is a type from the C++ Standard Library,
        specifically the std::function template (available in the <functional> header).
        It describes a callable object that:
        Takes an int as input (the (int) part).
        Returns an int (the int before the parentheses).
        Here, fibonacci is a variable of this type,
        meaning it can store any function-like object (like a lambda) that matches this signature.
    2. Lambda Function: [&](int n) -> int { ... }
        A lambda function is a way to define a small, anonymous function directly in your code.
        Let’s dissect the lambda syntax:
        [&]: This is the capture clause. It tells the lambda to capture variables from the surrounding scope by reference. In this case, it captures fibonacci itself, which is necessary for recursion (more on that later).
        (int n): The lambda takes an integer parameter n.
        -> int: This specifies that the lambda returns an int. (The -> int is optional here since the return type can be deduced, but it’s included for clarity.)
        { ... }: The body of the lambda contains the logic:
        if (n == 0) return 0; — Base case 1.
        if (n == 1) return 1; — Base case 2.
        return fibonacci(n - 1) + fibonacci(n - 2); — Recursive case.
    3. Recursion:
        The lambda function calls itself recursively to compute the Fibonacci number.
        This is possible because of the capture clause [&], which allows the lambda to refer to itself by name (fibonacci).
        The recursion continues until it reaches one of the base cases (n == 0 or n == 1).
    4. Usage:

    */
    function<int(int)> fibonacci = [&](int n) -> int {
        if(n<= 1) return n; // Base case: if n is 0 or 1, return n
        return fibonacci(n - 1) + fibonacci(n - 2);
    };
    return 0;
}
#if 0
Below is a detailed explanation of the page at 
https://en.cppreference.com/w/cpp/utility/functional/function.html, which covers the `std::function` template in C++. This explanation is designed to be clear, comprehensive, and well-structured, breaking down the key concepts and components of `std::function` for easier understanding.

---

## Explanation of `std::function` in C++

The page at https://en.cppreference.com/w/cpp/utility/functional/function.html is a reference for the `std::function` template, which is part of the C++ Standard Library's `<functional>` header. `std::function` is a powerful and versatile tool that allows you to **store**, **copy**, and **invoke** any callable entity—such as regular functions, lambda expressions, or function objects—in a uniform way. It is particularly useful in scenarios like implementing callbacks, storing functions in containers, or passing functions as arguments to other functions.

---

### What is `std::function`?

`std::function` is a **function object wrapper** that can hold any callable entity as long as it matches a specific **function signature**.
 A function signature defines the return type and parameter types of the callable. For example:
- `std::function<int(int, int)>` can hold any callable that takes two integers and returns an integer.
- `std::function<void()>` can hold any callable that takes no arguments and returns nothing.

In essence, `std::function` provides a standardized way to treat different types of callables uniformly, enhancing flexibility in your C++ code.

---

### Key Concepts

#### 1. **Function Objects**
A **function object** (or **functor**) is an object that can be called like a function. In C++, this is achieved by overloading the `operator()` in a class. For example:

```cpp
struct Add {
    int operator()(int a, int b) { return a + b; }
};
```

Here, `Add` is a function object that can be called as `Add()(3, 4)`, returning `7`.

#### 2. **Callable Entities**
`std::function` can store various types of **callable entities**, including:
- **Regular functions**: e.g., `int add(int, int)`.
- **Lambda expressions**: e.g., `[&](int a, int b) { return a + b; }`.
- **Function objects**: e.g., instances of classes with `operator()`.
- **Bind expressions**: e.g., results from `std::bind`.

#### 3. **Type Erasure**
`std::function` uses **type erasure**, a technique that allows it to store different types
 of callables without needing to know their exact types, as long as they match the specified signature. This is implemented using polymorphism internally, making `std::function` highly flexible.

---

### Declaration and Template Parameters

The `std::function` template is declared as:


```cpp
template <class R, class... Args>
class function<R(Args...)>;
```

- **`R`**: The return type of the function.
- **`Args...`**: The parameter types of the function (variadic, meaning zero or more).

Examples:
- `std::function<int(int, int)>`: A callable that takes two `int`s and returns an `int`.
- `std::function<void(std::string)>`: A callable that takes a `std::string` and returns nothing.

---

### Creating and Using `std::function`

You can create a `std::function` object by assigning it a callable that matches its signature. Here are some examples:

#### Example 1: Storing a Regular Function

```cpp
#include <functional>
#include <iostream>

int add(int a, int b) { return a + b; }

int main() {
    std::function<int(int, int)> func = add;
    std::cout << func(3, 4) << std::endl;  // Outputs 7
    return 0;
}
```

#### Example 2: Storing a Lambda Expression

```cpp
#include <functional>
#include <iostream>

int main() {
    std::function<int(int, int)> func = [](int a, int b) { return a + b; };
    std::cout << func(3, 4) << std::endl;  // Outputs 7
    return 0;
}
```

#### Example 3: Storing a Function Object

```cpp
#include <functional>
#include <iostream>

struct Multiply {
    int operator()(int a, int b) { return a * b; }
};

int main() {
    std::function<int(int, int)> func = Multiply();
    std::cout << func(3, 4) << std::endl;  // Outputs 12
    return 0;
}
```

---

### Key Features and Behaviors

#### 1. **Empty State**
A `std::function` object can be **empty**, meaning it doesn’t hold any callable. If you attempt to call an empty `std::function`, it throws a `std::bad_function_call` exception. You can check if it’s empty using the `bool` operator:

```cpp
std::function<int(int)> func;  // Empty by default
if (!func) {
    std::cout << "Function is empty" << std::endl;
}
```

#### 2. **Assignment and Swapping**
- You can assign a new callable to a `std::function` object at any time.
- It supports swapping with another `std::function` using the `swap` member function or the non-member `std::swap`.

#### 3. **Target Type**
- The `target_type()` member function returns a `std::type_info` object representing the type of the stored callable.
- The `target<T>()` member function returns a pointer to the stored callable if it matches type `T`, or `nullptr` otherwise.

#### 4. **Performance Considerations**
Because `std::function` uses type erasure, there may be a small performance overhead compared to directly calling a function or lambda. This overhead is typically minimal and acceptable for most applications, but it’s worth noting for performance-critical code.

---

### Member Types and Functions

The page likely details **member types** and **member functions** of `std::function`. Here are some key ones:

#### **Member Types**
- **`result_type`**: The return type of the function (e.g., `int` for `std::function<int(int, int)>`).

#### **Member Functions**
- **Constructors**: Create `std::function` objects (default constructor creates an empty object; others accept callables).
- **Assignment operators**: Assign new callables to the object.
- **`operator()`**: Invoke the stored callable with the provided arguments.
- **`operator bool`**: Check if the object holds a callable (returns `true` if not empty).
- **`swap`**: Swap contents with another `std::function`.
- **`target_type`**: Get the type of the stored callable.
- **`target<T>`**: Access the stored callable as type `T` (if it matches).

---

### Use Cases

`std::function` shines in scenarios where you need to:
- **Store functions in containers**: e.g., a vector of callbacks.
- **Pass functions as arguments**: e.g., to other functions or methods.
- **Implement callbacks**: e.g., event handlers in classes.
- **Handle callables generically**: e.g., in templates or polymorphic designs.

#### Example: Storing Callbacks in a Vector

```cpp
#include <functional>
#include <vector>
#include <iostream>

void print(int i) { std::cout << i << std::endl; }
void print_double(int i) { std::cout << 2 * i << std::endl; }

int main() {
    std::vector<std::function<void(int)>> callbacks;
    callbacks.push_back(print);
    callbacks.push_back(print_double);

    for (auto& cb : callbacks) {
        cb(5);  // Calls print(5) and print_double(5)
    }
    return 0;
}
```

**Output:**
```
5
10
```

---

### Summary

- **`std::function`** is a template in the `<functional>` header that wraps callable entities (functions, lambdas, functors) matching a specific signature.
- It uses **type erasure** to store different callable types uniformly.
- It’s ideal for callbacks, storing functions in containers, and passing functions as arguments.
- It can be empty, and calling an empty `std::function` throws a `std::bad_function_call` exception.
- While it introduces a slight overhead, it’s efficient for most use cases.

The page at https://en.cppreference.com/w/cpp/utility/functional/function.html provides a detailed reference for `std::function`, including its declaration, member types, member functions, and examples. Understanding `std::function` is essential for writing flexible, modern C++ code, especially in event-driven or functional programming contexts. Let me know if you’d like further clarification on any aspect!
#endif