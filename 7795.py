import sys
t = int(input())
for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(lambda x: (int(x), 'a'), sys.stdin.readline().split()))
    b = list(map(lambda x: (int(x), 'b'), sys.stdin.readline().split()))

    arr = a + b
    arr.sort()
    result = 0
    numA = 0
    for i in range(len(arr)):
        if arr[i][1] == 'a':
            result += i-numA
            numA += 1
    print(result)
