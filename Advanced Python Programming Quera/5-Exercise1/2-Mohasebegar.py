from math import ceil

def calculator(n, m, ls):
    
    value = 0
    for i in range(ceil(n/m)): value += int(pow(-1,i))*sum(ls[m*i:m*i+m])
    return value
