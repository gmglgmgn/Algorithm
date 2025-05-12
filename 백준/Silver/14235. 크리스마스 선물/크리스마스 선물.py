import sys
input = sys.stdin.readline
from heapq import *

N = int(input().strip())
hq = []
for _ in range(N):
    a, *s = map(int, input().split())
    if a == 0:
        if hq:
            print(-(heappop(hq)))
        else:
            print(-1)
    else:
        for i in s:
            heappush(hq, -i)