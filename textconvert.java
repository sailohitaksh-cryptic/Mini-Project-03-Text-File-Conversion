import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ConvertToUpper {
    public static void convertToUpper(String inputFile, String outputFile) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
        String line;
        
        while ((line = reader.readLine()) != null) {
            writer.write(line.toUpperCase());
            writer.newLine();
        }
        
        reader.close();
        writer.close();
    }
    
    public static double measureTime(String inputFile) throws IOException {
        String outputFile = "output.txt";
        long startTime = System.nanoTime();
        
        convertToUpper(inputFile, outputFile);
        
        long endTime = System.nanoTime();
        double timeTaken = (endTime - startTime) / 1e9;
        
        return timeTaken;
    }
    
    public static void main(String[] args) throws IOException {
        String[] fileSizes = {"200MB.txt", "400MB.txt", "600MB.txt", "800MB.txt", "1000MB.txt"};
        double[] timeTaken = new double[5];
        
        for (int i = 0; i < 5; i++) {
            timeTaken[i] = measureTime(fileSizes[i]);
        }
        
        // Print the time taken
        for (int i = 0; i < 5; i++) {
            System.out.printf("Time taken for %s: %.6f seconds\n", fileSizes[i], timeTaken[i]);
        }
    }
}
