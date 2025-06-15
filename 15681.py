import sys
sys.setrecursionlimit(10**7)

n, r, q = map(int, sys.stdin.readline().split())

edge_list = [[] for _ in range(n+1)]

visit = [False for _ in range(n+1)]

sub_node = [1] * (n + 1)

for _ in range(n-1):
    a, b = map(int, sys.stdin.readline().split())
    edge_list[a].append(b)
    edge_list[b].append(a)

def dfs(a):

    visit[a] = True
    count = 1

    for i in edge_list[a]:
        if not visit[i]:
            count += dfs(i)

    sub_node[a] = count
    return count
visit[r] = True
dfs(r)

for _ in range(q):
    ques = int(sys.stdin.readline())
    print(sub_node[ques])
