import sys
input = sys.stdin.readline

score = [0]*31

for i in range(28):
    n = int(input())
    score[n] = 1

for i in range(1, 31):
    if score[i] == 0:
        print(i)