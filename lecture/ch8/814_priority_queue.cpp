    #include <iostream>
    #include <queue>
    
    int main() {
        std::priority_queue<int> numbers;
        
        // 이 순서로 넣어도 3이 가장 위로 정렬됨
        numbers.push(1);
        numbers.push(3);
        numbers.push(2);
        
        std::cout << "top element : " << numbers.top() << std::endl;
        
        numbers.pop();
        
        if(!numbers.empty()) {
            std::cout << "priority queue is not empty" << std::endl;   
        }
        
        return 0;   
    }