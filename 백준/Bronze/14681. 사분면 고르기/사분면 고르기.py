import sys as s
input = s.stdin.readline

x = int(input().strip())
y = int(input().strip())

if x > 0:   # x가 양수
    if y > 0:   # y가 양수
        print(1)
    else :      # y가 음수
        print(4)
elif y > 0: # x 가 음수고 y가 양수
    print(2)
else:   # x, y 가 음수
    print(3)