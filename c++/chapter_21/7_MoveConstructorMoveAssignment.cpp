#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Auto_ptr4{
    T *m_ptr;
public:
    Auto_ptr4(T* ptr = nullptr): m_ptr(ptr){}
    ~Auto_ptr4(){delete m_ptr;}

    //Copy Constructor
    Auto_ptr4(const Auto_ptr4 &a){
        cout << "copy Constrcutor called\n";
            // deep copy
            m_ptr = new T;
        *m_ptr *a.m_ptr;
        return *this;
    }

    // let's do move constrcutor implementation :Note we will modify object on right side(existing) so no const
    // transfer ownership
    /**/
    Auto_ptr4(Auto_ptr4 &&a) noexcept :m_ptr(a.m_ptr) {
        cout<<"Move Constrcutor called\n";
        a.m_ptr = nullptr;
    }
    //Copy assignment
    Auto_ptr4 &operator=(const Auto_ptr4 &a){
        cout << "copy assignment called\n";
            // self reliant
            if (&a == this)
        {
            return *this;
        }
        //relase any Resource holding
        delete m_ptr;
        // deep copy of Resource
        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }
    // Move Assignment : transferownership from a.m_ptr to m_ptr
    Auto_ptr4 &operator= (Auto_ptr4 &&a) noexcept{
        cout<<"Move assignement called\n";
        if(&a == this) return *this;
        delete m_ptr;

        //transfer ownership
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }
};
class Resource
{
private:
    
public:
    Resource();
    ~Resource();
};

Resource::Resource()  
{
    cout<<"Resource accquired\n";
}

Resource::~Resource()
{
    cout << "Resource destroyed\n";
}

Auto_ptr4<Resource> generateResource(){
    Auto_ptr4<Resource> res{new Resource};
    return res;
}
int main()
{
    Auto_ptr4<Resource> mainRes;
    mainRes = generateResource();
    return 0;
}
/*
    ***********************************
    Implicit move constructor and move assignment operator

    The compiler will create an implicit move constructor and move assignment operator if all of the following are true:

        There are no user-declared copy constructors or copy assignment operators.
        There are no user-declared move constructors or move assignment operators.
        There is no user-declared destructor.
    These functions do a memberwise move, which behaves as follows:

        If member has a move constructor or move assignment (as appropriate), it will be invoked.
        Otherwise, the member will be copied.
        Notably, this means that pointers will be copied, not moved!

    Warning

    The implicit move constructor and move assignment will copy pointers, not move them. If you want to move a pointer member, you will need to define the move constructor and move assignment yourself.
*/
/*
Great observation and excellent question!

Let's **analyze your code step by step**, map the **actual output**, and answer **why the Move Constructor is not called**, even though you expect it to.

---

### ✅ **Your Code Summary**

#### Function:

```cpp
Auto_ptr4<Resource> generateResource(){
    Auto_ptr4<Resource> res{new Resource};
    return res;
}
```

You're returning a local `Auto_ptr4<Resource>` by **value**, which should ideally call the **move constructor** during the return.

---

### ✅ **Your Observed Output**

```text
Resource accquired
Move assignement called
Resource destroyed
```

---

## 🔍 **Why Move Constructor is NOT Called**

The move constructor is defined correctly:

```cpp
Auto_ptr4(Auto_ptr4 &&a) noexcept : m_ptr(a.m_ptr) {
    cout << "Move Constructor called\n";
    a.m_ptr = nullptr;
}
```

Yet, it's **not getting printed** during:

```cpp
mainRes = generateResource();
```

So, let’s explain it in detail:

---

## ✅ Step-by-Step Execution & Mapping

### 🔸 Step 1: `mainRes` Created

```cpp
Auto_ptr4<Resource> mainRes;
```

* Default constructor is called.
* `mainRes` is empty (`m_ptr = nullptr`).
* **No output yet.**

---

### 🔸 Step 2: `generateResource()` Called

```cpp
mainRes = generateResource();
```

#### Inside `generateResource()`:

```cpp
Auto_ptr4<Resource> res{new Resource};
```

* `Resource` is dynamically allocated.
* Output:

  ```
  Resource accquired
  ```

#### Then:

```cpp
return res;
```

Now the **return statement** may:

1. **Copy** `res` to a temporary (pre‑C++11 behavior)
2. **Move** `res` to a temporary (C++11 and later)
3. **Elide** the move entirely via **RVO (Return Value Optimization)** or **copy elision**

Since you're compiling with `-std=c++23`, which includes C++17 and later rules, **move elision is mandatory in many cases**.

> 🔥 **C++17 and newer guarantees elision of copy/move constructor** when returning a local variable by value.

So the move constructor **is never called**, because the compiler **constructs the return value directly** in the target (`mainRes`) via **RVO**, skipping both copy and move!

---

### 🔸 Step 3: Move Assignment Happens

Now back in `main()`:

```cpp
mainRes = generateResource();
```

This triggers the **move assignment operator**, because:

* `generateResource()` **returned an object** (via RVO, directly constructed in caller).
* `mainRes` is being **assigned** from it.

So this is a move assignment, and the output is:

```
Move assignement called
```

---

### 🔸 Step 4: Destructor Runs

After the assignment and at the end of the program, `mainRes` goes out of scope and is destroyed:

```cpp
~Auto_ptr4() { delete m_ptr; }
```

This deletes the heap-allocated `Resource`:

```
Resource destroyed
```

---

## ✅ Final Output Mapped to Code

| Line in Code                           | Output                    |
| -------------------------------------- | ------------------------- |
| `new Resource` in `generateResource()` | `Resource accquired`      |
| `mainRes = generateResource();`        | `Move assignement called` |
| `mainRes` destroyed at end of `main()` | `Resource destroyed`      |

---

## ✅ Summary

### ❓ **Why was `Move Constructor` not called?**

> Because of **RVO (Return Value Optimization)**—as per C++17 rules and above, returning a local variable by value **does not call copy or move constructor**.

### ✅ What was called?

* **Move Assignment Operator** was called during assignment: `mainRes = generateResource();`

### ✅ How to **force move constructor** call for learning/testing?

You can force move constructor usage by **disabling RVO** or returning a **temporary**:

```cpp
mainRes = std::move(generateResource());
```

This disables RVO and forces move construction, but in your case you're assigning, so only move assignment will be called unless it's an initialization:

```cpp
Auto_ptr4<Resource> mainRes = generateResource(); // Will call move constructor (if no RVO)
```

---


*/