#if 0
Let’s dive into l-value and r-value references in C++, focusing on their definitions, initialization rules, and modification capabilities, with clear examples to illustrate each case. This explanation aligns with C++11’s introduction of r-value references while recapping the traditional l-value references.

---

### **L-Value References Recap**

Before C++11, C++ had only one type of reference, simply called a “reference.” With C++11, these are now termed **l-value references** to distinguish them from the new r-value references. An l-value is an object that has a name and persists beyond a single expression (e.g., a variable), while an r-value is a temporary value (e.g., a literal or expression result).

#### **L-Value Reference (`Type&`)**
- **Definition**: Binds only to modifiable l-values.
- **Initialization**: Can be initialized with modifiable l-values but not with non-modifiable l-values or r-values.
- **Modification**: Allows modification of the bound object.

**Rules**:
| Can be initialized with | Allowed? | Can modify? |
|--------------------------|----------|-------------|
| Modifiable l-values      | Yes      | Yes         |
| Non-modifiable l-values  | No       | No          |
| R-values                 | No       | No          |

**Example**:
```cpp
int x = 5;         // Modifiable l-value
int& lref = x;     // lref is an l-value reference to x
lref = 10;         // Modifies x to 10
std::cout << x << std::endl;  // Outputs: 10
```
- Here, `x` is a modifiable l-value, and `lref` binds to it, allowing us to change `x` through `lref`.

**Invalid Cases**:
```cpp
// int& lref = 5;  // Error: cannot bind l-value reference to r-value (5)
// const int y = 5;
// int& lref2 = y; // Error: cannot bind l-value reference to non-modifiable l-value
```

#### **L-Value Reference to Const (`const Type&`)**
- **Definition**: Binds to modifiable l-values, non-modifiable l-values, and r-values.
- **Initialization**: Extremely flexible—accepts almost anything.
- **Modification**: Does not allow modification of the bound object.

**Rules**:
| Can be initialized with | Allowed? | Can modify? |
|--------------------------|----------|-------------|
| Modifiable l-values      | Yes      | No          |
| Non-modifiable l-values  | Yes      | No          |
| R-values                 | Yes      | No          |

**Examples**:
1. **With a modifiable l-value**:
   ```cpp
   int x = 5;
   const int& cref = x;  // Binds to modifiable l-value
   // cref = 10;         // Error: cannot modify through const reference
   std::cout << cref << std::endl;  // Outputs: 5
   ```

2. **With a non-modifiable l-value**:
   ```cpp
   const int y = 5;
   const int& cref = y;  // Binds to non-modifiable l-value
   std::cout << cref << std::endl;  // Outputs: 5
   ```

3. **With an r-value**:
   ```cpp
   const int& cref = 5;  // Binds to a temporary const int created from r-value 5
   std::cout << cref << std::endl;  // Outputs: 5
   ```

- **Why it’s useful**: `const Type&` is perfect for function parameters when you want to accept any argument (l-value or r-value) without copying:
  ```cpp
  void print(const int& val) {
      std::cout << val << std::endl;
  }
  int x = 5;
  print(x);   // Passes l-value
  print(10);  // Passes r-value
  ```

---

### **R-Value References (Introduced in C++11)**

C++11 introduced **r-value references** (`Type&&`), designed specifically to bind to r-values—temporary objects that don’t persist. They use a double ampersand (`&&`) to distinguish them from l-value references (`&`).

#### **R-Value Reference (`Type&&`)**
- **Definition**: Binds only to r-values.
- **Initialization**: Cannot bind to l-values unless explicitly converted (e.g., with `std::move`).
- **Modification**: Allows modification of the bound temporary.

**Rules**:
| Can be initialized with | Allowed? | Can modify? |
|--------------------------|----------|-------------|
| Modifiable l-values      | No       | No          |
| Non-modifiable l-values  | No       | No          |
| R-values                 | Yes      | Yes         |

**Example**:
```cpp
int&& rref = 5;  // Binds to a temporary int with value 5
rref = 10;       // Modifies the temporary to 10
std::cout << rref << std::endl;  // Outputs: 10
```
- Here, `rref` extends the lifetime of the temporary `5` and allows modification.

**Invalid Case**:
```cpp
int x = 5;
// int&& rref = x;  // Error: cannot bind r-value reference to l-value
```
- To bind `x` to an r-value reference, use `std::move`:
  ```cpp
  int x = 5;
  int&& rref = std::move(x);  // Treats x as an r-value
  rref = 10;                  // Modifies x
  std::cout << x << std::endl;  // Outputs: 10
  ```

#### **R-Value Reference to Const (`const Type&&`)**
- **Definition**: Binds to r-values but doesn’t allow modification.
- **Initialization**: Only r-values are allowed.
- **Modification**: No modification permitted.

**Rules**:
| Can be initialized with | Allowed? | Can modify? |
|--------------------------|----------|-------------|
| Modifiable l-values      | No       | No          |
| Non-modifiable l-values  | No       | No          |
| R-values                 | Yes      | No          |

**Example**:
```cpp
const int&& crref = 5;  // Binds to a temporary const int
// crref = 10;          // Error: cannot modify through const reference
std::cout << crref << std::endl;  // Outputs: 5
```

**Invalid Case**:
```cpp
int x = 5;
// const int&& crref = x;  // Error: cannot bind to l-value
```

---

### **Putting It All Together**

Here’s a quick comparison with examples:

1. **L-value reference**:
   ```cpp
   int x = 5;
   int& lref = x;
   lref = 10;  // x becomes 10
   ```

2. **L-value reference to const**:
   ```cpp
   const int& cref = 5;  // Binds to r-value 5
   ```

3. **R-value reference**:
   ```cpp
   int&& rref = 5;
   rref = 10;  // Modifies temporary
   ```

4. **R-value reference to const**:
   ```cpp
   const int&& crref = 5;  // Binds to r-value, no modification
   ```

---

### **Why These Matter**

- **L-value references to const** (`const &`) are great for read-only access to any argument without copying.
- **R-value references** (`&&`) enable **move semantics**, allowing efficient transfer of resources from temporaries (e.g., in move constructors):
  ```cpp
  class MyClass {
  public:
      MyClass(MyClass&& other) { /* Move resources */ }
  };
  ```

This foundation in C++11 enhances performance and resource management, making these concepts key to modern C++ programming.
#endif

#include <iostream>

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1)
    {
        out << f1.m_numerator << '/' << f1.m_denominator;
        return out;
    }
};

int main()
{
    auto &&rref{Fraction{3, 5}}; // r-value reference to temporary Fraction

    // f1 of operator<< binds to the temporary, no copies are created.
    std::cout << rref << '\n';

    return 0;
} // rref (and the temporary Fraction) goes out of scope here