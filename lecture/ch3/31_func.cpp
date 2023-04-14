#include <iostream>

// function prototype
int add(int a, int b);

int main() {
    int num1 = 5, num2 = 7;
    int result = add(num1, num2);
    std::cout << num1 << " + " << num2 << " = " << result << std::endl;
    return 0;
}

// function definition
int add(int a, int b) {
    return a+b;
}
