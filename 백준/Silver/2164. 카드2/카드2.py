'''https://www.acmicpc.net/problem/2164'''
import sys
input = sys.stdin.readline
from collections import deque

# Dequeue 만들기. 큐도 Deque 쓰기...
qu = deque()

N = int(input().strip())

# qu 값 넣기.
for i in range(1, N+1):
    qu.append(i)

count = N
while count > 1:
    count -= 1
    qu.popleft()
    qu.append(qu.popleft())

print(qu[0])