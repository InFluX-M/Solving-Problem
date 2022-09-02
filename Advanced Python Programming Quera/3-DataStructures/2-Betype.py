word = list(input())
aim = []

for c in word:
    if c == "=":
        if len(aim)!=0:
            aim.pop()
    else:
        aim.append(c)
    
s = ""    
for c in aim:
    s = s+c
    
print(s)