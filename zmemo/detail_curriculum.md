# 6. Classes & Objects

## 6.1 Constructors & destructors

### 6.1.1. The role of constructors
### 6.1.2. Default constructors
### 6.1.3. Parameterized constructors
### 6.1.4. Constructor overloading
### 6.1.5. Copy constructors
### 6.1.6. The role of destructors

## 6.2 Access specifiers (public, private, protected)

### 6.2.1. Public access specifier
### 6.2.2. Private access specifier
### 6.2.3. Protected access specifier
### 6.2.4. Class members and encapsulation

## 6.3 Class methods and properties
### 6.3.1. Member functions
### 6.3.2. Getter and setter functions
### 6.3.3. Static member functions
### 6.3.4. Static member variables
### 6.3.5. Const member functions

## 6.4 Inheritance and polymorphism
### 6.4.1. The concept of inheritance
### 6.4.2. Types of inheritance (public, protected, private)
### 6.4.3. Multiple inheritance
### 6.4.4. The concept of polymorphism
### 6.4.5. Virtual functions
### 6.4.6. Pure virtual functions and abstract classes

## 6.5 Operator overloading
### 6.5.1. Overloading arithmetic operators
### 6.5.2. Overloading relational operators
### 6.5.3. Overloading stream input/output operators
### 6.5.4. Overloading unary operators
### 6.5.5. Overloading assignment operator

## 6.6 Friend functions and classes
### 6.6.1. The concept of friend functions
### 6.6.2. Granting access to a friend function
### 6.6.3. Friend classes

## 6.7 File Input/Output


### 6.7.1. File streams (ifstream, ofstream, fstream)
### 6.7.2. Opening and closing files
### 6.7.3. Reading and writing data to files
### 6.7.4. File stream manipulators and formatting
### 6.7.5. Random access file operations

# 7. File streams (ifstream, ofstream, fstream)
## 7.1 Opening and closing files
- ifstream, ofstream and fstream classes
- Opening files using constructors
- Closing files using the close() member function

## 7.2 Reading and writing to files
- Reading data from files using getline(), get(), and >>
- Writing data to files using << and put()
- Checking for end-of-file and other I/O states

## 7.3 File modes and error handling
- File open modes (ios_base::in, ios_base::out, ios_base::app, etc.)
- Handling file I/O errors using exceptions and the fail() member function

## 7.4 Standard Template Library (STL)
- Using file streams with STL containers and algorithms (e.g., reading data into a vector, processing data with algorithms)

# 8. Introduction to the STL

## 8.1 Containers (vector, list, deque, set, map, etc.)
### 8.1.1 Sequential containers (vector, list, deque)
### 8.1.2 Associative containers (set, map, multiset, multimap)
### 8.1.3 Unordered associative containers (unordered_set, unordered_map,    unordered_multiset, unordered_multimap)
### 8.1.4 Container adaptors (stack, queue, priority_queue)

## 8.2 Iterators
### 8.2.1 Iterator categories (input, output, forward, bidirectional, random access)
### 8.2.2 Iterator operations and functions (advance, distance, next, prev)

## 8.3 Algorithms (sort, find, etc.)
### 8.3.1 Sorting algorithms (sort, stable_sort, partial_sort, nth_element)
### 8.3.2 Searching algorithms (find, find_if, binary_search, lower_bound, upper_bound)
### 8.3.3 Modifying algorithms (copy, move, transform, fill, replace, remove, unique)
### 8.3.4 Numeric algorithms (accumulate, inner_product, partial_sum, adjacent_difference)

## 8.4 Function objects and lambda expressions
### 8.4.1 Function objects (functors)
### 8.4.2 Lambda expressions and closures
### 8.4.3 Standard library function objects (less, greater, plus, minus, multiplies, etc.)

## 8.5 Advanced C++ Topics
### 8.5.1 Smart pointers (unique_ptr, shared_ptr, weak_ptr)
### 8.5.2 Move semantics and rvalue references
### 8.5.3 Template metaprogramming

# 9. Templates
## 9.1 Introduction to templates
### 9.1.1 Function templates
### 9.1.2 Class templates
### 9.1.3 Template specialization
### 9.1.4 Variadic templates
## 9.2 Template type deduction
## 9.3 Template argument deduction and SFINAE (Substitution Failure Is Not An Error)
## 9.4 Template aliases

### 9.4.1 Basic template alias

### 9.4.2 Template alias for a specific instantiation

### 9.4.3. using template aliases w/ other templates

# 10. Advanced C++ Concepts
## 10.1 Exception handling (try, catch, throw)
## 10.2 Namespaces
## 10.3 Multithreading
## 10.4 C++ Best Practices and Design Patterns