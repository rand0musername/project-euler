# RandomUsername (Nikola Jovanovic)
# Project Euler
# 120

import math
 
# We expand (a-1)^n + (a+1)^n using binomial expansion:
# n even: r = 2
# n odd: r = 2an
# since a > 2, 2an > 2 (mod a^2)
# => rmax is max(2an % a^2)
# even a:
# 2a | a^2 => ret = 2a * (a/2 - 1) = a^2 - 2*a = a(a-2)
# odd a:
# 2a | 2a^2 => ret = max( ( 2a * ((a-1)/2) ) % a^2, ( 2a * (a-1) ) % a^2)
#	= max(a^2 - a, a^2 - 2a) = a^2 - a = a(a-1)
# so rmax = a(a-1) if a is odd, else rmax = a(a-2)

ret = 0

for a in range(3, 1001):
	maxr = a*(a-1) if a&1 else a*(a-2)
	ret += maxr

print(ret)