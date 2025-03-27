'''
문제
2021년, 홍익대학교는 절대평가를 시행한다. 착한 도현이는 A학점을 받는 사람이 최대한 많았으면 한다.
Y점이 주어질 때, 상대평가 시 A학점을 받는 인원의 수와 절대평가 시 A학점을 받는 인원의 수를 구하는 프로그램을 작성해보자.

출력
첫째 줄에 상대평가 시 A학점을 받는 인원의 수와 절대평가 시 A학점을 받는 인원의 수를 공백으로 구분해 출력한다.

예제 입력
10
1 2 3 4 5 6 7 8 9 10
50 3

예제 출력
5 8
'''
import sys
input = sys.stdin.readline

N = int(input().strip())        # 응시자 수
A = list(map(int, input().split()))         # 응시자들의 점수
X, Y = map(int, input().split())        # 상대 평가 시 A 비율, 절대 평가 시 A 최소점

gradedAinRelative = N*X // 100
# if ratioRemainder == 0:
#     gradedAinRelative = N//ratio
# else:
#     gradedAinRelative = N//ratio + 1

gradedAinAbs = 0
for i in range(N):
    if A[i] >= Y:
        gradedAinAbs += 1

print(f"{gradedAinRelative} {gradedAinAbs}")