import sys
input = sys.stdin.readline
''' 
체스판
        0,     1,   ...    n-2,    n-1
n-1

n-2

.
.
.

1,
                
0     R(0,0)    b    a

가능한 케이스들은 어떤 것이 있을까?
1. 두 폰이 서로의 대각선에 위치 : 
    룩은 방해 없이 x, y 이동해서 잡을 수 있음 = 2회
2. 두 폰이 하나의 열 또는 하나의 행에 위치 :
    특수한 경우가 아니면 2회.
3. 두 폰이 0행에 동시에, 혹은 0열에 동시에 위치하면서 Rook을 가로 막고 있는 경우
    = B 폰과 A 폰이 0열에 동시에 위치한다면, B 폰의 행 값이 더 작은 상황
    = B 폰과 A 폰이 0행에 동시에 위치한다면, B 폰의 열 값이 더 작은 상황
    여기서는 Rook 이 3번 움직여야 함.
4. A 가 0 행 혹은 0 열에 위치하면서, B에 가로막혀 있지 않은 경우.
    1회.
3 하고 4를 먼저 필터링하고 나머지는 2로 출력하면 될 것 같은데..
'''

# 잡을 폰
aX, aY = map(int, input().split())
# 방해하는 폰
bX, bY = map(int, input().split())

# Rook의 시작 위치는 0,0
rX, rY = 0, 0

if rX == aX :
    if aX != bX:
        print(1)
    elif aY < bY:    # a(0, y) 이고, aY < bY 일 때.
        print(1)
    elif aY > bY:
        print(3)
    else:
        print(2)
elif rY == aY :
    if aY != bY:
        print(1)
    elif aX < bX:  # a(x, 0) 이고, aX < bX 일 때.
        print(1)
    elif aX > bX:     # a(x, 0) 이고, aX > bX 일 때.
        print(3)
    else:
        print(2)
else:
    print(2)
