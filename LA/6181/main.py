P = int(input())
for i in range(P):
    D = int(input())
    s = input()
    l = len(s)
    N = int(input())
    c = 0
    X = map(int, input().split())
    print(D, end=' ')
    for x in X:
        c += x
        c += l
        c %= l
        print(s[c], end='')
    print()
