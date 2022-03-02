# 7a
def get_min(mylist):
    min_num = None
    if mylist: # if list is not empty
        min_num = mylist[0]
        for i in mylist[1:]:
            if i < min_num:
                min_num = i
    return min_num

# 7b
def get_index(my_list, var):
    idx = -1
    for i in range(len(my_list)):
        if var == my_list[i]:
            idx = i
    return idx


# 7c
num_list = [98, 67, 26, 99, 89, 12]
list_min = get_min(num_list)
min_idx = get_index(num_list, list_min)
pop_num = num_list.pop(min_idx)
print(pop_num)

# 7d
_sum = 0 # isn't sum a build-in name??
num_list = [ 98, 67, 26, 99, 89, 12 ]
while _sum <= 100:
    temp_min = get_min(num_list)
    _sum += temp_min
    num_list.pop(get_index(num_list, temp_min))
print(num_list, _sum)