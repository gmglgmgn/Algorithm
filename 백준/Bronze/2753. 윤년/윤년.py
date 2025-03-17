import sys
input = sys.stdin.readline

# 연도 입력 받기
year = int(input().strip())

if year % 4 == 0:
    if (year % 100 != 0) or (year % 400 == 0):
        print(1)
    else :
        print(0)
else:
    print(0)
