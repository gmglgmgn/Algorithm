import sys
input = sys.stdin.readline
from heapq import *

N = int(input().strip())
hq = []
for _ in range(N):
    x = int(input().strip())
    if x == 0:
        if hq:
            print(heappop(hq))
        else:
            print(0)
    else:
        heappush(hq, x)