# 3a
num_list = [ 32, 99, 12, 17, 77 ]
list_sum = 0
for i in num_list:
    list_sum += i
print('sum:', list_sum)

# 3b
num_list = [ 32, 99, 12, 17, 77 ]
list_sum = 0
length = 0
for i in num_list:
    list_sum += i
    length += 1
print('number of elements:', length)
print('mean:', float(list_sum)/length)