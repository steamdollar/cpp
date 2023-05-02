    #include <iostream>
    #include <vector>
    #include <numeric>
    
    int main() {
        std::vector<int> v1 = { 1,2,3,4,5};
        std::vector<int> v2 = { 6,7,8,9,10};
        
        int product = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0); 
        
        std::cout << "inner product  " << product << std::endl;
        
        return 0;
    }