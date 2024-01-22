n = (int)(input("Enter a number : "))
sum = 0
num = n
while num!= 0:
    rem =(int)(num % 10)
    rem  = rem ** 3
    
    sum += rem
    num = num/10
    
print(sum)
if(sum == n):
    print("It is an armstrong number")
else:
    print("It is not an armstrong number")


