#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1,5,9,10,2};
    replace(numbers.begin(), numbers.end(), 5, 42);
    
    for (const auto &num:numbers) {
        std::cout << num << " ";   
    }
    std::cout << std::endl;
    
    return 0;
}