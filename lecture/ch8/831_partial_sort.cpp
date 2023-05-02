#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {5,3,1,4,2};
    std::partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end());
    
    for (int num : numbers) {
        std::cout << num << " ";   
    }
    // 1 2 3 5 4
    
    return 0;
}

