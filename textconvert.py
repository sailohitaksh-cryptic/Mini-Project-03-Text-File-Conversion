import time

def convert_to_upper(input_file, output_file):
    with open(input_file, 'r') as input_f, open(output_file, 'w') as output_f:
        for line in input_f:
            output_f.write(line.upper())

def measure_time(input_file):
    output_file = 'output.txt'
    start_time = time.time()

    convert_to_upper(input_file, output_file)

    end_time = time.time()
    time_taken = end_time - start_time

    return time_taken

if __name__ == '__main__':
    file_sizes = ['200MB.txt', '400MB.txt', '600MB.txt', '800MB.txt', '1000MB.txt']
    time_taken = []

    for file in file_sizes:
        time_taken.append(measure_time(file))

    # Print the time taken
    for i in range(len(file_sizes)):
        print(f"Time taken for {file_sizes[i]}: {time_taken[i]} seconds")
