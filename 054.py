# RandomUsername (Nikola Jovanovic)
# Project Euler
# 054

from collections import namedtuple
import math
from enum import IntEnum

# input file
in_file = open("054.in")

# IntEnum for easy comparing of all possible hands
class Hands(IntEnum):
	high_card = 1
	one_pair = 2
	two_pair = 3
	three_oak = 4
	straight = 5
	flush = 6
	full_house = 7
	four_oak = 8
	straight_flush = 9

# evaluate a single hand
def eval(hand):
	# list of all the numbers, num/suit dictionary
	nums_list = []
	nums = dict()
	suits = dict()
	# max and min card in this hand and a max number of occurences for a number
	mincard = 16
	maxcard = 1
	maxocc = 1
	# evaluate each card
	for card in hand:
		# add its value to nums_list
		nums_list.append(card[0])
		# update dictionaries
		if not card[0] in nums:
			nums[card[0]] = 1
		else:
			nums[card[0]] += 1
			maxocc = max(maxocc, nums[card[0]])
		if not card[1] in suits:
			suits[card[1]] = 1
		else:
			suits[card[1]] += 1
		# update min and max hand
		mincard = min(mincard, card[0])
		maxcard = max(maxcard, card[0])
	# sort nums_list decreasingly
	nums_list = list(reversed(sorted(nums_list)))
	# Straight flush
	if 5 in suits and maxocc == 1 and maxcard - mincard == 4:
		return (Hands.straight_flush, maxcard, 0, nums_list)
	# Four of a kind
	if 4 in nums.values():
		val = [k for (k, v) in nums.items() if v == 4][0]
		return (Hands.four_oak, val, 0, nums_list)
	# Full house
	if 3 in nums.values() and 2 in nums.values():
		idx1 = [k for (k, v) in nums.items() if v == 3][0]
		idx2 = [k for (k, v) in nums.items() if v == 2][0]
		return (Hands.full_house, idx1, idx2, nums_list)
	# Flush
	if 5 in suits.values():
		return (Hands.flush, 0, 0, nums_list)
	# Straight
	if maxocc == 1 and maxcard - mincard == 4:
		return (Hands.straight, maxcard, 0, nums_list)
	# Three of a kind
	if 3 in nums.values():
		val = [k for (k, v) in nums.items() if v == 3][0]
		return (Hands.three_oak, val, 0, nums_list)
	# Two pairs
	lst = [k for (k, v) in nums.items() if v == 2]
	if len(lst) == 2:
		return (Hands.two_pair, max(lst[0], lst[1]), min(lst[0], lst[1]), nums_list)
	# One pair
	if 2 in nums.values():
		val = [k for (k, v) in nums.items() if v == 2][0]
		return (Hands.one_pair, val, 0, nums_list)
	# High card
	return (Hands.high_card, maxcard, 0, nums_list)

# Convert card values to numbers for easy comparing
def to_num(c):
	if c == "T":
		return 10
	elif c == "J":
		return 11
	elif c == "Q":
		return 12
	elif c == "K":
		return 13
	elif c == "A":
		return 14
	else:
		return ord(c) - 48

# The solution
first_won = 0

# Parsing the input
for line in in_file:
	cards = line.strip().split()
	v1 = eval( list( map( lambda c: (to_num(c[0]), c[1]), cards[0:5] ) ) )
	v2 = eval( list( map( lambda c: (to_num(c[0]), c[1]), cards[5:10] ) ) )
	# We can compare hands easily like this since each hand is a tuple
	# (hand_value, arg1, arg2, [list of cards])
	# The natural orderings of tuples and lists help here
	if v1 > v2:
		first_won += 1
	# Test case #94 contains same card values for both players
	# in which case occurs a draw, so no one wins
	# I suppose that this shouldn't be counted towards the total number of wins...
	if v1 == v2:
		print("EQUAL", v1, v2)

# Print the solution
print(first_won)
