'''
문제
소문자로 이루어진 단어 N개가 주어졌을 때, 단어가 총 최소 몇 개의 그룹으로 이루어져 있는지 구하는 프로그램을 작성하시오.

그룹에 속한 단어는 모두 같은 알파벳으로 이루어져 있어야 하고, 개수도 같아야 한다. 즉, 단어를 구성하는 알파벳의 순서만 달라야 한다.

입력
첫째 줄에 단어의 개수 N이 주어진다. (2 ≤ N ≤ 100) 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. 단어는 알파벳 소문자로만 이루어져 있고, 길이는 10을 넘지 않는다.

출력
첫째 줄에 그룹의 최소 개수를 출력한다.
'''
import sys
input = sys.stdin.readline

N = int(input().strip())    # number of words
words = []

# get number of N words
for _ in range(N):
    words.append(sorted(list(input().strip())))
groupCount = 0
groups = []

# count groups
for word in words:
    if words.count(word) != 0 and groups.count(word) == 0:
        groupCount += 1
        groups.append(word)

print(groupCount)