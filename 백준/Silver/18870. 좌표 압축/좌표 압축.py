'''
문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표 Xj의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.
'''
import sys
input = sys.stdin.readline

N = int(input().strip())    # get the number of coordinates
coordinates = list(map(int, input().split()))   # save coordinates
temp = sorted(set(coordinates))      # sort coordinates by values and save them in temporal list and remove redundancy by using set() object

# remove redundant elements in temporal list
# don't use anymore to avoid time complexity issue
# for coord in coordinates:
#     while temp.count(coord) > 1:
#         temp.remove(coord)

# make a dictionary which maps coordinate and its compacted coordinate
coordAndCompaction = {}
for i, j in zip(range(len(temp)), temp):
    coordAndCompaction[j] = i

for coord in coordinates:
    print(coordAndCompaction[coord], end=" ")