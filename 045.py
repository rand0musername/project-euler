# RandomUsername (Nikola Jovanovic)
# Project Euler
# 045

import math

n = 285
while(True):
	n += 1
	X = n * (n+1) // 2
	# 3n^2 - n - 2X = 0 => n = ( 1+-math.sqrt(1+24X) ) / 6
	# 2n^2 - n - X = 0 => n = ( 1 +- math.sqrt(1+8X) ) / 4
	D1 = 1 + 24 * X
	D2 = 1 + 8 * X
	if not math.sqrt(D1).is_integer() or not math.sqrt(D2).is_integer():
		continue
	N1_1 = (1 + math.sqrt(D1)) / 6
	N1_2 = (1 - math.sqrt(D1)) / 6
	if not (N1_1.is_integer() and N1_1 > 0) and not (N1_2.is_integer() and N1_2 > 0):
		continue
	N2_1 = (1 + math.sqrt(D2)) / 4
	N2_2 = (1 - math.sqrt(D2)) / 4
	if not (N2_1.is_integer() and N2_1 > 0) and not (N2_2.is_integer() and N2_2 > 0):
		continue
	# match!
	print(X)
	exit(0)