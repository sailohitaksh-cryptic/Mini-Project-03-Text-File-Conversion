#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>

void convertToUpper(std::string inputFile, std::string outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);
    std::string line;
    
    while (std::getline(input, line)) {
        std::transform(line.begin(), line.end(), line.begin(), ::toupper);
        output << line << "\n";
    }
}

double measureTime(std::string inputFile) {
    std::string outputFile = "output.txt";
    std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    
    convertToUpper(inputFile, outputFile);

    std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
    double timeTaken = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count();

    return timeTaken;
}

int main() {
    std::string fileSizes[] = {"200MB.txt", "400MB.txt", "600MB.txt", "800MB.txt", "1000MB.txt"};
    double timeTaken[5];

    for (int i = 0; i < 5; i++) {
        timeTaken[i] = measureTime(fileSizes[i]);
    }

    // Print the time taken
    for (int i = 0; i < 5; i++) {
        std::cout << "Time taken for " << fileSizes[i] << ": " << timeTaken[i] << " seconds\n";
    }

    return 0;
}
