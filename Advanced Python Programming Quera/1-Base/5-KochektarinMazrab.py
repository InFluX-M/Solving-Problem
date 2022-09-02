p, d = input().split()
p = int(p)
d = int(d) 

i = 1
while True:
    if (d*i) % p>=0 and (d*i) % p<=p/2:
        print(d*i)
        break
    i=i+1