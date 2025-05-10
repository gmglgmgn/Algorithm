import sys
input = sys.stdin.readline

# QR에 해당하는 글자들만 입력될 것.
# QR = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:"

for _ in range(int(input())):
    R, S = input().split()  # 반복 수, 문자열
    for i in S:
        for _ in range(int(R)):
            print(i, end="")
    print()
