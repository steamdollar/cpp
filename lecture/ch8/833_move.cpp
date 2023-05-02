#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> source = {"hello", "world"};
    std::vector<std::string> destination(2);
    
    move(source.begin(), source.end(), destination.begin());
    
    // hello, world
    for(const auto& word: destination) {
        std::cout << word << std::endl;
    }
    
    // "", ""
    for(const auto& word: source) {
     std::cout << word  << std::endl;   
    }
    
    return 0;
}