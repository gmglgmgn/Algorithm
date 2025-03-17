import sys

input = sys.stdin.readline
INF = 10 ** 6

while True:
    i = input().split()
    if not i:  # EOF 가 아니면
        break
    a, b = map(int, i)
    print(a + b)