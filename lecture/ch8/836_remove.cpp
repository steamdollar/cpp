#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string input = "Does not matter since they are going to start clearing.";
    std::cout << "original: " << input << std::endl; 
    
    input.erase(std::remove(input.begin(), input.end(), 'a'), input.end());
    
    std::cout << "modified: " << input << std::endl;
    
    return 0;
}