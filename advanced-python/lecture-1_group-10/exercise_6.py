# Iterating over 0 - 99 and checking divisibility 
# by 28, 4 and 7 for respective print statements 
for i in range(100):
    if i % 28 == 0:
        print('PingPong')
    elif i % 4 == 0:
        print('Ping')
    elif i % 7 == 0:
        print('Pong')