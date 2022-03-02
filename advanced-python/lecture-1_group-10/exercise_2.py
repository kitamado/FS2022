# 2a
# print(a) will print ['x', 'y']

# 2b
# because b and a point to the same location, and we modified b,
# so the list where a and b both pointed to has an 'y' added,
# therefore list a also print ['x', 'y']

# 2c
a = 'x'
b = a
b += ' y'
print(a)
print(b)
# because strings are immutable objects so when we add 'y' to b, variable b
# points to a new memory location that stores string 'x y', while variable a
# still points to the old memory location

