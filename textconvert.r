convertToUpper <- function(inputFile, outputFile) {
  input <- file(inputFile, "r")
  output <- file(outputFile, "w")
  line <- readLines(input)
  
  for (i in 1:length(line)) {
    writeLines(toupper(line[i]), output)
  }
  
  close(input)
  close(output)
}

measureTime <- function(inputFile) {
  outputFile <- "output.txt"
  startTime <- Sys.time()
  
  convertToUpper(inputFile, outputFile)
  
  endTime <- Sys.time()
  timeTaken <- difftime(endTime, startTime, units = "secs")
  
  return(timeTaken)
}

fileSizes <- c("200MB.txt", "400MB.txt", "600MB.txt", "800MB.txt", "1000MB.txt")
timeTaken <- numeric(5)

for (i in 1:length(fileSizes)) {
  timeTaken[i] <- measureTime(fileSizes[i])
}

# Print the time taken
for (i in 1:length(fileSizes)) {
  cat("Time taken for", fileSizes[i], ":", timeTaken[i], "seconds\n")
}
