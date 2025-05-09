import sys
input = sys.stdin.readline

# 카드 수 N, 카드들 입력 받기.
N = int(input().strip())
Cards = list(map(int, input().split()))

# Flag 배열 설정. 바이어스가 10의 7승이 되겠다. 음수도 들어올테니..
Flags = [False] * (2 * 10**7)
for c in Cards:
    Flags[c+(10**7)] = True

# 쿼리의 수 M과 쿼리들 입력받기.
M = int(input().strip())
Queries = list(map(int, input().split()))

# Flag 배열 출력
for Q in Queries:
    if Flags[Q+(10**7)]:
        print(1, end=" ")
    else:
        print(0, end=" ")