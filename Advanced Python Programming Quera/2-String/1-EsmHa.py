n = int(input())

j = 0
for i in range(n):
    s = input()
    i = 0
    while len(s)!=0:
        s = s.replace(s[0],"")
        i=i+1
    
    if j < i: j = i
    
print(j)