n, m = [int(_) for _ in input().split()]
a = [0] * (n + 2)
maxi = -1e17
tmp = 0
for i in range(1,m + 1):
    x, y, k = map(int, input().split())
    a[x] += k
    a[y + 1] += -k
for i in a:
    tmp += i
    maxi = max(maxi,tmp)
print(maxi)