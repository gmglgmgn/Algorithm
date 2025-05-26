import sys
from collections import deque

input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

cnt = 1

qu = deque()
qu.append(R)
visited = [0] * (N+1)
visited[R] = cnt

while qu:
    t = qu.popleft()
    for n in sorted(graph[t]):
        if visited[n] == 0:
            qu.append(n)
            cnt += 1
            visited[n] = cnt
            
for i in range(1, N+1):
    print(visited[i])