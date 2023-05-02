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
## 6.1 Constructors and destructors

### 6.1.1 role of constructors
- 생성자는 class의 object가 생성될때 자동으로 실행되는 class의 함수이다.

- obj의 attribute를 초기화하고 resource를 allocate하는데 사용된다.

- 생성자 함수 이름은 class 이름과 동일하고, 리턴 타입은 없다.

### 6.1.2 default constructors
- class에 대해 생성자함수를 정의하지 않는다면 컴파일러가 자동으로
디폴트 생성자를 제공해 객체를 디폴트 값으로 설정한다.

- 생성자를 파라미터와 함께 정의하면 컴파일러가 디폴트 생성자를 생성하지 않는다. 이 경우, 변수를 주지않고 객체를 생성하려면 명시적으로 생성자함수를 줘야 함.

### 6.1.3 parameterized constructor
- 객체의 attribute를 특정 값으로 초기화하고 위해 파라미터와 함께 생성자를 정의할 수 있다.

### 6.1.4 constructor of overloading
- 함수 overload와 비슷하게, 다른 파라미터들을 가진 여러 개의 생성자를 하나의 class에서 정의할 수 있다. 객체 생성시 적절한 생성자가 호출된다. 

### 6.1.5 copy constructor
- copy constructor는 생성자의 한 타입으로, 존재하는 obj의 값을 이용해 새 obj를 초기화한다.

- 컴파일러가 제공하는 디폴트 copy constructor는 obj의 sttribute를 얕은 복사한다.

- 깊은 복사가 필요하다면 직접 copy constructor를 만들어야 한다.

### 6.1.6 role of destructor
- 객체가 범위를 벗어나거나 명시적으로 삭제될때 자동 실행되는 특수한 member function이다.

- 리소스를 release하고, cleanup task를 실행한다.

- destrucotr의 이름은 class명과 동일하지만 ~가 prefix로 붙고 리턴 타입, 파라미터는 없다.

``` cpp
    class exClass {
        public:
        // 생성자
            exclass() {
                std::cout << "Constructor called" << std::endl;
            }
            
            ~exClass() {
                std::cout << "Destrucotr called" << std::endl;
            }
                
    }
    
    int main() {
        // 생성자 함수가 자동으로 호출
        exClass obj;
        
        // obj가 범위 밖으로 나가면 destructor가 자동으로 호출됨
        return 0;
    }
```

## 6.2 Access specifiers (public, private, protected)
access speicfier는 class memeber의 접근성과 가시성을 결정한다.

- public : class에 접근할 수 있는 프로그램의 어떤 부분에서도 접근 가능하다.
= class 안팎 모두에서 접근이 가능하다.

- private : class 자체에서만 접근이 가능하다. 상속받은 class나 class 밖에서는 접근할 수 없다.

- protected : class와 derived class에서 접근이 가능하지만 class 밖에서는 접근이 불가능하다. 

``` cpp
    class ExClass {
        public : 
        int publicVar;
        void publicFunc(){}
        
        private:
        int privateVar;
        void privateFunc(){}
        
        protected:
        int protectedVar;
        void protectedFunc(){}   
    }
```

class의 memeber에 어떤 속성을 줄것인지를 결정할 때는 

"principle of least privilege" 를 따르는 것이 좋다.

: 목적을 당성하기 위해 필수적인 최소한의 접근성을 준다.

memeber의 접근성에 대해 명시적으로 지정해주지 않으면 디폴트 값으로 정해지는데,

struct는 public, class는 private.


## 6.3 Class methods and properties
- methods (member fucntions)
1. class 선언 시점에 내부에서 정의하거나, :: 연산자를 이용해 class 밖에서 만든다.

2. method는 자신이 속한 obj의 속성에 접근해 이를 수정할 수 있다.

3. public, private, protected로 지정해 접근성을 조정할 수 있다.

4. const로 선언하면 method가 obj의 state를 바꾸지 못한다.

- properties (member var)
1. class의 obj에 데이터를 저장한다.

2. public/protected/private 설정 가능

3. static으로 선언될 수 있다. 이 경우, class의 모든 obj에 공유되며, 모든 obj에서 값이 같다.

4. static하지 않다면 디폴트 값을 가질 수 있다.

``` cpp
    class Circle {
        private :
            double radius
            
        public :
            Circle(double r) {
                radius : r;   
            }
            
            // const이므로 obj에 뭔가 변화를 주지는 못함
            double getRadius() const {
                return radius;   
            }
            
            void setRadius(double r) {
                radius : r;   
            }
            
            double area() const {
             return 3.141519 * radius * radius;
    }
```


## 6.4 Inheritance and polymorphism

- inheritance
inheritance(상속)은 존재하는 class에서 property와 method를 상속받은

새로운 class를 생성해 코드에 재사용성과 조직화를 돕는다.

cpp에서 상속은 `:${access_specifier}`, base class 이름을 사용해 일어난다.

``` cpp
class Animal {
    public : 
        void speak() {
            std::cout << "the animal makes sound" << std::endl;
        }
}

// Animal class를 상속 받음 
class Dog : public Animal {
    public:
    // speak method를 상속받지만 override함.
        void speak() {
            std::cout << "the dog barks" << std::endl;
        }
}
```

- polymorphism
polymorphism은 base class reference를 통해 class obj를 유도할 수 있게 해

저 유연하고 일반화된 코드를 짤 수 있게 해준다.

cpp 에서 이를 활용하려면 base class로의 포인터나 참조를 사용해야 하고, base class의 method를 virtual로 선언해야 한다.

virtual method는 유도된 class에 의해 override되고, 런타임에서 객체의 실제 타입에 기반해 호출된다.

``` cpp
    class Animal {
        public :
        // speak method를 virtual로 선언하면
        // Dog class가 speak()를 override할 수 있음
        virtual void speak() {
            std::cout << "the animal makes a sound" << std::endl;
        }
        
        virtual ~Animal() {
            std::coust << "Animal destructor called" << std::endl;   
        }
    }
    
    class Dog : public Animal {
        public :
        void speak() override {
            std::cout << "the dog barks" << std::endl;   
        }
        
        ~Dog() {
            std::cout << "Dog destructor called" << std::endl;
        }
    }
    
    int main() {
        // Animal pointer가 Dog obj를 가리킨다.
        Animal* animalPtr = new Dog();
        
        // Dog's의 speak method 호출
        animalPtr->speak();
        
        // arrow로 해도 되고, 이렇게 점찍어도 됨
        animalPtr.speak()
        
        // destructor 호출
        delete animalPtr;
        return 0;
    }
    
```

## 6.5 Operator overloading

operator overload는 built-in 연산자를 커스텀 class에서 재정의한다.

``` cpp
    #include <iostream>
    
    class Complex {
        public:
        Complex(double real, double imaginary) : real_(real), imaginary_(imaginary) {}
        
        // overloading + operator
        Complex operator+(const Complex& other) const {
            return Complex(real_ + other.real_, imaginary_ + other.imaginary_);
        }  
        
        
        void print() const {
            std::cout << real_ << " + " << imaginary_ << "i" << std::endl;   
        }
        
        private:
        double real_;
        double imaginary_;
    }
    
    int main() {
        Complex a(3,2);
        Complex b(1,7);
        
        Complex result = a + b;
        result.print();
        
        return 0;
    }
```

## 6.6 Friend functions and classes

cpp에서 가끔은 함수가 class가 다른 class의 private or protected member에

접근해야 할 때가 있는데, 그 때 friend function or friend class를 사용한다.

- Friend functions
: class의 private, protected member에 접근 할 수 있는 함수를 말한다.

``` cpp
        class Circle {
        public :
            // 생성자함수 - class와 이름이 같음
            Circle(double radius) : radius_(radius) {}
            
            // declare friend function
            friend double calculate_area(const Circle& circle);
        
        private:
            double radius_;
        }    
        
        // define friend function - 이 함수는 private 속성인 radius에 접근 가능
        double calculate_area(const Circle& circle) {
            return 3.1415 * circle.radius_ * circle.radius_;   
        }   
        
        int main() {
            Circle c(5);
            double area = calculate_area(c);
            std::cout << "Area : " << area << std::endl;
            
            return 0;   
        }
    
```

- friend class

다른 class의 protected, private 속성에 접근 가능ㅎ다ㅏ.

``` cpp
    class Rectangle {
    public:
        Rectangle(double width, double height): width_(width), height_(height) {}
    
    private:
        double width_;
        double height_;
        
        friend class RectangleInfo;   
    }
    
    class RectangleInfo {
        public:
        static double calculate_area(const Rectangle& rectangle){
            return rectangle.width_ * rectangle.height_;   
        }
    }
    
    int main() {
        Rectangle r(4,6);
        
        // RectangleInfo의 해당 함수는 r에 접근 가능
        double area = RectangleInfo::calculate_area(r);
        std::cout << "Area: " << area << std::endl;
        
        return 0;   
    }
    
```

## 6.7 File Input/Output
파일에서 데이터를 읽거나 파일에 데이터를 쓰는데 사용된다.

표준 라이브러리를 사용할 수 있다.

1. ifstream (input file stream) : Used for reading data from files
2. ofstream (output file stream) : used for writing data to files

``` cpp
    #include <iostream>
    #include <fstream>
    #include <string>
    
    int main() {
        
        // writing to file
        std::ofstream outFile("example.txt")
        if(!outFile) {
            std::cerr << "failed to open file to writing" << std::endl;
            return 1;
        }
        
        outFile << "hello file" << std::endl;
        oufFile.close();
        
        // reading from a file
        std::ifstream inFile("example.txt");
        in(!inFile) {
            std::cerr << "failed to open the file for reading" << std::endl;
            return 1;
        }
        
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;   
        }
        inFile.close();
        
        return 0;
    }
```


# 7. File streams (ifstream, ofstream, fstream)
## 7.1 Opening and closing files

### 7.1.1 ifstream, ofstream and fstream classes
파일을 조작하는건 <fstream> header의 3개 class를 사용할 수 있다.

1. ifstream : input file stream used for reading data from file
2. ofstream : output file stream used for writing data to files
3. fstream : File stream that can be used for both r, w

### 7.1.2 opening files using constructors
대응하는 file stream class 객체를 생성해 파일을 열고, 파일 경로/이음을 준다.

``` cpp
    #include <iostream>
    #include <fstream>
    
    int main() {
        // file을 연다.
        std::ifstream inputFile("input.txt");
        std::ofstream outputFile("output.txt");
           
        // task를 진행
           
        // 작업 후 파일을 닫는다.
        inputFile.close();
        outputFile.close();
        
        return 0;
    }
```

### 7.1.3 Closing files using the close() member function
close() method를 이용해 파일을 닫을 수 있다. go와는 다르게 이건 굳이 안써줘도 
file stream이 범위에서 벗어나거나 하면 자동으로 파일이 닫힌다.

## 7.2 Reading and writing to files
### 7.2.1 Reading data from files using getline(), get(), and >>

ifstream 객체의 >> 연산자를 이용해 파일을 읽을 수 있다.

``` cpp
    #include <iostream>
    #include <fstream>
    #include <string>
    
    int main() {
        
        // ifstream class의 inputFiel method 호출, 파일명을 인수로 줌.
        std::ifstream inputFile("input.txt");
        
        // 열려 있다면 
        if (inputFile.is_open()) {
            // inputFile의 각 line을 읽는다.
            while (std::getline(inputFile, line)) {
                std::cout << line << std::endl;   
            }   
            inputFile.close();
        }   else {
            std::cerr << "unable to open the file" << std::endl;   
        }
        
        return 0;
    }
```

### 7.2.2.Writing data to files using << and put()
``` cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    
    if(inputFile.is_open() && outputFile.is_open()) {
        int number;
        // whitespace로 구분해 끊어 읽으려면 >>를 사용
        while (inputFile >> number) {
            int doubledNumber = number * 2;
            outputFile << doubledNumber << std::endl;
        }
        
        inputFile.close();
        outputFile.close();
        
    }   else {
        std::cerr << "unable to open" << std::endl;
    }
    
    return 0;
}
```

put method는 std::ostream class의 member로, output stream에

char 하나를 쓴다. 그래서 매개변수도 글자 하나씩 받음.

``` cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("output.txt");
    
    if(outputFile.is_open()) {
        outputFile.put('H');
        outputFile.put('e');
        outputFile.put('l');
        outputFile.put('l');
        outputFile.put('o');
        outputFile.put('\n');
        outputFile.put('w');
        // ... 생략
        
        outputFile.close();
    } else {
        std::cout << "unable to open file" << std::endl;   
    }
    return 0;
}
```

### 7.2.3 Checking for end-of-file and other I/O states
file stream 관련 작업을 할 때는 데이터 처리를 제대로 하고 있는지 확인하기 위해

eof 등의 다양한 I/O state를 체크하는 것이 중요하다.

이런 I/O state 체크를 위해 file stream class에서 제공하는 몇가지 함수가 있다.

- eof() : end of file에 도달했다면 true를 리턴
- fail() : I/O operation이 실패하면 true를 리턴한다. (존재하지 안흔 파일을 읽으려 하거나, 타입이 다르거나..)
- bad() : 심각한 에러 (파일이 오염되거나, 하드웨어 failure)가 있을 때 true를 리턴한다.
- good() : 위 세 가지를 만나지 않았을 경우 true를 리턴

``` cpp
    #include <iostream>
    #include <fstream>
    #include <string>
    
    int main() {
        std::ifstream inputFile("input.txt");
        
        if(inputFile.is_open()) {
            std::string line;
            while(getline(inputFile, line)) {
                std::cout << line << std::endl;
                
                if(inputFile.eof()) {
                    std:;cout << "reached eof" << std::endl;   
                } else if (inputFile.fail()) {
                    std::cout << "an I/O oper failed" << std::endl;
                } else if (inputFile.bad()) {
                    std::cout << "critial err" << std::endl;   
                }
            }
            
            inputFile.close();
        } else {
            std::cout << "unable to open file" << std::endl;
        }
        
        return 0;
    }
```

## 7.3 File modes and error handling
### 7.3.1 File open modes (ios_base::in, ios_base::out, ios_base::app, etc.)
file mode는 file stream을 어떻게 열고 파일을 다룰지를 특정한다.

보통은 std::fstream을 사용할 때, 혹은 특정 모드로 file을 열 때
(r/w가 동시에 일어나거나, data 병합이 일어나거나)

cpp에서 파일 모드는 ios class 상수로 정의되고 OR 연산자와 결합되어 사용한다.

- ios::in : read를 위해 파일을 연다. (ifstream의 디폴트)
- ios::out : write를 위해 파일을 연다. (ofstream의 디폴트) 파일이 이미 존재한다면 내용물을 초기화한다.

- ios::app : append를 위해 파일을 연다. 모든 write된 내용이 eof에 추가된다.

- ios::ate : 파일을 열고, file position indicator를 eof로 이동시킨다.
- ios::trunc : 파일이 존재한다면 초기화한다. ios::out의 디폴트
- ios::binary : binary mode로 파일을 연다. 텍스트 파일이 아닌 이미지, 실행 파일을 열때 유용하다.

``` cpp
    #include <iostream>
    #include <fstream>
    
    int main() {
        // example.txt를 std::fstream class를 이용해 ios::in, ios::out mode로 연다.
        // 이 경우 파일을 초기화하지 않고 읽고 쓰는게 가능
        std::fstream file("example.txt", std::ios::in | std::ios::out);
        
        if(!file.is_open()) {
            // 앞에 배운 여러 체크 함수들을 이용해 에러를 체크 할 수 있음
            std::cerr << "err opening the file" << std::endl;
            return 1;   
        }
        
        file.close();
        return 0;
    }
```

### 7.3.2 Handling file I/O errors using exceptions and the fail() member function
예외 처리를 이용해 I/O를 핸들링할 수 있다. exceptions() 함수를 이용해 원하는 에러를 처리할 수 있음.

디폴트로 file stream은 에러 에외를 던지지 않지만 우리가 커스텀할 수 있다.

```cpp
    #include <iostream>
    #include <fstream>
    
    int main() {
        std::ifstream inputFile;
        std::ofstream outputFile;
        
        try {
            // fallbit, badbit에 err state 예외를 허용
            inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            inputFile.open("input.txt");
            
            outputFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
            outputFile.open("output.txt");
            
            std::string line;
            while (std::getline(inputFile, line)) {
                outputFile << line << std::endl;   
            }
            
        } catch(const std::ifstream::failure& e) {
            std::cerr << "error: " << e.what() << std::endl;
            return 1; 
        }   
        
        inputFile.close();
        outputFile.close();
        return 0;
    }
```

에러가 파일 열기, 읽기, 쓰기 과정에서 일어나면 std::ifstream::failure 예외가 던져져서

catch block으로 빠지게 된다.

what() method가 에러 내용을 출력한다.


## 7.4 Standard Template Library (STL)
STL은 cpp 표준 라이브러리의 일부로, 강력한 container class와 algorithm을 제공한다.

데이터 구조등에 대해 수행하는 작업(e.g. 검색, 정렬 수정 등)을 편하게 해줌.

1. Containers
객체를 저장하고 메모리를 관리하는 데이터 구조체이다.
e.g. std::vector, std::list, std::map, std:;set 등..

2. iterators
iterator는 컨테이너의 요소를 순회하고 접근하는데 사용된다.

모든 컨테이너에 대한 공통적인 인터페이스를 제공해 다른 타입의 구조체에도 동일한 코드를 적용할 수 있게 해줌.

3. algorithms
여러 컨테이너에 대해 적용될 수 있는 제네릭 알고리즘
e.g. std::sort, std::find, std::accumulate

4. functors
알고리즘의 인수로 사용될 수 있는 함수 객체이다. 코드 수정없이 알고리즘의 행동을 커스터마이즈 할 수 있게 해줌.

5. allocators
컨테이너에 대한 메모리 할당을 관리한다. 데이터 구조체에 대한 메모리 할당, 할당 해제 방식을 수정할 수 있음.

STL에 파일 스틤과 직접 연관이 된건 아니지만 복잡한 프로그램에선 많이 마주치게 될거다.

파일에서 많은 양의 데이터를 가져올 때 유용함.


# 8. Introduction to the STL
## 8.1 Containers (vector, list, deque, set, map, etc.)
Container는 STL의 기본적인 컴포넌트 중 하나로, 데이터를 효율적이고 짜임새있는 구조로

데이터를 저장, 조작하는 방법을 제공한다.

몇 가지 class가 있는데 각각 특성과 use case가 다르다.

### 8.1.1 Sequential containers
- vector : 요소의 추가/제거에 따라 자동으로 사이즈가 조절되는 동적 배열. 
    랜덤 요소로의 빠른 접근, 마지막 요소의 효율적인 삽입, 삭제가 가능하다.
    index를 통해 요소에 접근하거나, 마지막 요소에 추가, 삭제를 할 때 유리하다.

``` cpp
    #include <iostream>
    #include <vector>
    
    int main() {
        // 표준 lib, int 속성 vector 선언 
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        
        std::cout << "the first element is: " << numbers[0] << std::endl;  
        
        // vector 마지막에 요소 추가
        numbers.push_back(6);
        
        // vector에서 마지막 요소 제거
        numbers.pop_back();
        
        for (const auto &number : numbers) {
            std:: cout << number << " ";    
        }
        std::cout << std::endl;
        return 0;
    }
```
    
- list : 컨테이너 어디에서든 효율적인 삽입과 삭제를 허용하는 doubly linked list. 
    단, 개별 요소에의 직접적 접근은 불가능.
    자주 컨테이너 중간에 삽입/삭제가 필요하고, 랜덤 엑세스는 필요없는 경우 사용한다.
    
``` cpp
    #include <iostream>
    #include <list>
    
    int main() {
        std::list<int> numbers = {1,2, 3, 4, 5};
        
        numbers.push_front(0);
        
                for (const auto &number : numbers) {
            std::cout << number << " ";
        }   
        std::cout << std::endl;
        numbers.pop_front();
        
        for (const auto &number : numbers) {
            std::cout << number << " ";
        }   
        std::cout << std::endl;
        
        return 0;
    }
```
    

- deque (double ended queue) : vector와 비슷하지만 처음과 끝 요소에서 효율적인 삽입과 삭제를 할 수 있다.
    요소들에 빠른 랜덤 엑세스가 필요할 때, 컨테이너 양 끝에 삽입/삭제를 할 때 사용한다.

``` cpp
    #include <iostream>
    #include <deque>
    
    int main() {
        std::deque<int> numbers = {1,2,3,4,5};
        
        numbers.push_front(0);
        
        numbers.push_back(6);
        
        for (const auto &number : numbers) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
        numbers.pop_front();
           
        numbers.pop_back();
           
        for (const auto &number : numbers) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
           
        return 0;
    }
```


### 8.1.2 Associative containers

- set : unique한 key들을 값으로 정렬한 집합. 키와 연결된 데이터는 저장하지 않는다.

``` cpp
    #include <iostream>
    #include <set>
    
    int main() {
        std::set<int> numbers = {1, 2, 3, 4, 5};
        
        // set에 element 추가
        numbers.insert(6);
        
        if(numbers.find(3) != numbers.end()) {
            std::cout << "3 is present" << std::endl;   
        }   
        
        // set에서 element 제거
        numbers.erase(2);
        
        for (const auto &number : numbers) {
            std::cout << number << " ";   
        }
        std::cout << std::endl;
        
        return 0;
    }
```

- multiset
set과 비슷하지만, 동일 key를 여러 개 저장할 수 있다.

- map
k-v 쌍의 모음으로, key values로 정렬된다. 

``` cpp
    #include <iostream>
    #include <map>
    int main() {
        std::map <std::string, int> ages;
        
        ages["Alice"] = 20;
        ages["Bob"] = 25;
        
        std::cout << "Alice's age : " << ages["Alice"] << std::endl;
        
        for (const auto &pair : ages) {
            std::cout << pair.first << " : " << pair.second << std::endl;   
        }
        
        return 0;
    }
```

### 8.1.3 Unordered associative containers
k-v pair를 저장하는건 위와 동일하지만 순서를 유지해주지는 않는다. 요소를 조직화하기 위해

해시 함수를 이용해 평균적으로 빠른 탐색 시간을 제공함.

- unordered_set
``` cpp
    #include <iostream>
    #include <unordered_set>
    
    int main() {
        std::unordered_set<int> numbers = {1, 2, 3, 4, 5}
        
        numbers.insert(6);
        
        if (numbers.find(3) != numbers.end()) {
            std::cout << "3 exist in unordered set" << std::endl;
        }   
        
        numbers.erase(3);
        
        return 0;
    }
    
```

- unordered_map
이 쪽도 순서가 없다는 것만 빼면 map과 동일

``` cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> ages = {{"Alice", 30}, {"Bob", 25}};
    
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;
    
    ages["Diana"] = 28;
    
    if(ages.find("Bob") != ages.end()) {
        std::cout << "Bob's age is in unordered map" << std::endl;   
    }
    
    ages.erase("Bob");
    
    return 0;
}

```

### 8.1.4 Container adaptors
이들 자체가 완전한 컨테이너는 아니지만 기저의 컨테이너에 특정 인터페이스를 제공해준다.

stack, queue, priority_queue가 있다.

- stack
stack은 LIFO 데이터 구조

``` cpp
    #include <iostream>
    #include <stack>
    
    int main() {
        std::stack<int> numbers;
        
        numbers.push(1);
        numbers.push(2);
        numbers.push(3);
        
        std::cout << "Top element : " << numbers.top() << std::endl;
        
        numbers.pop();
        
        if(!number.empty()) {
            std::cout << "stack is not empty" << std::endl;   
        }
        
        return 0;
    }
```

- queue
FIFO 구조.

``` cpp
    #include <iostream>
    #include <queue>
    
    int main() {
        std::queue<int> numbers;
        
        numbers.push(1);
        numbers.push(2);
        numbers.push(3);
        
        std::cout << "Front element : " << numbers.front() << std::endl;
        
        numbers.pop();
        
        if(!numbers.empty()) {
            std::cout << "queue is not empty" << std::endl;   
        }
        
        return 0;
    }
    
```

- priority_queue
element가 계속 특정 우선순위에 의해 정렬되는 데이터 구조.

디폴트로는 max-heap (큰 값을 가진 요소가 큰 priority) 이지만,

min-heap를 가지거나, 커스텀할 수 있다.

``` cpp
    #include <iostream>
    #include <queue>
    
    int main() {
        std::priority_queue<int> numbers;
        
        numbers.push(1);
        numbers.push(3);
        numbers.push(2);
        
        std::cout << "top element : " << numbers.top() << std::endl;
        
        numbers.pop();
        
        if(!numbers.empty()) {
            std::cout << "priority queue is not empty" << std::endl;   
        }
        
        return 0;   
    }
    
```


## 8.2 Iterators
컨테이너의 요소들을 순회하고 조작할 수 있게 해준다.

다른 컨테이너 타입과 작동하는 일반화된 포인터라고 볼 수도 있다.

### 8.2.1 Iterator types
5가지 iterator 타입이 있다.

1. input iterator
컨테이너에서 요소를 읽는다. 수정은 못하고, 앞으로만 움직일 수 있음.

2. output iterators
컨테이너에 요소를 쓸 수는 있는데 반대로 읽지는 못함. 앞으로만 움직임.

3. forward iterators
읽고 쓸 수 있으며, 앞으로만 움직인다.

4. bidrectical iterators
앞, 뒤로 움직일 수 있다.

5. random access iterators
어떤 위치의 요소에게든 바로 접근할 수 있으며, 읽고 쓸 수 있고, 요소 간 이동을 위해 산술 연산을 수행한다.

### 8.2.2 Basic iterator operationas
iterator와 자주 함께 쓰는 연산자들은 다음이 있다.

- increment(`++`) : 컨테이너 다음 요소로 이동
- dereference(`*`) : iterator가 포인트 하고 있는곳으로 접근
- comparison(`==`, `!=`) : 두 iterator가 동일한지 확인

``` cpp
    #include <iostream>
    #include <vector>
    
    int main() {
        std::vector<int> numbers = { 1,2,3,4,5};
        
        std::vector<int>::iterator it;   
        
        for (it = numbers.begin(); it != numbers.end(); ++it) {
            std::cout << *it << " ";   
        }
        
        return 0;
    }
```  

### 8.2.3 Iterator operations and functions (advance, distance, next, prev)
더하고 빼고 비교하는것 이외에도 좀 복잡한 연산을 위한 연산자가 있다.

- std::advance
특정 step만큼 앞/뒤로 이동하게 해준다.

``` cpp
    #include <iostream>
    #include <vector>
    #include <iterator>
    
    int main() {
        std::vector<int> numbers = {1, 2, 3, 4,5};
        std::vector<int>::iterator it = numbers.begin();
        
        std::advance(it, 2);
        
        std::cout << *it << std::endl;
        
        return 0;
    }
```

- std::distance
두 요소 사이의 거리를 리턴

``` cpp
    #include <iostream>
    #include <vector>
    #include <iterator>

    int main() {
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        std::vector<int>::iterator it1 = numbers.begin();
        std::vector<int>::iterator it2 = numbers.end();
        
        std::ptrdiff_t dist = std::distance(it1, it2);
        
        std::cout << "distacne btw two vectors" << dist << std::endl;
        
        return 0;
    }
```

- std::next
특정 step 이후의 iterator를 반환한다.

``` cpp
    #include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5};
    
    // numbers의 첫 요소 지정
    std::vector<int>::iterator it = numbers.begin();
    
    // it에서 3개 이후의 요소
    std::vector<int>::iterator nextIt = std::next(it, 3);
    
    std::cout << "position 4 :" << *nextIt << std::endl;
    
    return 0; 
}
```

- std::prev
이전 iterator로 원하는 만큼 돌아간다.

``` cpp
    #include <iostream>
    #include <vector>
    #include <iterator>
    
    int main() {
        std::vector<int> numbers = { 1, 2, 3, 4,5 };
        std::vector<int>::iterator it = numbers.end();
        
        int n = 2;
        // n step 만큼 뒤로 이동
        std::vector<int>::iteraotr prevIt = std::prev(it, n);
        
        std::cout << *prevIt << std::endl;
        
        return 0;  
    }
```

## 8.3 Algorithms (sort, find, etc.)

### 8.3.1 Sorting algorithms
cpp STL은 container 안의 요소들을 정렬할 수 있도록 정렬 알고리즘이 있다.

- sort
[first, last) 의 범위를 오름/내림 차순으로 정렬한다. 복잡도는 O(n*log(n))

``` cpp
    #include <algorithm>
    #include <vector>
    
    std::vector<int> numbers = {5, 3, 1, 4, 2};
    std::sort(numbers.begin(), numbers.end())

```

- stable_sort
sort와 비슷하지만 동일한 요소의 전후 순서를 보장해준다.
``` cpp
    #include <alforithm>
    #include <vector>
    
    std::vector<int> numbers = {5,3,1,4,2};
    std::stable_sort(numbers.begin(), numbers.end());
```

- partial_sort
[first, last) 범위의 요소를 sort 해줌. 나머지는 무작위로 남음.
``` cpp
    #include <algorithm>
    #include <vector>
    
    std::vector<int> numbers = {5,3,1,4,2};
    std::partial_sort(numbers.begin(), nermbers.begin() + 3, numbers.end());
    // 1, 2, 3, 5, 4
```

- nth_element
반복자 n번째가 가리키는 요소가 정렬된 시퀀스에서와 동일한 위치를 갖도록 [첫 번째, 마지막) 범위의 요소를 재배열한다. 복잡도는 O(n)

``` cpp
    std::vector<int> numbers = {5,3,1,4,2};
    std::nth_element(numbers.begin(), numbers.begin() + 2, numbers.end());
```


### 8.3.2 Searching algorithms (find, find_if, binary_search, lower_bound, upper_bound)

탐색 알고리즘은 특정 조건이나 값을 만족하는 요소를 찾는데 사용된다.

- find
특정 값을 탐색해 처음 만나는 타겟 값의 위치를 리턴한다. 못 찾았을 경우 마지막 요소를 리턴한다.
``` cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>
    
    int main() {
        std::vector<int> numbers = {4, 2, 7, 5, 9, 1};
        int target = 5;
        
        auto it = std::find(numbers.begin(), numbers.end(), target);
        
        if(it != numbers.end()) {
            std::cout << "Found " << target << " at position: " << std::distance(numbers.begin(), it) << '\n';
        } else {
            std::cout << target << "not found.\n"
        }
        return 0;
    }
```

- find_if
특정 조건을 만족하는 요소를 찾는다. 만족하는 첫 번째 요소를 리턴, 없다면 마지막 요소를 리턴

``` cpp
    bool is_even(int x) {
        return x % 2 == 0;   
    }
    
    int main() {
        std::vector<int> numbers = { 3,7,5,2,1,9};   
        
        auto it = std::find_it(numbers.begin(), numbers.end(), is_even);
        
        if (it != numbers.end()) {
            std::cout << "Found even number : " << *it << '\n';   
        } else {
            std::cout << "no even number found";
        }
        
        return 0;
    }
```

- binary_search
특정 값이 정렬된 컨테이너에 있는지 확인.
있다면 true 리턴, vice versa. T/F만 알려줘서 binary라고 하는 듯.

``` cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>
    
    int main() {
        std::vector<int> numbers = { 1, 3, 5, 7, 9};
        int target = 5;
        
        if(std::binary_search(numbers.begin(), numbers.end(), target)) {
            std::cout << target << " found. \n";   
        } else {
            std::cout << target << " not found.\n";
        }
        
        return 0;
    }
```

- lower/upper bound
특정 값보다 작지/크 않은 첫 번째 요소의 index를 리턴

lower는 '작지 않은' 값이고 upper는 '큰' 값임.

``` cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>
    
    int main() {
        std::vector<int> numbers {1,3,5,5,5,7,9};
        int target = 5;
        
        auto lower = std::lower_bound(numbers.begin(), numbers.end(), target);
        auto upper = std::upper_bound(numbers.begin(), numbers.end(), target);
        
        // target == 5 보다 크지 않은 첫 요소 5의 index 값 2 리턴
        std::cout << "lower bound: " << std::distance(numbers.begin(), lower) << '\n';
        
        // target보다 큰 첫 요소 7의 index값 5 리턴
        std::cout << "upper bound: " << std::distance(numbers.begin(), upper) << '\n';
        
        return 0;
    }
```

### 8.3.3 Modifying algorithms (copy, move, transform, fill, replace, remove, unique)
컨테이너 안의 값들을 바꿔주는 함수들.

- copy
범위 내의 값들을 복사한다. 복사된 값을 받는 컨테이너 크기가 충분해야 함.
``` cpp
    vector<int> source = { 1,2,3,4,5};
    vector<int> destination(5);
    
    copy(source.begin(), source.end(), destination.begin());
```

- move
특정 값들을 다른 컨테이너로 이동한다. 마찬가지로 값을 받는 컨테이너 크기가 충분히 커야 함.
이동하면 원래 컨테이너에서 그 값은 null값이 됨.
``` cpp
    vector<string> source = {"hello", "world"};
    vector<string> destination(2);
    
    move(source.begin(), source.end(), destination.begin());
```

- transform
각 요소에 함수를 적용해 다른 컨테이너에 넣는다. js의 map이랑 비슷한듯.

``` cpp
    vector<int> numbers = {1,2,3,4,5};
    vector<int> squares(5);
    
    transform(numbers.begin(), numbers.end(), squares.begin(), [](int x) {
        return x*x;
    };
    
```

- fill
범위 내 모든 element에 값을 할당
``` cpp
    std::vector<int> numbers(5);
    fill(numbers.begin(), numbers.end(), 42);
```

- replace
주어진 범위내 모든 타깃 값을 지정된 값으로 교채

``` cpp
    std::vector<int> numbers = {1,2,3,4,5};
    replace(numbers.begin(), numbers.end(), 2, 42);
```

- remove
범위 내의 타깃값을 전부 제거. 제거된 자리는 null값이 남음.

``` cpp
    std::vector<int> numbers = { 1,2,3,2,1};
    auto new_end = remove(numbers.begin(), numbers.end(),2);
    numbers.erase(new_end, numbers.end());
```

- unique
중복된 요소를 하나만 남기고 제거. 지워진 값은 null값이 남음
``` cpp
    std::vector<int> numbers = {1,1,2,2,3,3};
    auto new_end = unique(numbers.begin(), numbers.end());
    numbers.erase(new_end, numbers.end());
```


### 8.3.4 Numeric algorithms (accumulate, inner_product, partial_sum, adjacent_difference)
범위 내 요소에 대해 산술적 연산을 수행

- accumulate
주어진 범위 내 요소들의 합을 계산
``` cpp
    #include <iostream>
    #include <vector>
    #include <numeric>
    
    int main() {
        std::vector<int> numbers = {1,2,3,4,5};
        
        // 3rd param : initial value
        int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
        
        std::cout << " Sum : " << sum << std::endl;
        
        return 0;   
    }
```

- inner_product
요소들의 두 시퀀스의 inner product를 계산
이거 설마 벡터 내적 말하는건가?

맞네...

``` cpp
    #include <iostream>
    #include <vector>
    #include <numerio>
    
    int main() {
        std::vector<int> v1 = { 1,2,3,4,5};
        std::vector<int> v2 = { 6,7,8,9,10};
        
        int product = std::inner_product(v1.begin(), v1.end(), v2.begin, 0); 
        
        std::cout << "inner product  " << product << std::endl;
        
        return 0;
    }
    
```

- partial_sum : 부분합
``` cpp
    #include <iostream>
    #include <vector>
    #include <numeric>
    #include <iterator>
    
    int main() {
        std::vector<int> numbers = { 1,2,3,4,5};
        std::vector<int> result(numbers.size());
        
        std::partial_sum(numbers.begin(), numbers.end(), result.begin());
        
        std::cout << "partial sum :";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        return 0;
           
    }
    
```

- adjacent_difference
주어진 range에서 인접한 요소의 차이를 계산 후, 그 값을 다른 range에 저장

``` cpp
    int amin() {
        std::vector<int> numbers = { 1, 2, 4, 7, 11 };
        std::vector<int> result(numbers.size());
        
        std::adjacent_difference(numbers.begin(), numbers.end(), result.begin());
        
        std::cout << "Adjacent diff : ";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        return 0;
    }
```


## 8.4 Function objects and lambda expressions
## 8.4.1 function objects (functors)
함수로서 호출되는 객체. class를 operator()를 이용해 overload해 함수 객체를 만들 수 있다.

``` cpp
    #include <iostream>
    
    // overload된 operaotr를 가진 Adder 정의
    class Adder {
    public:
        int operator() (int a, int b) const {
            return a + b;   
        }   
    };
    
    int main() {
        // Adder class add를 생성
        Adder add;
        
        // add를 함수처럼 호출 가능
        int sum = add(3,4);
        std::cout << "3 + 4 = " << sum << std::endl; 
        
        return 0;  
    }
```

### 8.4.2 Lambda expressions and closures
람다 표현은 함수 객체를 더 정확하게 정의할 수 있는 방식이다. 이름이 없고 정의해 바로 사용할 수 있음.

``` cpp
    [capture](parameters) -> return_type {body}
```

``` cpp
    #include <iostream>
    
    int main() {
        auto add = [](int a, int b) -> int { return a + b };
        int sum = add(3,4);
        std::cout << " 3 + 4 = " << sum << std::endl;
        
        return 0;
    }
```

Closures는 주변 범위에서 변수들을 capture한 람다 표현식으로 부터 생성된 함수 객체이다.

람다 표현식의 capture clause는 람다 표현식이 scope에서 어떻게 변수를 캡쳐하는지 정의한다.

(& for reference, = for value)

### 8.4.3 standar lib function objs
cpp 표준 lib는 비교, 산술, 논리 연산자 등을 위한 함수 객체를 미리 정의해두었다.

이건 굳이 여기서 볼 필요는 없을 듯.


## 8.5 Advanced C++ Topics

### 8.5.1 Smart pointers (unique_ptr, shared_ptr, weak_ptr)
스마트 포인터는 메모리 관리를 자동으로 하게 해주는 cpp의 기능이다.

더 필요가 없다면 메모리를 deallocate 해버리는걸 보장해주는데,

스마트 포인터는 세 가지가 있음.

1. unique_ptr
> raw 포인터를 감싸는 경량 wrapper 로, 하나의 raw pointer를 저장하고

범위를 벗어날 때 대상을 삭제한다.

고유한 소유권을 가지므로 복사는 안되고 이동만 가능.

이동될 경우 원래 unique_ptr은 nullptr로 설정되고,

대상의 소유권이 대상 unique_ptr로 이전된다.

따라서 마지막 uinque_ptr이 범위를 벗어날 때  객체는 한 번만 삭제됨.

``` cpp
    #include <iostream>
    #include <memory>
    
    int main() {
        std::unique_ptr<int> ptr1(new int(42));
        // std::unique_ptr<int> ptr2 = ptr1 ;
        // > err : unique_ptr은 복사될 수 없음
        
        std::unique_ptr<int> ptr2 = std::move(ptr1);
        // transfer ownership from ptr1 to ptr2
        
        std::cout << *ptr2 << std::endl;
        
        return 0;
    }
```

2. shared_ptr
> 개체에 대한 raw pointer와 참조 카운트라는 두 가지 정보를 저장하는 스마트 포인터 

참조 갯수는 별도의 제어 블록에 저장되고, 이 블럭은 개체에 대해 첫 번째 shared_ptr 생성시 생성.

이 제어 블록은 개체를 가리키는 shared_ptr의 수를 추적한다.

여러 개의 인스턴스가 동적 할당된 대상에 대한 소유권을 공유.

모든 shared_ptr이 범위를 벗어나거나 리셋되면 대상과 제어 블록이 삭제된다.

리소스를 여러 개 인스턴스가 공유해야 할때 유용하다.

``` cpp
    #include <iostream>
    #include <memory>
    
    int main() {
        std::shared_ptr<int> ptr1(new int(42));
        std::shared_ptr<int> ptr2 = ptr1;
        
        std::cout << *ptr1 << " " << *ptr2 << std::endl;
        
        return 0;   
    }

```

3. weak_ptr
> 하나 이상의 shared_ptrs가 소유하고 있는 동적으로 할당된 객체에 대한 비소유 참조를 보유한다. shared_ptrs 간의 순환 종속성을 끊는 데 사용할 수 있으며, 수명을 연장하지 않고 객체를 관찰하는 데에도 사용할 수 있다. 오브젝트에 액세스하려면 weak_ptr에서 shared_ptr을 생성해야 한다.

shared_ptr과 유사하지만 참조 수에 기여하지 않는다. shared_ptr와 raw pointer, 제어 블록에 대한 포인터를

저장한다는 건 동일하지만 참조 횟수를 변화시키지 않고 객체를 관찰하기만 한다.

대상에 접근하려면 weak_ptr에서 shared_ptr을 생성해야 한다. 

객체가 살아있다면 (가리키는 shared_ptr이 존재한다면)

참조 카운트가 증가하고 개체에 접근할 수 있다.
 

``` cpp
    #include <iostream>
    #include <memory>
    
    int main() {
        std::shared_ptr<int> ptr1(new int(42));
        std::weak_ptr<int> wptr1(ptr1); // 소유권을 공유하지 않음
        
        if(auto ptr2 = wptr1.lock()) {
            std::cout << *ptr2 << std::endl;
        }
        
        return 0;   
    }
```

중요하건 이들 모두 리소스 관리를 위해 사용된다는 것이고, RAII 방식을 이용한다는 점이다.

(resource acquistion is initiailization 대상의 생명 주기에 리소스의 생명 주기를 묶는 것)


### 8.5.2 Move semantics and rvalue references
1. Move semantics
> cpp 11의 기능으로, 리소스 (메모리 등)의 효율적인 이동을 도와준다.

컴파일러가 리소스를 한 개체에서 다른 개체로 복사가 아니라 이동을 시킬 수 있게 해줌으로써

특정 작업을 최적화한다.

2. Rvalue References
> 1을 지원하기 위해 cpp 11에서 나온 새로운 레퍼런스의 타입
rvalue reference는 이름이 없고 이후에 refer도 될 수 없는 일시적인 객체나 값인 rvalue에 bind된다.

cpp 03에선 lvalue에 bind되는 lvalue reference만 있었다 (메모리에 주소가 있는 명명된 객체나 값)

rvalue reference를 사용하면 rvalue를 특정해 핸들링하는 함수를 생성할 수 있다.

``` cpp
// rvalue ref (int&&) 가 rvalue(42)에 bind
    int&& rvalue_ref = 42;
```

rvalue ref를 파라미터로 사용하는 함수를 생성해 move semantics를 사용할 수 있다.

``` cpp
    void process_string(std::string&& str) {
        //...   
    }
```

### 8.5.3 Template metaprogramming

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