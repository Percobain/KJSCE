import matplotlib.pyplot as plt
import numpy as np

savings = np.array(["20","30","40","50"])
freq = np.array(["105","195","27","73"])

plt.bar(savings, freq)
plt.show()

import matplotlib.pyplot as plt

# saving data
saving_percent = [20, 30, 40, 50]

# frequency data
frequency = [105, 195, 27, 73]

# creating bar chart
fig, ax = plt.subplots()

# bar chart for saving
ax.bar(saving_percent, frequency, color='b', alpha=0.)

# x-axis and y-axis labels
ax.set_xlabel('Saving in %')
ax.set_ylabel('Frequency of Number Employee')

# title for the plot
ax.set_title('Bar Chart for Saving in % and Frequency of Number Employee')

# show the plot
plt.show()

# import matplotlib.pyplot as plt
# import numpy as np

# savings = np.array(["20","30","40","50"])
# freq = np.array([56,97,34,60])

# fig, ax = plt.subplots()

# # converting frequencies to percentages
# freq_percent = freq / freq.sum() * 100

# ax.pie(freq_percent, labels=savings)

# ax.set_xlabel("Saving in % ")
# ax.set_ylabel('Frequency of Number Employee')

# ax.set_title("Financial Analysis of Prolog Employee")

# plt.show()

# import matplotlib.pyplot as plt
# import numpy as np

# # Function for the first subplot
# def f(x):
#     return x**2 + 5*x + 10

# # Creating the subplots
# fig, axes = plt.subplots(2, 1, figsize=(6, 8))

# # First subplot: plotting the quadratic function
# x = np.linspace(-5, 5, 100)
# y = f(x)
# axes[0].plot(x, y, label='y = x^2 + 5x + 10', color='red')
# axes[0].set_xlabel('x')
# axes[0].set_ylabel('y')
# axes[0].set_title('Quadratic Function')
# axes[0].legend()
# axes[0].grid(True)

# # Second subplot: creating a bar chart
# categories = ['Category A', 'Category B', 'Category C', 'Category D', 'Category E']
# values = [15, 10, 5, 12, 8]

# axes[1].bar(categories, values, color='green')
# axes[1].set_xlabel('Categories')
# axes[1].set_ylabel('Values')
# axes[1].set_title('Bar Chart')
# axes[1].legend()
# axes[1].grid(True)

# # Displaying the plot
# plt.show()