#include <iostream>
    #include <map>
    int main() {
        std::map <std::string, int> ages;
        
        ages["Alice"] = 20;
        ages["Bob"] = 25;
        
        std::cout << "Alice's age : " << ages["Alice"] << std::endl;
        
        // ages map 안에 있는 요소들 전부를 순회
        for (const auto &pair : ages) {
            // pair.first는 key, second는 value
            std::cout << pair.first << " : " << pair.second << std::endl;   
        }
        
        return 0;
    }