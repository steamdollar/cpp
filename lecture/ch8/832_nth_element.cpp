#include <algorithm>
#include <vector>
#include <iostream>


int main() {
    std::vector<int> numbers = {5,3,1,4,2};
    std::nth_element(numbers.begin(), numbers.begin() + 2, numbers.end());
    
    for ( int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // 2 1 3 4 5
}
