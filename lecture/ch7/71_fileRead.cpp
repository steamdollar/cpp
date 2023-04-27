#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    
    if(inputFile.is_open() && outputFile.is_open()) {
        int number;
        while (inputFile >> number) {
            int doubledNumber = number * 2;
            outputFile << doubledNumber << std::endl;
        }
        
        inputFile.close();
        outputFile.close();
        
    }   else {
        std::cerr << "unable to open" << std::endl;
    }
    
    return 0;
}