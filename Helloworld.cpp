#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    const std::string filename = "integers.txt";
    
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return 1;
    }
    
    std::vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();


    std::sort(numbers.begin(), numbers.end());
    
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return 1;
    }
    
    for (const int &val : numbers) {
        outputFile << val << " ";
    }
    outputFile.close();
    
    std::cout << "File sorted and saved successfully." << std::endl;
    return 0;
}
