n, q = map(int, input().split())
lastAnswer = 0
a = [[] for x in range(n)]
while q > 0:
    q -= 1
    t, x, y = map(int, input().split())
    idx = (x ^ lastAnswer) % n
    if t == 1:
        a[idx].append(y)
    else:
        lastAnswer = a[idx][y % len(a[idx])]
        print(lastAnswer)
