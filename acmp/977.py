import math
n = int(input())
r = 0
for k in range(0, n+1):
    r += ((-1)**(n-k))*(2**(k*(k-1)//2))*(math.factorial(n)//math.factorial(k)//math.factorial(n-k))
print(r)

