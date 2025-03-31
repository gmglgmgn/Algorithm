import sys
input = sys.stdin.readline
from itertools import combinations

N, M = map(int, input().split())
lst = list(map(int, input().split()))
res = 0
s = 0

for i, j, k in combinations(range(N), 3):
    s = lst[i] + lst[j] + lst[k]
    if M >= s > res:
        res = s
        
print(res)
