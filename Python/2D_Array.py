a = []
sumMax = -100
for i in range(6):
    a.append([int(x) for x in input().split()])
for r in range(4):
    for c in range(4):
        tmp = a[r][c] + a[r][c+1] + a[r][c+2] + \
            a[r+1][c+1] + a[r+2][c] + a[r+2][c+1] + a[r+2][c+2]
        sumMax = max(tmp,sumMax)
print(sumMax)
