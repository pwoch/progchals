import sys
oz = {} 
nz = {}

for c in "kangaroo":
    if c not in oz.keys(): oz[c] = 1 
    else: oz[c] = oz[c] + 1
for c in "kiwibird":
    if c not in nz.keys(): nz[c] = 1 
    else: nz[c] = nz[c] + 1

for s in sys.stdin.readlines():
    s = s.lower()
    pOZ = 0
    pNZ = 0
    for c in s:
        if c in oz.keys(): pOZ += oz[c]
        if c in nz.keys(): pNZ += nz[c]

    if pOZ == pNZ: print("Feud continues")
    elif pOZ > pNZ: print("Kangaroos")
    else: print("Kiwis")
