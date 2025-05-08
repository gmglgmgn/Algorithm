import sys
input = sys.stdin.readline

def solve():
    # 구멍의 수와 크기 입력 받고 전처리.
    _ = int(input().strip())    # 전체 구멍의 수는 신경 안 쓸거임.
    hole = [(-1, 0)]    # 크기가 -1인 0번째 구멍 하나를 가진 언덕.
    idx = 0
    for holeSize in map(int, input().split()):  # 원래 구멍 사이즈를 입력 받아 holeSize로 순회
        if hole[-1][0] < holeSize + idx:
            # 1. 구멍 하나 지날 때 마다 도토리 크기 - 1 됨. -> N 번째 구멍의 사실상 크기 == 구멍 크기 + N
            # 2. 언덕 배열의 마지막 구멍보다 순회 중인 구멍의 사실상 크기가 더 큰 경우만 추가
            #       -> 불필요한 구멍 제거해서 구멍이 있는 언덕 배열을 단조 증가 배열로 만들기.
            hole.append(( holeSize + idx, idx + 1))
        idx += 1

    _ = int(input().strip())    # 쿼리의 수 상관 없음.
    for i in map(int, input().split()):     # 도토리 크기 배열 입력받아 순회
        l, r = 0, len(hole)-1

        while l +1 < r :    # 이분 탐색
            m = (l + r) // 2
            if hole[m][0] >= i :
                r = m
            else :
                l = m

        print(hole[r][1], end=" ")  # 결과 출력

solve()