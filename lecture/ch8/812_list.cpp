#include <iostream>
#include <list>
    
int main() {
        std::list<int> numbers = {1,2, 3, 4, 5};
        
        numbers.push_front(0);
        
                for (const auto &number : numbers) {
            std::cout << number << " ";
        }   
        std::cout << std::endl;
        numbers.pop_front();
        
        for (const auto &number : numbers) {
            std::cout << number << " ";
        }   
        std::cout << std::endl;
        
        return 0;
}