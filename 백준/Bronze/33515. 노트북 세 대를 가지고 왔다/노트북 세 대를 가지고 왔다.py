import sys
input = sys.stdin.readline

N = list(map(int, input().split()))
N.sort()

print(N[0])