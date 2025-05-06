import sys
input = sys.stdin.readline

N, M = map(int, input().split())
staff = list(map(int, input().split()))

start, end = 0, 10**12+7

while end > start + 1:
    mid = (start + end) // 2
    cnt = 0
    for i in staff:
        cnt += mid // i
    if cnt >= M:
        end = mid
    else:
        start = mid

print(end)