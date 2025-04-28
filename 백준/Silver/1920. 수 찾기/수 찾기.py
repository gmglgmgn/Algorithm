import sys
input = sys.stdin.readline

N = int(input().strip())
A = list(map(int, input().strip().split()))

M = int(input().strip())
Q = list(map(int, input().strip().split()))

A.sort()

for i in Q:
    l, r = 0, N-1
    flag = 0
    while l <= r:
        m = (l+r)//2
        if A[m] == i:
            flag = 1
            break
        elif A[m] > i:
            r = m-1
        else:
            l = m+1
    if flag == 1:
        print(1)
    else:
        print(0)