import sys
input = sys.stdin.readline

N, M = map(int, input().split())    # 노동자 수 | 필요한 풍선 수
staff = list(map(int, input().split()))     # 노동자 별 분당 풍선 생산 수

start, end = 0, 10**12+7    # l, r 포인터. l == 못 만드는 경계, r == 만드는 경계

while end > start + 1:  # 못 만드는 경계와 만들 수 있는 경계의 차이가 1일 때 까지
    mid = (start + end) // 2
    cnt = 0
    for i in staff:
        cnt += mid // i # 각 스태프가 m 분에 만들 수 있는 풍선 수 == min * 분당 풍선 제작 수
    if cnt >= M:
        end = mid
    else:
        start = mid

print(end)