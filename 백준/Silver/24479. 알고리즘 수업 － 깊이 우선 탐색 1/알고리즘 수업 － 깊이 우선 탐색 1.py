import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)


visited = [0] * (N+1)
cnt = 1

def dfs(t):
    global cnt
    visited[t] = cnt
    cnt += 1
    for n in sorted(graph[t]):
        if not visited[n]:
            dfs(n)

dfs(R)

for i in range(1, N+1):
    print(visited[i])