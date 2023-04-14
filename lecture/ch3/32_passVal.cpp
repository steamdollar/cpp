#include <iostream>

void modify_value(int x) {
    x = x*2;
    std::cout << "Inside func, x = " << x << std::endl;   
}

int main() {
    int num = 5;
    std::cout << "Before call func, num = " << num << std::endl;
    
    modify_value(num);
    
    std::cout << "after func, num = " << num << std::endl;
    return 0;
}