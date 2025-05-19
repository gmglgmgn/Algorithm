import sys
input = sys.stdin.readline

N = int(input().strip())
table = []
for _ in range(N):
    table.append(tuple(map(int, input().split())))

table.sort(key=lambda x: (x[1], x[0]))

temp = -1
cnt = 0
for start, end in table:
    if start >= temp:
        cnt += 1
        temp = end

print(cnt)