
import sys
from sys import stdin 

n = input()
for k in range(int(n)):
    stdin.readline()
    t = list(map(int,stdin.readline().split()))
    l = [i-1 for i in t]
    b = []
    for i in range(max(t)):
        b.append(l.index(i))
    l = stdin.readline().split()
    for i in range(max(t)):
        print(l[b[i]])
    if k != int(n)-1: print()


