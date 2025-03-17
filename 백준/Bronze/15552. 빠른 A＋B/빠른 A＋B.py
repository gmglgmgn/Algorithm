from sys import stdin, setrecursionlimit

# import sys as s
# input = s.stdin.readline()
input = stdin.readline
setrecursionlimit(10**5)

N = int(input().strip())

for _ in range(N):
    a, b = map(int, input().split())
    print(a + b)

