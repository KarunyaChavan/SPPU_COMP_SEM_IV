count = 0
for i in range(1,21):
    flag = 0
    for j in range(1,i):
        if(i%j==0):
            flag = 1
            break
    if(flag!=1):
        count += 1
print(count)