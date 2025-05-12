'''https://www.acmicpc.net/problem/1874'''
import sys
input = sys.stdin.readline

N = int(input().strip())
lst = []
for _ in range(N):
    lst.append(int(input().strip()))

st = []
result = []
idx = 0
i = 0

for n in lst:
    if n > i:
        while n > i:
            i += 1
            st.append(i)
            result.append('+')
        st.pop()
        result.append('-')
    else:
        if st[-1] == n:
            st.pop()
            result.append('-')
        else:
            print('NO')
            exit()

for i in result:
    print(i)