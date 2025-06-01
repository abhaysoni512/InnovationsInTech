/*
C++ supports 3 different kinds of template parameters :

    1. Type template parameters(where the template parameter represents a type)
        *A type template parameter represents a type (e.g., int, double, std::vector<int>, etc.).
        *It allows us to define generic classes or functions that can work with any data type.

        Example: Generic function to add two numbers
            template <typename T>
            T add(T x, T y)
            {
                return x + y;
            }
            int main()
            {
                std::cout << add(5, 4) << '\n'; // 9
                std::cout << add(5.5, 4.3) << '\n'; // 9.8
                return 0;
            }
        Example: Generic Class:
            template <typename T>
            class Box {
                T value;
            public:
                Box(T v) : value(v) {}
                T getValue() { return value; }
            };

            int main() {
                Box<int> intBox(42);
                Box<double> doubleBox(3.14);
                std::cout << intBox.getValue() << "\n";      // 42
                std::cout << doubleBox.getValue() << "\n";  // 3.14
                return 0;
            }
    2. Non - type template parameters(where the template parameter represents a constexpr value).
        *A non-type template parameter represents a value (e.g., an integer, a pointer, etc.).
        *It allows us to define generic classes or functions that can work with values that are known at compile time.

        Example: Generic function to get the size of an array
            template <typename T, int size>
            int getArraySize(T(&)[size])
            {
                return size;
            }
            int main()
            {
                int arr1[] = { 1, 2, 3, 4, 5 };
                double arr2[] = { 1.1, 2.2, 3.3, 4.4 };
                std::cout << getArraySize(arr1) << '\n'; // 5
                std::cout << getArraySize(arr2) << '\n'; // 4
                return 0;
            }
    3.Template template parameters(where the template parameter represents a template).
        *A template template parameter represents a template.
        *It allows us to define generic classes or functions that can work with any template.

        Example: Generic class to store a pair of values
            template <typename T>
            class Pair {
                T values[2];
            public:
                Pair(const T& first, const T& second)
                {
                    values[0] = first;
                    values[1] = second;
                }
                const T& getFirst() const { return values[0]; }
                const T& getSecond() const { return values[1]; }
            };

            template <template <typename> class P, typename T>
            void printPair(const P<T>& pair)
            {
                std::cout << pair.getFirst() << ", " << pair.getSecond() << '\n';
            }

            int main()
            {
                Pair<int> p1(1, 2);
                Pair<double> p2(3.4, 7.8);
                printPair(p1); // 1, 2
                printPair(p2); // 3.4, 7.8
                return 0;
            }
*/


