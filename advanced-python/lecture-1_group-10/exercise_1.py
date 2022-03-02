# 1a
print('(1a)Height difference:')
wadlow_cm = 272
user_cm = 179
if wadlow_cm > user_cm:
    print('You are ', wadlow_cm - user_cm, ' cm lower.')
elif wadlow_cm < user_cm:
    print('I don\'t believe you.')
else:
    print('You are as tall as Mr. Wadlow')

# 1b
print('\n(1b)Indentation:')
num_list = [ 32, 99, 12, 17, 77 ]
for num in num_list:
    if num >= 50:
        print(num)
    else:
        print('Too low')