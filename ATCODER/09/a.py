
from sys import stdin

n = stdin.readline()
a = []
b = []
#read input
for line in stdin:
    a.append(int(line[0]))
    b.append(int(line[2]))
counter = 0
i = int(n)-1
while i >= 0:
    if( (a[i]+counter)%b[i]):
        counter += b[i] - ((a[i]+counter)%b[i])
    i-=1
print counter
    

