import math

all = []
for i in range(0, 101): all.append(0)
all[0] = 1
c = [all]
for i in range(1, 101):
    c.append([1])
    for j in range(1, 101):
        c[i].append(c[i-1][j]+c[i-1][j-1])

n = int(input())
dp = [0, 0] #0 and 1 playa expected value
for i in range(2, n+1):
    #i players
    sum = 0
    pow2 = 0
    for j in range(1, i):
        pow2 += c[i][j]
        sum+=dp[j]*c[i][j]
    dp.append((sum+3**(i-1))/pow2)
print("%.10f" % dp[n])
