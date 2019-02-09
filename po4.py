powers = [pow(4, i) for i in range(17)] #create list with powers of 4 from 0 to 16, as 4^16 > 20000000000
for _ in range(int(input())):           #iterate given number of times
    i = int(input()[:-1])               #Enter a number and cut its last digit
    for p in range(len(powers)):        #Iterate over powers
        if powers[p] > i:               #If a power is greater than the number
            print(powers[p-1])          #Print the previous one
            break
