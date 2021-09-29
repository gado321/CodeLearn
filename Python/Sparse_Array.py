n = int(input())
a = [input() for _ in range(n)]
q = int(input())
for _ in range(q):
    print(a.count(input()))