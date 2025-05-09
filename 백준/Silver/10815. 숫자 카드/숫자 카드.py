import sys
input = sys.stdin.readline

# 카드 수 N, 카드들 입력 받기.
N = int(input().strip())
Cards = list(map(int, input().split()))

# 카드 배열 정렬하기. 2진 탐색 위해서.
Cards.sort()

# 쿼리의 수 M과 쿼리들 입력받기.
M = int(input().strip())
Queries = list(map(int, input().split()))

for Q in Queries:
    left, right = 0, len(Cards)-1   # left와 right 포인터 만들기
    find = False
    while left <= right:
        mid = (left + right) // 2
        if Cards[mid] == Q:
            find = True
            break
        elif Cards[mid] < Q:
            left = mid + 1
        else:
            right = mid - 1
    if find:
        print(1, end=" ")
    else:
        print(0, end=" ")