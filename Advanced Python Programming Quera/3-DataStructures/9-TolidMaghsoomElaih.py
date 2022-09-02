def divs(a):
    yield 1
    for i in range(2, (a//2)+1):
        if a%i==0: yield i
    yield a
    
print(list(divs(int(input()))))