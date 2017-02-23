
from sys import stdin
import math

for line in stdin:
    l = list(map(int,line.split()))
    h,u,d,f = l[0],l[1],l[2],l[3]/100.0
    if ( h == 0): break
    success, end = 0, 100
    height = 0
    i = 1
    while height >= 0:
      dec = 1-f*(i-1) if (1-f*(i-1)) > 0 else 0
      height += u*dec
      if height > h:
          success = i
          break
      height -= d
      if height < 0:
          end = i
          break
      i +=1
    if success:
        print("success on day", success)
    else:
        print("failure on day", end)


