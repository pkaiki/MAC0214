def func(x, n):
	if x*(x-1) > 2*n:
		return 1
	else:
		return 0
 
def bs(n):
	l = 1
	r = n+1
	while l+1 < r:
		mid = (l+r)//2
		if func(mid, n):
			r = mid
		else:
			l = mid
	return l
 
t = int(input())
 
for _ in range(t):
	n = int(input())
	l = int(bs(n))
	k = int(n - ((l*(l-1))//2))
	print(k+l)
