import sys
input = sys.stdin.readline


while 1:
    N, M = map(int, input().split())
    if N + M == 0:
        break
    print(N + M)