#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void convertToUpper(FILE* inputFile, FILE* outputFile) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(toupper(ch), outputFile);
    }
}

double measureTime(char* inputFile) {
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen("output.txt", "w");
    clock_t start = clock();
    
    convertToUpper(input, output);

    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    fclose(input);
    fclose(output);

    return timeTaken;
}

int main() {
    char* fileSizes[] = {"200MB.txt", "400MB.txt", "600MB.txt", "800MB.txt", "1000MB.txt"};
    double timeTaken[5];

    for (int i = 0; i < 5; i++) {
        timeTaken[i] = measureTime(fileSizes[i]);
    }

    // Print the time taken
    for (int i = 0; i < 5; i++) {
        printf("Time taken for %s: %f seconds\n", fileSizes[i], timeTaken[i]);
    }

    return 0;
}
