import sys
input = sys.stdin.readline

'''
x, y 
- N자리 이진수
- 각각 a개의 1과 b개의 1을 가짐
XOR(x, y) 의 최대 값을 구하라.

입력 : 
N
a b

출력 :
MAX(XOR(x_i, y_i))
'''

N = int(input())        # 자리 수
A, B = map(int, input().split())    # x와 y의 1의 수

# 1의 수가 A와 B 인 N 자리 2진수들 x, y
x = []
y = []

for i in range(2**N):       # N자리 2진수는 총 2^N 개
    a, b = 0, 0
    for j in range(N):      # i 가 몇 개의 1을 가지는 지 확인
        if i & (1 << j):
            a += 1
            b += 1
    if a == A:      # x 의 1의 개수를 만족
        x.append(i)
    if b == B:      # y 의 1의 개수를 만족
        y.append(i)

MAX = 0     # 최대 XOR 값

for i in x:     # 모든 x와 y에 대해서 수행
    for j in y:
        xor = i^j       # x XOR y 계산
        if xor > MAX:
            MAX = xor

print(MAX)