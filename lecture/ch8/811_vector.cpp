#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    
    std::cout << "first element : " << numbers[0] << std::endl;
    
    numbers.push_back(6);
    
    numbers.pop_back();
    
    for (const auto &number : numbers) {
        std::cout << number << " ";   
    }
    std::cout << std::endl;
    
    return 0;
}