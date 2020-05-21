import math
res = int(1)
all = input().split()
for i in range(1, min(int(all[0])+1, 5)):
    a, b = map(int, all[i].split(':'))
    if a > 25 or b > 25:
        r = int(pow(2, (a + b - 48) / 2))
        r = r * 16123801841550
    else: r = int(math.factorial(a + b - 1) / (math.factorial(min(a, b)) * math.factorial(a + b - 1 - min(a, b))))
    res = res * r
 
if(all[0]=='5'):
    a, b = map(int, all[5].split(':'))
    if a > 15 or b > 15:
        r = int(pow(2, (a + b - 28) / 2))
        r = r * 20058300
    else:
        r = int(math.factorial(a + b - 1) / (math.factorial(min(a, b)) * math.factorial(a + b - 1 - min(a, b))))
    res = res * r
 
print(res)

