n, k = map(int, input().split())
n = n*2
dp = []
 
for i in range(0, n+1):
    dp.append([])
    for j in range(0,n+1):
        dp[i].append([])
        for e in range(0, k+1):
            dp[i][j].append(0)
 
dp[0][0][0] = 1
 
for i in range(1, n+1):
    for j in range(0, n+1):
       for e in range(j, k+1):
            if j > 0 and e == j: dp[i][j][e] += dp[i - 1][j - 1][e - 1] #when we add ( and plus 1 to balance and max deep
            dp[i][j][e] += dp[i-1][j-1][e]
            if j< n: dp[i][j][e]+=dp[i-1][j+1][e]
print(dp[n][0][k])

