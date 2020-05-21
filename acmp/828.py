n, k = map(int, input().split())
all = []
all.append([])
 
for i in range(0, k): all[0].append(0)
all[0][0] = 1
 
for i in range (1, n):
    all.append([])
    for j in range(0, k):
        r = all[i-1][j]*(j+1)
        if j>0: r+=all[i-1][j-1]
        all[i].append(r)
sum = 0
for i in range(0, k): sum+=all[n-1][i]
print(sum)

