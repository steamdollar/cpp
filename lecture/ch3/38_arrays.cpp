    #include <vector>
    #include <iostream>
    
    int main() {
        // 5개 요소를 가진 벡터 생성
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        // use the vector as needed..
        
        // resize vector
        // 자동으로 resize하고 새 요소를 초기화
        numbers.resize(10);
        
        for (int number : numbers) {
            std::cout << number << " ";   
        }
        std::cout << std::endl;
    }