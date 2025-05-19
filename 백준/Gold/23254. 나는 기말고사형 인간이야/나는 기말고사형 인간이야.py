import sys
from heapq import *
input = sys.stdin.readline

N, M = map(int, input().split())
score = list(map(int, input().split()))
efficient = list(map(int, input().split()))

qu = []
for i in range(M):
    heappush(qu, (-min(100-score[i], efficient[i]), i))

for _ in range(N*24):
    t, i = qu[0]
    score[i] -= t
    if 100-score[i] < -t:
        heappop(qu)
        heappush(qu, (-(100 - score[i]), i))

print(sum(score))