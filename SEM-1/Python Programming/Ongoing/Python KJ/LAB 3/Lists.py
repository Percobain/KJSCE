str = input()

# create dictionary to store key value pair
dict = {}

for i in str:
    # if i already appears as key in dict, increment the count
    if i in dict:
        dict[i] += 1

    # else i appears for the first time, add to dict
    else:
        dict[i] = 1

# printing result 
print(dict)

