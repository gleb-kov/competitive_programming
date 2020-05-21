import re
 
n = int(input())
t = []
cost = []
for i in range(0, n):
    name,s = map(str, input().split())
    t.append(name)
    cost.append(int(s))
 
k = int(input())
for i in range(0, k):
    name, all = input().split()
    col = re.split(r'\s+', re.sub(r'[\[\]]', ' ', all).strip())
    #print(name, col)
    curcost = -1
    for j in range(0, n):
        if t[j] == name: curcost = cost[j]
    j = len(col)-2
 
    while j>0:
        curcost = 24+int(col[j])*curcost
        j-=1
    print(curcost)

