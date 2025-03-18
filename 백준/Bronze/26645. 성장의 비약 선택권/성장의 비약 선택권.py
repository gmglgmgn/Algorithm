import sys as s
input = s.stdin.readline
INF = 10**6
'''
1 : 200 ~ 209 성장의 비약 : 8
2 : 200 ~ 219 성장의 비약 : 4
3 : 200 ~ 229 성장의 비약 : 2
4 : else  태풍 성장의 비약 : 1
'''
N = int(input().strip())

elixirs = [1, 2, 4, 8]
ceil = [239, 229, 219, 209]
max_index = 0
increased_level = 0

for i in range(len(elixirs)):
    # N 이 구간을 벗어나면 탈출
    if N > ceil[i]:
        break
    # 현재 레벨을 기준으로 성장의 물약 최대로 사용할 수 있는 횟수 구하기
    while elixirs[i] + N > ceil[i] + 1:
        elixirs[i] -= 1
    # 이전까지 올릴 수 있던 레벨이 현재 사용 가능한 성장의 물약 개수보다 적으면 업데이트
    if increased_level < elixirs[i]:
        increased_level = elixirs[i]
        max_index = i

print(4 - max_index)
