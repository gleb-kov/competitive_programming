n = int(input())
ways = []
ways.append([])
k = n//2*9
for i in range (10): ways[0].append(1)
for i in range(10, k+1): ways[0].append(0)
for i in range(1, n//2):
    ways.append([])
    for j in range(k+1):
        sum = int(0)
        for w in range(max(0,j-9),j+1): sum+=ways[i-1][w]
        ways[i].append(sum)
res = int(0)
for i in range(k+1): res+= ways[n//2-1][i]**2
print(res)

