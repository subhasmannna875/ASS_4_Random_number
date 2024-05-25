import numpy as np
import matplotlib.pyplot as plt

# Load the random numbers from the file
random_numbers = np.loadtxt('exponential_random_numbers.txt')

# Plot the density histogram of the random numbers
plt.hist(random_numbers, bins=50, density=True, alpha=0.6, color='g', label='Generated Data')

# Define the exponential PDF
mean = 0.5
x = np.linspace(0, max(random_numbers), 1000)
pdf = (1/mean) * np.exp(-x/mean)

# Plot the theoretical exponential PDF
plt.plot(x, pdf, 'r-', lw=2, label='Exponential PDF')

plt.xlabel('Value')
plt.ylabel('Density')
plt.title('Density Histogram and Exponential PDF')
plt.legend()
plt.show()