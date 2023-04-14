#include <iostream>

void modify_value(int &x) {
    x = x * 2;
    std::cout << "inside fx, x= " << x << std::endl;
}

int main() {
    int num = 5;
    std::cout << "Before func, num = " << num << std::endl;
    modify_value(num);
    std::cout << "After func, num = " << num << std::endl;
    return 0;
}