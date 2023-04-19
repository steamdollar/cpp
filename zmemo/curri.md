# 1. Introduction to C++
- Overview of C++ and its history
- Setting up a development environment
- Basic structure of a C++ program
- Compiling and running a C++ program
- Basics of C++ Syntax

# 2. Variables and data types
- Constants and enumerations
- Basic input/output (cin, cout)
- Arithmetic, relational, and logical operators
- Control structures (if, else, switch, for, while, do-while)
- Functions

# 3. Defining and calling functions
- Function prototypes and declarations
- Pass-by-value vs. pass-by-reference
- Function overloading
- Inline functions
- Recursion

### 3.6 arrays & pointers
#### 3-6-1: Arrays
- Introduction to arrays in C++
- Declaring and initializing arrays
- Accessing array elements
- Array bounds checking

#### 3-6-2: Pointers
- Introduction to pointers in C++
- Declaring and initializing pointers
- Pointer arithmetic
- Pointers and arrays

#### 3-6-3: Pointer-to-Pointer and Multi-dimensional Arrays
- Working with pointer-to-pointer variables
- Declaring and initializing multi-dimensional arrays
- Accessing multi-dimensional array elements

#### 3-6-4: Dynamic Memory Allocation
- The need for dynamic memory allocation
- Using new and delete operators
- Allocating arrays dynamically

#### 3-6-5: Common pitfalls and best practices
- Common mistakes when working with arrays and pointers
- Best practices for using arrays and pointers in C++

# 4. Arrays and array notation
## 4.1 Pointers and pointer arithmetic (review)
### 4.1.1 Pointer basics

포인터 선언은 다음과 같이 *을 이용한다.

```
    int* my_ptr
```

### 4.1.2 Pointer arithmetic
산술 계산이 포인터에 왜 필요하냐? 포인터가 가리키는 값을 바꿔줄 수 있음.
배열이랑 잘 조합되서 사용한다.

``` cpp
    int my_array[5] = {1, 2, 3, 4, 5};
    
    // 포인터로 배열을 지정하면 배열의 첫번쨰 요소를 자동으로 가리킴
    int* my_ptr = my_array; 
    
    // 그 포인터의 다음 주소는 두 번째 요소를 가리키게 됨
    int second_element = *(my_pointer + 1)
    
```

### 4.1.3 Relationship between pointers and arrays
함수에서 배열은 포인터로 분해되므로, 포인터 산술계산과 응용하면
배열 순회를 포인터로 할 수 있음.

``` cpp
    void print_array(int* arr , int size) {
        for( int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    
    int main() {
        // my_array는 array의 1st 요소를 가리키는 포인터로 decay되어 함수로 전달됨
        int my_array[5] = {1, 2, 3, 4, 5};
        print_array(my_array, 5);
        return 0;
    }
```

## 4.2 Dynamic memory allocation (new, delete)
### 4.2.1 passing array to functions using pointers
함수에 배열을 전달할 때 파라미터에 크기를 특정해줄 필요가 없다. 

포인터를 사용해 전달하기 때문.

단, 포인터만으로는 size를 특정할 수 없으므로 이 파라미터는 따로 넣어주면 된다.

``` cpp
    // 매개변수 int* arr이 integer array를 "represent"한다.
    int sum_array_elements(int* arr, int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];   
        }
        return sum;
    }
```

### 4.2.2 using pointer args to modify data
pointer를 이용해 함수로 배열을 전달할 때, 함수는 원 배열의 내용물을 변경할 수 있다.

포인터가 메모리 주소를 직접 reference해주기 때문.

반대로, 값을 이용해 배열을 전달 할때는 원 값의 복사본을 함수가 받게 되고, 

여기서 함수를 수정해도 원 배열에는 영향을 주지 않는다.

``` cpp
    #include <iostream>
    
    void double_array_elements(int* arr, int size) {
        for(int i = 0; i < size; i++) {
            arr[i] *= 2;    
        }   
    }
    
    void print_array(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";   
        }   
        std::cout << std::endl;
    }
    
    int main() {
        int my_array[5] ={ 1, 2, 3, 4, 5};
        std::cout << "orginal : ";
        print_array(my_array, 5);
        
        double_array_elements(my_array, 5);
        
        std::cout << "doubled: ";
        print_array(my_array, 5);
        return 0;
    }
```

cf) 복사해 넘겨주는 코드
// 이 경우 vector를 사용해야 한다.
``` cpp
    #include <iostream>
    #include <vector>
    
    std::vector<int> double_array_elements(const std::vector<int>& arr) {
        std::vector<int> new_array(arr.size());
        for (std::size_t i = 0; i <arr.size(); ++i) {
            new_array[i] = arr[i] * 2;   
        }
        return new_array;
    }
    
    // param의 const는 함수가 vector를 바꾸지 않는다는 것을 지시
    // &은 vector가 함수로 들어갔을때 이를 복사하는 걸 피하기 위해 사용한다.
    // vector 크기가 클 때 성능 향상에 도움이 됨
    // 나머진 그냥 param 이름이랑 타입임
    template<typename T>
    void print_array(const std::vector<T>& arr) {
        
        // vector arr의 type T의 element에 대해 반복
        // 마찬가지로 const는 original vector element가 반복문 안에서 바뀌지 않는다는걸 의미
        for (const T& element : arr){
            std::cout << element << " ";   
        }
        std::cout << std::endl;
    }
    
    int main() {
        // std::vector는 동적 배열 of cpp 표준 lib
        std::vector<int> my_array = {1,2,3,4,5};
        std::cout << "original : ";
        print_array(my_array);
        
        std::vector<int> doubled_array = double_array_elements(my_array);
        
        std::cout << "doubled : ";
        print_array(doubled_array);
        
        std::cout << "original after double : ";
        print_array(my_array);
        
        return 0;
    }
    
```

## 4.3 Functions with array and pointer arguments (review)
skipped

## 4.4 Strings
### 4.4.1 C-style string
C 스타일 string은 문자의 배열로, 메모리에 있는 문자의 시퀀스를 표현한다.

string의 끝을 지시하기 위해 string 마지막에 null char(\0)를 자동으로 붙이는 null-terminated 속성이다.

``` cpp
    char my_string[] = "Hello, world";
```

### 4.4.2 null-terminated character arrays
늘 null문자를 고려하면서 문자를 선언, 조작할 것

``` cpp
    char my_str[] = {"h", "e", "l", "l", "o", "\0"};
```

### 4.4.3 string manipulation functions
cpp 표준 lib는 c-style string과 관련된 여러 문자 관련 함수를 지원한다.

(e.g. strlen, strcmp, strcpy, strcat)

``` cpp
    #include <cstring>
    #include <iostream>
    
    int main() {
        char str1[] = "hello";
        char str2[] = "world";
        char str3[11];
        
        strcpy(str3, str1);
        strcat(str3, " ");
        strcat(str3, str2);
        
        std::cout << "product : " << str3 << std::endl;
        
        return 0;   
    }
```

### 4.4.4 C++ string class (std::string)
이래도 되고, cpp std string class를 사용해도 된다.

``` cpp
    #include <iostream>
    #include <string>
    
    int main() {
        std::string str1 = "hello";
        std::string str2 = "world";  
        std::string str3 = str1 + " " + str2;
        
        std::cout << "product : " << str3 << std::endl;
        
        return 0;
    }
```
보통 c-style은 low level 관련 작업할때만 쓰고, 일반적으로 cpp의 표준 string 사용



# 5. C-style strings
## 5.1. C-style strings vs. C++ strings
C-style, Cpp string 모두 cpp에서 string을 다루는 방식이다.

### C-style string
- C-style string은 마지막에 null 문자가 붙은 문자들의 배열이다. 
- C언어로부터 상속되었다.
- 메모리 관리와 조작 측면에서 에러가 많이 터지고 번거로운 면이 있다.
- C-style string을 이용하려면 헤더에 <cstring>을 포함시키고, 그 안의 함수들을 사용할 수 있다.
(.e.g. strcpy, strlen, ...)

### CPP strings
- cpp string은 cpp 표준 lib의 일부로, std::string class로 구현할 수 있다.
- 메모리 자동 관리, member func가 있어 string을 다루기가 안전하고 편하다.
- 헤더에 <string>을 포함해야 한다.
- 최근 cpp에서는 c++ string을 사용하길 권장한다. (편함, 안전성, 유연함)

그럼에도 C-style string을 공부하는 이유는 C를 다룰 떄도 많을 거고,

low level programming, 면접 등에 도움이 될 것이므로..

## 5.2. Declaring and initializing C-style strings

- 선언과 초기화
``` cpp
    #include <cstring>

    // 한 번에 하고 싶다면 이렇게
    char my_string[] = "hello, world";
    
    // 따로 하고 싶다면 이렇게
    
    // 문자열 길이를 지정하고 
    // 문자열 + null 문자를 다 저장할 만큼의 크기가 있어야 함.
    char my_string[14];
    strcpy(my_string, "Hello, World!");
```

## 5.3. Common string manipulation functions

C-style string의 조작을 위해서는 <cstring> lib가 필요하다.

``` cpp
    #include <cstring>
    
    // strlen : 문자열 길이 리턴
    int length = strlen(my_string);
    
    // strcpy : string을 다른 string (크기가 충분한)
    char dest[14];
    strcpy(destination, my_string);
    
    // strcat : 한 string을 다른 string으로 추가
    char dest2[25] = "Hello";
    char source[] = ", World!";
    strcat(dest, source); 
    
    // strcmp : 두 문자열을 비교, 동일하면 0, 1st param이 작다면 -, vice versa
    int result = strcmp(string1, string2);
    
```

C-style string을 사용하고 싶다면 buffer overflow 등의 메모리 이슈에 주의할 것.
(할당된 배열 길이가 충분한지 확인 잘 하라는 말)

## 5.4. String input and output

### C-style string
- input
사용자의 C-style string input을 읽기 위해서는 scanf() 함수를 사용할 수 있다.

``` cpp
    char str[100];
    scanf("%s", str);
```

단, scanf 함수는 buffer overflow를 막아주지 못하므로 보통 이것보단 fget() 함수가 선호된다.

``` cpp
    char str[100];
    fgets(str, sizeof(str), stdin);
```

- output
printf() 함수 사용

``` cpp
    char str[] = "hwllo world";
    printf("%s\n", str);
```

### cpp strings
- input
std::cin 객체를 stream extract 연산자 ">>"와 함께 사용한다.

``` cpp
    std::string str;
    std::cin >> str;
```

다만 이 emthod는 whitespace 문자를 읽지 않는다.

전체 line을 읽으려면 std::getline() 함수를 사용한다.

``` cpp
    std::string str;
    std::getline(std::cin, str);
```

- output
std::cout 객체를 stram insertion 연산자 "<<"와 함께 상요한다.

``` cpp
    std::string str = "Hello World!";
    std::cout << str << std::endl;
```

## 5.5. Converting between C-style strings and C++ strings
둘 간엔 상호 변환이 가능하다.

### 5.5.1 cpp strings to c-style
std::string class의 함수인 c_str() 를 사용할 수 있다.
이 함수는 \0로 끝나는 char 배열에 대한 포인터를 가져온다.

``` cpp
    std::string cppString = "hello";
    const char* cString = cppString.c_str();
    
    // 이제 cString을 C-style string처럼 사용 가능
    printf("%s\n", cString);
```

const 이므로 포인터를 통해 원 값을 변경할 수 없고, 원 값에 묶여있으므로

원 cpp string이 수정되면 cString값도 변한다.

### 5.5.2 c-style to cpp string
c-style string을 std::string constructor로 넘겨주거나 바로 assign해주면 된다.

``` cpp
    const char* cString = "Hello, World!";
    std::string cppString(cString);
    
    // or
    cppString = cString;
    
    //
    std::cout << sppString << std::endl;
```

이건 C-style string의 복사본을 만든것이므로 원본의 상태를 걱정할 필요가 없다.




# 6. Classes and objects
Constructors and destructors
Access specifiers (public, private, protected)
Class methods and properties
Inheritance and polymorphism
Operator overloading
Friend functions and classes
File Input/Output

# 7. File streams (ifstream, ofstream, fstream)
Opening and closing files
Reading and writing to files
File modes and error handling
Standard Template Library (STL)

# 8. Introduction to the STL
Containers (vector, list, deque, set, map, etc.)
Iterators
Algorithms (sort, find, etc.)
Function objects and lambda expressions
Advanced C++ Topics

# 9. Templates
Exception handling (try, catch, throw)
Namespaces
Smart pointers and memory management
Multithreading
Move semantics and rvalue references
C++ Best Practices and Design Patterns

# 10. Coding style and conventions
C++11, C++14, C++17, and C++20 features
Common design patterns
Performance optimization techniques