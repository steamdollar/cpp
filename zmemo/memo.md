남는 시간엔 cpp를 해보자.

cpp는 범용성 높은 프로그래밍 언어로 C언어의 확장으로서 개발되었다.

class가 있는 C라고도 불리는데, 이는 시스템 프로그래밍, 게임 개발 , 임베디드 시스템, 고성능 컴퓨팅에 많이 사용된다.

# obsolete 
cpp를 공부하는데 있어 익숙해야 하는 키 컨샙은 다음과 같은 것들이 있다.

1. 변수와 데이터 타입
    cpp는 int, float, double, char와 같은 built in type이 몇가지 있고, 이를 반영해 변수를 생성해야 한다.
    
    ``` cpp
        int age = 30;
        float weight = 70.5
    ```

2. control structure
    다른 언어처럼 cpp도 if, else, while, for가 있다.
    ``` cpp
        for (int i = 0; i < 10; i++) {
            std::cout << 1 << std::endl;
        }
    ```
    
3. 함수
    cpp의 함수는 리턴 타입, 함수명, 파라미터 리스트를 이용해 정의된다. 
    ``` cpp
        int add (int a, int b) {
            return a + b;
        }
    ```

4. class & obj
    cpp는 객체 지향형 언어로, class나 obj를 생성할 수 있다.
    

    ``` cpp
        std::string name;
        int age;
        
        void bark() {
            std::cout << "woof" << std::endl;
        }
    ```

5. standard template library(STL)
    C++ 는 stl이라는 라이브러리가 있고, 여러 유용한 데이터 구조와 알고리즘을 제공한다. (벡터, 리스트, 큐)
    
    ``` cpp
        #include <iostream>
        
        int main() {
            std::cout << "Hello, C++!" << std:endl;
            
            for(int i =0; i<5; i++ ) {
                std::cout << "Iteration: " << i << std::endl;
            }
            
            return 0;
        }
    ```
    
    
# 1. intro to cpp
간단한 cpp 프로그램은 다음 컴포넌트들로 이루어져 있다.

- header files : 헤더 파일은 함수, 클래스, 변수 선언을 포함한다.
    일반적으로는
    `#include <iostream>` 을 가장 많이 사용하는데, 이는 input/output operations을 할 수 있게 해줌.

- main function : `main` 함수는 Cpp 프로그램의 진입점. 일반적으로 0을 리턴해 프로그램이 잘 완료되었음을 알려준다.

- statements & expressions : 프로그램의 building block, 프로그램의 동작을 정의한다.

ex) 
``` cpp
    #include <iostream> // 표준 입출력 라이브러리
    
    int main() {
        std::cout << "Hello CPP!" << std::endl;   
    }
```

확장자 명은 .cpp, 컴파일은 다음과 같이 하면 된다.

``` cpp
    g++ hello.cpp -o hello
```


# 2. Basics of C++ syntax

## variables & data types

기본 타입은 int, float, double, char, bool 이 있다.

변수 선언은 타입과 변수명을 같이 써주면 된다.

``` cpp
    data_type variable_name;
```

다른건 다 익숙한데 double type은 뭐냐? double time은 아는데..

이 쪽도 유리수에 관련된 건 맞는것 같은데.. 

비트를 더 써서 정확한 표현을 위한 건가 float보다?

float는 32비트를, double은 64비트를 쓴다.

그래서 float는 7자리 정도만 정확한데, double은 15~17자리까지 정확하게 알려줄 수 있음.

## basic input and otuput
cpp에서는 cin, cout 객체를 이용해 기본적인 입출력 작업을 할 수 있다.

값을 출력하려면 cout을 stream insertion operator ('<<') 와 함께 사용한다.

``` cpp
    #include <iostream>
    
    int main() {
        std::cout << "hello cpp" << std::endl;
        return 0;
    }
```

반대로 사용자가 값을 입력하려면 cin 객체를 사용해 stream extraction 연산자('>>')와 함께 사용한다.

``` cpp
    #include <iostream>

    int main() {
        int age;
        std::cout << "please enter your name";
        std::cin >> age;
        std::cout << "age is : " << age << std::endl;
        return 0;   
    }
```

std::endl; 는 end of line의 약자로, 

output stream에 \n을 추가하기 위해 사용되는데,

추가적으로 output stream을 flush해서 남은 버퍼 데이터가 전부 출력되게끔 한다.

마찬가지로 << 를 이용해 사용한다.

\n 를 추가해도 되는데 얘는 output stream을 flush해주진 않음.

여러개 문자열을 합쳐 출력하고 싶으면 console log에서 ,로 구분한것처럼 <<로 구분하면 된다.

e.g. 
``` cpp
    std::cout << "hello,' << name << "!" << std:endl;
```


# 3. functions

## 3.1 function prototypes and declaration

prototype이나 declaration이나 똑같은 말이다. 리턴 타입, 함수이름, 파라미터, 함수 내용을 주면 된다.

단, prototype은 함수 바디를 포함하고 있지는 않다. 그냥 이런 함수가 존재한다는 걸 컴파일러에게 알려주는 역할.

``` cpp
    return_type func_name(param_list)
```

## 3.2 pass by value vs pass by reference

cpp 에선 함수에 둘 모두를 사용할 수 있다.

i) pass by value
디폴트로는 이 방식을 사용함. 값을 복사해서 넘겨주는 방식.

따라서 함수에서 아무리 이걸 갖고 부랄발광을 해도 함수 밖에 있는 원래 값은 변하지 않음.

ii) pass by ref
이건 원 값의 reference나 포인터를 전달해줌.

이러면 함수가 원래 값을 직접 바꿀 수가 있게 된다.

### 주의점

- 배열은 항상 ref로 넣어줘야 함. (&가 없어도 ref로 들어감)

단, 이 때 배열 크기가 보존이 안되서 이것도 따로 매개 변수화 해서 넣어줘야 한다.

- 객체는 값 복사를 통해 전달된다. 이러면 객체 크기가 커지면 성능 저하가 생기는데,

이를 피하기 위해선 ref, pointer를 적절히 사용한다.

- 큰 객체나 배열을 수정없이 함수에 전달하고 싶르면 const reference를 사용한다.

이는 함수가 값을 복사하지 못하게 하면서도 원 값을 바꾸지 못하게 해준다.

이런식으로 전달해주면 됨.

``` cpp
    coid print_vector(const std::vector<int> &v);
```

- retuning reference : 함수가 reference를 리턴하는것도 가능하지만 이럴 땐 조심해야 함.

reference가 함수 내부의 지역 변수라면 함수 종료시 무효화되고. undefined로 변해서 코드를 줘패고 다닌다.

ref 대신 값이나 포인터로 리턴할 것.

- passing pointers : 원 데이터의 주소를 함수에 전달한다. 이건 현대 cpp에서는 잘 사용하지 않는데,

refence가 작업하기 편하고 에러도 덜 터지기 때문이다. (그래도 포인터도 많이 쓰임)

** what is reference?

### reference? 

cpp에서 reference가 뭐냐? 존재하는 변수의 alias 이다.

reference를 생성하면 이는 원 값과 동일한 메모리 주소를 참조한다.

이러면 원 데이터를 간접적으로 레퍼런스를 통해 작업할 수 있음.

#### 몇 가지 rule of ref

    1. 선언과 동시에 초기화되어야 하며, 다른 변수에 재할당 될 수 없다.
    2. null 일수는 없다.
    3. 다른 일반적인 변수를 사용하는 것과 syntax는 동일

``` cpp
    int x = 10;
    int& ref_x = x;
    
    ref_x = 20;
```

### pointer
cpp에서 포인터는 다른 변수의 메모리 주소를 갖는 변수이다.

이를 이용해 이들이 가리키는 메모리 주소에 저장된 데이터를 간접적으로 수정할 수 있다.

#### char
1. 포인터는 선언시 초기화될 수 있지만, 언제라도 다른 변수에 할당될 수 있다.

2. null 값을 가질 수 있다. 즉, valid한 메모리 주소를 가리키고 있지 않아도 된다.

3. * 연산자를 이용해 포인터를 dereference할 수 있고, & 연산자를 이용해 변수의 주소를 알 수 있다.

``` cpp
    int x = 10;
    int * ptr_x = &x; // x를 가리키는 포인터 ptr_x 
    
    *ptr_x = 20; // x값 변경
```

## 3.3 function overloading

다른 파라미터를 가진 여러 개의 함수를 동일한 이름으로 사용할 수 있게 해주는 개념이다.

컴파일러는 호출 시점에서 인수의 타입과 갯수를 보고 그때 그땓 적절한 함수를 호출함.

이를 이용해 더 유연하고 expressvie한 인터페이스를 만들 수 있다.

``` cpp
    #include <iostream>
    
    // 함수 이름이 같아도 컴파일러가 알아서 어떤 add인지 추론해서 실행해줌
    int add(int a, int b) {
        return a+b   
    }
    
    double add(double a, double b) {
        return a + b   
    }
    
    int main() {
        int a = 5, b = 7;
        double x = 5.5, y = 7.5;
        
        std::cout << "+ of integer : " << add(a,b) << std::endl;
        std::cout << "+ of double : " << add(x,y) << std::endl; 
        
        return 0;
    }
```

### char
1. 함수의 이름은 같고, 인수가 달라야 한다. 리턴 타입만 다른 걸로는 충분하지 않다.
2. 타입이나 갯수중 하나는 달라야 한다. 인수 순서만 바뀐다고 구분 못함.
3. 애매하면 컴파일 에러


## 3.4 inline function
함수 호출의 overhead를 줄여줄 수 있는 성능 최적화 기능이다.

### overhead : 실제 작업 자체 외에 작업을 수행하는데 필요한 추가 작업을 의미

함수를 호출할 때의 경우 다름과 같은 요소들로 나눌 수 있다.

1. call setup : 콜 스택이 셋업되어야 한다.
새로운 스택 프레임을 생성하고, 리턴 주소를 저장하고, 필요한 레지스터 값을 저장

2. 인수 패싱 : 함수 호출자의 stack frame에서 호출되는 함수 스택 프레임으로 인수를 복사해준다.

3. 리턴 값 핸들링 : 호출된 함수가 실행이 완료되면 리턴값이 호출된 곳으로 반환된다.

여기서도 리턴값을 복사해 호출자의 스택 프레임에 전달한다.

4. call teardown : 호출된 함수가 리턴된 후, 콜 스택이 청소된다. 

저장된 레지스터 값을 복구하고, 호출된 함수의 스택 프레임을 제거하고 스택 포인터를 이전의 스택 프레임으로 업데이트한다.

//

cpp에서는 class 선언을 통한 맴버 함수가 많이 이용되는데, 이 경우 간단한 기능을 하는 함수들이 많이 만들어지고,

(생성자, 게터, 세터 등..)

함수를 여러 번 호출하게 되면 성능 저하가 발생한다. (콜 스택, 인수 전달, 리턴 등의 리소스 소모)

함수를 inline으로 선언하면 컴파일러에게 actual 함수 코드를 대체해야 한다고 알려줘서

호출 위치에서 함수를 인라인으로 확장하는 것이다. (함수 코드를 호출하는 장소에 바로 embed 해서)

이러면 호출이라는게 없어지게 됨.

호출 스택 설정, 인수 전달, 값 반환 등 함수 호출과 관련된 오버헤드를 줄여 성능을 향상시킬 수 있다.

``` cpp
    inline int add(int a, int b) {
        return a + b;   
    }
```

단, inline이 되는건 어디까지나 컴파일러가 결정한다. 

(gpt 말을 빌리자면 inline 키워드는 컴파일러에게 힌트가 되어줄 뿐)

너무 크거나 복잡한 함수는 inline으로 설정되지 않을 수도 있음.

컴파일 과정에서 인라인 함수 부분으로 호출한 부분을 치환하게 됨.

그렇다고 너무 많이 인라인을 사용하면 파일 크기가 커짐.

꼭 필요하다고 생각되는 곳에서만 이 키워드를 사용하고 나머지는 컴파일러에게 맡겨라.

너보다 컴파일러가 잘함 ㅎ


### stack frame 
also known as activation record, 프로그램에서 호출되는 함수에 대한 정보를 저장하는 데이터 구조

메모리의 영역인 콜 스택에서 생성되며, 함수 호출과 함수 호출에 연관된 데이터를 관리하기 위해 사용된다.

stack frame은 다음과 같은 값들을 가진다.

1. 지역 변수, 인수

지역 변수는 stack frame에 저장되고, 함수 리턴시 deallocated

인수도 여기 저장되고, 호출된 함수가 접근할 수 있다.

2. 리턴 주소
호출된 함수가 반환된 후, 실행이 재개되어야 할 호출자의 메모리 주소.

3. saved register

일부 cpu 레지스터는 함수 호출들을 거쳐도 보존 되어야 함. 이런 레지스터들은 스택 프레임에 저장되고, 함수 반환시 restore 된다.

함수가 호출되면 새로운 스택 프레임이 콜 스택 위에 쌓이고, 스택 포인터는 새 프레임을 포인트 하도록 업데이트 된다.

함수가 리턴되면, 스택 포인터는 다시 원래 프레임을 가리키게 되고, 현재 프레임은 deallocate 된다.

### register
cpu 안에 있는 작고 빠른 스토리지. 사용중인 데이터를 hold하거나, 계싼 결과를 바로 저장하기 위해 사용된다.

또, 중요 cpu state 정보를 저장하고 

(e.g. 현재 executing instruction을 가리키는 program counter, call stack의 top을 가리키는 stack pointer) 

레지스터는 함수 호출에 중요한 역할읗 한다. 함수에 인수를 전달하거나, 함수의 리턴값을 저장하거나.

또, 함수 실행 도중의 중간 결과나 일시적인 값들을 저장하기도 한다.

앞서 말한것처럼 호출자 함수의 상태가 오염되지 않도록 여러 함수 호출에 걸쳐 저장되고 복원되야 하는 경우도 있다.




## 3.5 template function
다른 타입이나 클래스들에 대해 각각 함수를 써주지 않도록 하는

ts의 제네릭 같은 기능임.

type placeholder (== template parameter)를 함수 정의에 적어주면

컴파일러가 적절히 맞는 버전을 생성해준다.

``` cpp
    template <typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
```

위 예시에서 typename T는 template parameter로 데이터 타입의

placeholder를 의미한다.

실제로 함수를 사용해 T 위치에 원하는 데이터 타입을 넣어주면

컴파일러가 그에 맞춰서 함수를 생성해준다.

``` cpp
    int main() {
        int x = 5, y = 10;
        swap<int>(x, y);
        
        double a = 3.5, b = 7.5;
        swap<double>(a,b)
        
        return 0;
    }
```

많은 경우 <type>도 안써줘도 컴파일러가 알아서 추론해줘서 명시해주지 않아도 됨.


## 3.6 recursion

재귀 함수 : 문제 해결을 위해 스스로를 호출하는 함수

복잡한 문제를 더 잘게 쪼개서 base case까지 내려가는 것이 컨셉이다.

base case란 바로 해결될 수 있는, 더 이상 반복하지 않아도 되는 문제의 가장 단순한 버전을 의미한다.

재귀 함수를 디자인할 때는 recursive case와 base case를 확인하는게 중요하다.

base case가 있어야 무한 루프에 빠지는걸 막을 수 있음.

가장 간단한 예시로 팩토리얼 계산하는 함수가 있음
``` cpp
    int factorial(int n) {
        if (n==0) {
            return 1;
        } else {
            return n * factorial(n-1)
        }
    }
```

## 3.7 arrays and pointers

### arrays
cpp의 배열은 뭐가 다른가..

go도 그렇고 자꾸 이걸 강조하더라. 배열의 요소들은 연속적인 메모리 주소를 가지게 된다.

고정된 숫자의 요소를 가진다.

정의는 요소의 타입과 수를 적어주면 되고,  초기값을 {} 에 넣어주면 값을 초기화할 수 있다.
``` cpp
    int numbers[5] = {1, 2, 3, 4, 5}
```

길이보다 적은 갯수로 초기화하면 나머지는 기본값으로 채워지게 되고,

길이를 설정하지 않았다면 초기값의 갯수로 컴파일러가 알아서 추론한다.

``` cpp
    int numbers[] = {1,2,3,4,5}
```

요소 접근, 수정은 다른 언어와 차이가 없으니 생략

- array bound check
cpp는 자동으로 배열의 범위를 체크해주지 않아서

조심하지 않으면 배열밖의 메모리에 접근할 수도 있다.

``` cpp
int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    for (int i =0; i < 6; i++) {
        std::cout << "Before func, num = " << numbers[i] << std::endl;
    }   
}
// numbers[5] 를 출력하면 전혀 다른 값이 나옴
```

- 배열 길이를 바꾸고 싶다면 동적 메모리 할당을 이용해 배열을 생성한다.
new 연산자를 이용해 heap 메모리를 할당하도록 해서 배열을 생성할 수 있고,

더 필요 없어지면 delete 연산자를 이용해 메모리 사용을 종료하면 된다.

``` cpp
    int arraySize = 5;
    int* numbers = new int[arraySize];
    
    int newSize = 10;
    int* newNumbers = new int[newSize]
    

    for (int i = 0; i < arraySize; ++i) {
        newNumbers[i] = numbers[i]
    }
    
    delete[] numbers;
    
    numbers = newNumbers;
    arraySize = newSize;
    
    // ... 할거 하고
    
    // 메모리를 돌려줌
    delete[] numbers;
```

다만 이런 raw pointer와 동적 메모리 할당은 에러가 터질 여지가 많아

요즘엔 그닥 추천되지 않고, 대신 표준 라이브러리 std::vector를 사용해

자동으로 동적 메모리 할당과 resize를 진행한다.

``` cpp
    #include <vector>
    #include <iostream>
    
    int main() {
        // 5개 요소를 가진 벡터 생성
        std::vector<int> numbers = {1, 2, 3, 4, 5}
        // use the vector as needed..
        
        // resize vector
        // 자동으로 resize하고 새 요소를 초기화
        numbers.resize=(10)
        
        // 이렇게쓰면 컴파일 에러남. 벡터는 이 함수가 받는 타입이 아니므로..
        // std::cout << numbers << std::endl;
        
        for (int number : numbers) {
            std::cout << number << " ";   
        }
        std:;cout << ste::endl;
    }
```

### pointers
다른 변수의 메모리 주소를 저장하는 변수이다. 이를 이용해 메모리를 직접 조작해

더 효율적이고 유연한 코드를 작성할 수도 있다.

1. declare, initialize pointer
포인터응 선언하려면 포인터가 가리키는 변수의 타입과 *을 이용한다.
int를 가리키는 포인터를 선언하려면 int* 처럼 해주면 된다.

& 연산자를 이용해 포인터가 가리킬 변수를 지정할 수 있다.

``` cpp
    int* intPtr;
    
    int myVar = 42;
    int* intPtr2 = &myVar;
```

2. dereferencing pointer
메모리 주소에 저장된 값에 접근하기 위해 dereference 연산자 *을 사용한다.

``` cpp
    int myVar = 42;
    int* intPtr = &myVar;
    
    int value = *intPtr;
    
```

3. pointer를 이용해 값 변경
``` cpp
    int myVar = 42;
    int* intPtr = &myVar;
    
    *intPtr = 24;
    
    //
    
    int myArray[3] = {10, 20, 30}
    int* intPtr = myArray;
    
    intPtr++;
```

전술했듯이 요즘에는 vector를 사용하는 것이 더 안전하다.


### pointer & array
포인터로 배열을 찍으면 그 배열의 1st 요소를 가리킴.

+ 배열은 연속적으로 메모리를 차지하므로 주소도 연속적이고,

> 포인터 값에 1만 더하면 다음 요소를 가리키게 된다.

``` cpp
    int myArray[5] = {1, 2, 3, 4, 5}
    int *ptr = myArray;
    
    std::cout <<< "1st : " << *ptr << std::endl;
    std::cout <<< "2nd : " << *(ptr+1) << std::endl;
    std::cout <<< "3rd : " << *(ptr+2) << std::endl;
    
    *(ptr+1) = 42;
    
    std::cout << myArray[1] << std::endl; // 42
    return 0;
```

### std :: 
std는 cpp 표준 lib의 namespace다. namespace는 연관된 함수, 클래스, 식별자등을 묶어

코드 내에서 충돌이 발생하는 것을 막기 위한 방법이다. 

iostream은 cpp 표준 라이브러리의 하나로, input, ouput 관련 작업을 담당한다.

cout, endl 같은것 이외에도 std:: 에 속한 요소들은 많다.

std::vector 같은 데이터 구조체도 있고,

std::sort 같은 알고리즘 관련 메서드도 있고,

반복을 위한 std::iterator, std::reverse_iterator 등등

굉장히 많은데, std:: 네임 스페이스는 이런 수많은 요소들을 다른 라이브러리 (제3자발)의

동일한 요소들과 충돌이 나지 않게 해준다.

#### Eigen

하나의 예로 eigen 라이브러리가 있는데, 한 번 써보고 싶다.

이건 npm 같은것도 없나? 직접 홈페이지 들어가서 인스톨을 하라네..

일단 패스



## 3.8 Pointer-to-Pointer and Multi-dimensional Arrays

cpp 에서는 포인터를 가리키는 포인터 "pointer to pointer"를 사용할 수 있다.

다중 배열이나 동적 데이터 구조를 다룰 때 유용할 수 있다.

### pointer-to-pointer

이는 별 2개를 써서 선언한다. (**)

``` cpp
    int **ptr_to_ptr;
    
    int rows = 3;
    int cols = 4;
    
    // allocate memory for the pointer
    int **matrix = new int*[rows];
    
    // allocate memory for actual data
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]   
    }
    
    // 이러면 matrix는 동적 할당된 2차 배열로 row, col을 가짐.
    
    int matrix[3][4] = 42;
```

* new는 힙 메모리를 새로운 객체나 배열에 할당하기 위해 사용된다.

## 3.9 dynamic memory allocation

동적 메모리 할당은 런타임에서 메모리를 할당, 취소하는 프로세스를 의미한다.

전에 본 것처럼 new와 delete 키워드가 각각을 담당함.

### 동적 메모리 할당

하나의 객체에 동적으로 메모리를 할당하려면 new 키워드를 사용한다.

``` cpp
    // int에 대한 메모리를 heap에 할당하고, 포인터를 리턴한다.
    int *ptr = new int;
    
    int *array = new int[10]
```

### 동적 메모리 deallocating 
delete 키워드를 사용한다.

``` cpp
    delete ptr;
    
    delete[] array;
```

### 메모리 할당 실패 handling
메모리 부족 등의 이유로 new를 이용한 메모리 할당이 실패할 경우,

std::bad_alloc 타입의 예외가 반환된다.

이는 try-catch block을 이용해 처리할 수 있다.

``` cpp
    int *ptr;
    try {
        ptr= new int[10000000000];
    } catch(const std::bad_alloc &e) {
        // e는 예외 object에 대한 reference
        // exception 객체의 함수 what()을 사용해 error 설명을 확인 가능
        // 단, 이 exception은 성능적으로 비싸다. 말그대로 예외적인게 아니면 사용하지 않는게 좋다.
        std:cerr << "memory alloc failed : " << e.what() << std::endl;
    }
```

### 자동 메모리 관리를 위한 스마트 포인터 사용
C++ 11은 알아서 메모리를 관리해주는 스마트 포인터를 도입헀다.

가장 많이 사용되는 스마트 포인터는 `std::unique_ptr`, `std::shared_ptr` 로

스코프를 벗어나거나 더 이상 대상에 대한 참조가 없는 경우 자동으로 메모리를 deallocate한다.

``` cpp
    #include <memory>
    
    std::unique_ptr<int> ptr(new int(42));
    
    // ptr로 뭔가 막 하고, scope에서 벗어나면 자동으로 deallocate됨
```

이 동적 메모리 할당은 cpp의 

특히 lifetime이나 size가 변화하는 데이터 구조를 사용할 때 중요한 부분이다.

메모리 관리르 잘 해야 메모리 누수나 다른 이슈들을 방지할 수 있다.


## 3.10 Common pitfalls and best practices
포인터, 배열, 동적 메모리 할당에서 주의할 점에 대해 알아보자.

### memory leaks
할당만 되고 프로그램이 종료될 때까지 deallocate가 되지 않을 때 발생한다.

이렇게 되면 사용되지 않는 메모리가 누적되고, 필요 이상의 메모리를 소모하게 된다. 

항상 delete, delete[] 명령어를 사용해 사용하지 않는 메모리를 deallocate해야한다.

``` cpp
    int *array = new int[10];
    // do sth..
    
    delete[] array;
```

### dangling pointers

dangling pointer는 deallocate 되었거나 더 이상 valid하지 않는 메모리를 가리키는 포인터이다.

이를 이용해 메모리에 접근하면 undefined behavior를 마주할 수 있다.

이를 방지하려면 포인터가 가리키는 메모리를 deallocate한 후, 포인터를 nullpte로 설정할 것.

``` cpp
    int *ptr = new int;
    
    // do sth..
    
    delete ptr;
    ptr = nullptr;
    
```

### double deletion

동일한 메모리를 두 번 이상 지우려고 할 때 나타난다. 마찬가지로 undefined behavior가 나타남.

이 또한 마찬가지로 방지하려면 nullptr로 잘 설정해줘야 한다.

``` cpp
    int *ptr = new int;
    delete ptr;
    ptr = nullptr;
```

### using uninitialized pointers
초기화하지 않은 호인터는 어딜 보고 있을지 모름. 사용전에 초기화 꼭 해라.

특정 valid addr로 지정하던가, nullptr로 설정하던가

### prefer smart pointer
자동으로 가리키는 대상의 메모리를 관리하는 스마트 포인터가 cpp 11부터 도입되었다.

raw pointer보다 이걸 쓰는걸 언제든 가능할 때는 고려해볼 것.

``` cpp
    #include <memory>
    
    std::unique_ptr<int[]> array(new int[10]);
```

- unique_ptr
    대상에 대한 exclusive ownership을 가짐. 어떤 시점에서든 하나의 unique_ptr 인스턴스가 대상을 소유한다.
    스코프에서 벗어나거나 명시적으로 리셋되면 가리키던 대상은 자동으로 삭제된다.
    
    공유되선 안되거나 엄격한 소유권을 주고싶을때 사용한다.
    
    복사될 수 없으므로 소유권을 한 인스턴스에서 다른 인스턴스로 이동시키는 것만 가능하다.
    
- std::shared_ptr
    대상에 대한 공유된 소유권을 의미. 여러 개의 shared_ptr 인스턴스가 동일 대상을 소유할 수 있고,
    
    모든 shared_ptr이 제거되면 대상도 삭제된다.
    
    shared_ptr은 대상을 쇼유하는 인스턴스가 몇 개인지를 추적한다. 0이 되면 대상은 삭제된다.
    

## 3.11 Best practices for using arrays and pointers in C++

cpp에서 array, pointer를 잘 사용하기 위한 몇 가지 팁

1. standard containers 사용 : 
raw array나 포인터를 사용하기보다, std::vector, std::array, and std::list 같은 standard containers를 사용한다. 사용도 쉽게, 추가적인 기능도 있고. 메모리 관리도 용이하다.

2. smart pointers 사용:
raw pointer보다는 std::unique_ptr, std::shared_ptr, and std::weak_ptr 등의 스마트 포인터를 사용해 동적 메모리 할당을 진행한다.
더 이상 사용되지 않는 메모리를 자동으로 풀어주고, 소유권 semantic을 시행한다.


3. pointer arithmetic 사용하지 않기:
Pointer arithmetic은 가독성도 별로고 에러가 터질 가능성이 높다.
포인터 산술계산 대신, 컨테이너 내의 요소에 접근하기 위해 반복문을 사용한다.

4. 포인터 초기화
항상 포인터를 초기화해준다. 아직 대상이 없다면 nullptr로 초기화하는 것이 좋다.

5. Check for null pointers:
포인터를 dereference 하기 전에 항상 null ptr인지를 확인한다. 

6. pointer-to-pointer, 다중 배열 사용시에는 주의:
고차 데이터를 사용시 ptr_to_ptr이나 다중 배열은 에러가 터지기 쉽고, 헷갈린다. 대신 std:vector 같은 표준적인 컨테이너를 사용한다.
e.g. std::vector<std:vector<int>>

7. array decay에 주의:
배열을 함수에 전달할 때 배열은 포인터로 분해된다. 배열에 있는 정보를 잃을 수도 있으므로 주의해야 한다.
표준 컨테이너를 사용하거나, 고정된 크기 배열을 함수에 전달시 std::array를 사용한다.

8. 메모리 할당 실패를 잘 처리할 것:
동적 메모리 할당을 위해 new나 malloc을 사용 시, 항상 반환된 포인터가 valid 한지 확인한다. nullptr이라면 적절한 예외 처리를 거칠 것.

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
### 4.2.1 