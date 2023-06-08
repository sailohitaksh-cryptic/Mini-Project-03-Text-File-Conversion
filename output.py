import matplotlib.pyplot as plt
import pandas as pd

file_sizes = [200, 400, 600, 800, 1000]
c_times = [1.23, 2.45, 3.68, 4.91, 6.13]
cpp_times = [1.34, 2.67, 4.00, 5.32, 6.65]
java_times = [1.45, 2.89, 4.33, 5.76, 7.20]
r_times = [2.56, 5.12, 7.68, 10.24, 12.80]
python_times = [3.67, 7.34, 11.01, 14.68, 18.35]

# Create a table
table_data = {'C': c_times, 'C++': cpp_times, 'Java': java_times, 'R': r_times, 'Python': python_times}
table = pd.DataFrame(table_data, index=file_sizes)
table.index.name = 'File Size (MB)'  # Set the name of the index
print(table)

# Create a graph
plt.plot(file_sizes, c_times, marker='o', label='C')
plt.plot(file_sizes, cpp_times, marker='o', label='C++')
plt.plot(file_sizes, java_times, marker='o', label='Java')
plt.plot(file_sizes, r_times, marker='o', label='R')
plt.plot(file_sizes, python_times, marker='o', label='Python')
plt.xlabel('File Size (MB)')
plt.ylabel('Time (seconds)')
plt.legend()

# Show the table and graph
plt.show()
