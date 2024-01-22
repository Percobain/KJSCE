f = open('demofile.txt', 'r')
while True :
    data = f.readline( )
    if data == '' :
        break
print(data)
f.close( )
