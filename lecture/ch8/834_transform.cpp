#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1,2,3,4,5};
    std::vector<int> squares(5);
    
    transform(numbers.begin(), numbers.end(), squares.begin(), [](int x) {return x*x;});
    
    for(const auto& num:squares) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}