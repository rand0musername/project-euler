fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

def sum(n):
	ret = 0
	while n > 0:
		ret += fact[n % 10]
		n //= 10
	return ret 

RET = 0

for base in range(1000000):
	vis = set()
	curr = base
	counter = 0
	while True:
		if curr in vis:
			break
		else:
			vis.add(curr)
			counter += 1
			curr = sum(curr)
	if counter == 60:
		RET += 1

print(RET)
