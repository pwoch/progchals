
import math 
import sys
def getPrimes(b):
	m  = math.floor(math.sqrt(b)) 
	l = [0]*m
	l[0] = 1
	l[1] = 1
	for i in range(m):
		if l[i]: continue
		j = 2*i;
		while j < m:
			l[j] = 1
			j += i
	return [i for i in range(m) if l[i] == 0]


def isPrime(a, p):
	i, r, m, N = 0, 1, math.floor(math.sqrt(a)), len(p)
	while i < N  and p[i] <= m:
		if a%p[i] == 0: 
			r = 0
			break;
		i+=1
	r = r if a != 1 else 0
	return r  




def main():
	f = open("pprime.in")
	l = list(map(int,f.read().split()))
	a, b = l[0], l[1] 
	c = 0
	p = getPrimes(b)
	l = []
	i = 5;
	for i in range(10):
		if i == 0: continue
		t = i
		if t > b: continue
		if t >= a and isPrime(t,p): l.append(t)
		t = i*10 + i
		if t > b: continue
		if a <= t and isPrime(t,p): l.append(t)
		for j in range(10):
			t = i*100 + j*10 + i
			if t > b: continue
			if a <= t and isPrime(t,p): l.append(t)
			t = i*1000 + j*100 + j*10 + i
			if t > b: continue
			if a <= t and isPrime(t,p): l.append(t)
			for k in range(10):
				t = i*10000 + j*1000 + k*100 + j*10 + i
				if t > b: continue
				if a <= t and isPrime(t,p): l.append(t)
				t = i*100000 + j*10000 + k*1000 + k*100 + j*10 + i
				if t > b: continue
				if a <= t and isPrime(t,p): l.append(t)
				for n in range(10):
					t = i*1000000 + j*100000 + k*10000 + n*1000 + k*100 + j*10 + i
					if t > b: continue
					if a <= t and isPrime(t,p): l.append(t)
					t = i*10000000 + j*1000000 + k*100000 +n*10000 + n*1000 + k*100 + j*10 + i
					if t > b: continue
					if a <= t and isPrime(t,p): l.append(t)
					for n in range(10):
						t = i*100000000 + j*10000000 + k*1000000 +n*100000 +t*10000 + n*1000 + k*100 + j*10 + i
						if t > b: continue
						if a <= t and isPrime(t,p): l.append(t)
	l.sort()
	for p in l:
		print(p)

	

if __name__ == "__main__":
	main()


