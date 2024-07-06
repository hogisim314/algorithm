import sys
input = sys.stdin.readline

s=set()
count = 0
n, m = map(int, input().split())

for _ in range(n):
    data=input().rstrip()
    s.add(data)

for _ in range(m):
    data=input().rstrip()
    if data in s:
        count+=1

print(count)