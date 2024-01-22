import numpy as np

arr = eval(input("Enter the array: "))

max_val = np.max(arr)
print(f"The Maximum value in the array is {max_val}")

sorted_arr = np.sort(arr)
print(f"the sorted array is {sorted_arr}")

search = int(input("Enter a number to search: "))
find = np.where(sorted_arr == search)

if len(find[0]) > 0:
    print(f"The number {search} is found at index {find[0][0]} in the sorted array")
else:
    print(f"The number {search} is not found in the array")'

import numpy as np

# define the data for the number of hours worked by each employee in 4 weeks
data = {
    'VIPUL': [40, 40, 40, 40],
    'RISHI': [42, 42, 42, 42],
    'VIVEK': [45, 45, 45, 45],
    'VIBHU': [38, 38, 38, 38],
    'VIDITA': [30, 30, 30, 30]
}

# create numpy arrays for each employee
for key in data.keys():
    data[key] = np.array(data[key])

# print duty chart
print("\nDuty Chart:")
for key in data.keys():
    print("\n{}: {}".format(key, data[key].shape))

# calculate sum of hours in month for each employee
monthly_hours = {key: np.sum(data[key]) for key in data.keys()}
print("\nSum of hours in Month of each employee:")
for key in monthly_hours.keys():
    print("\n{}: {}".format(key, monthly_hours[key]))

# search for employee securing highest working hours
max_hours = max(monthly_hours.values())
max_employee = [key for key, value in monthly_hours.items() if value == max_hours]
print("\nSearch employee securing highest working hours . Name of Employee: {}".format(max_employee))

