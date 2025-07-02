import sys
input = sys.stdin.readline

N, M = map(int, input().split())
cards = list(map(int, input().split()))
res = 0

for i in range(0, N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            s = cards[i] + cards[j] + cards[k]
            if M >= s > res:
                res = s

print(res)