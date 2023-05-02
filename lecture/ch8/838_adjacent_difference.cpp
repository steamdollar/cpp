#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

int main() {
    std::vector<int> numbers = { 1, 2, 4, 7, 11};
    std::vector<int> result(numbers.size());
    
    std::adjacent_difference(numbers.begin(), numbers.end(), result.begin());
    
    std::cout << "Adjacent diff : ";
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    // 1 1 2 3 4 - 첫 번째 1은 첫 요소를 복사해옴
    
    
    return 0;
}