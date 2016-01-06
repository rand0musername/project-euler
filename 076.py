# RandomUsername (Nikola Jovanovic)
# Project Euler
# 076

import math

# DP matrices
DP = [ [0 for x in range(105)] for x in range(105)]
cDP = [ [0 for x in range(105)] for x in range(105)]

# DP[i][j] - valid partitions of i with j as the largest number
# cDP[i][j] - sum: DP[i][k] where k: 1 -> j

# base case
DP[0][0] = 1
for i in range(0, 101):
	cDP[0][i] = 1

# recurrence relation: DP[i][j] = cDP[i - j][j]
for i in range(1, 101):
	for j in range(1, 101):
		if j > i:
			DP[i][j] = 0
		else:
			DP[i][j] = cDP[i - j][j]
		cDP[i][j] = cDP[i][j-1] + DP[i][j]

# 100 = 100 should not be considered
print(cDP[100][100] - 1)