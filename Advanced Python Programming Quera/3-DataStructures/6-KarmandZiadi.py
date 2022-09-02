n = int(input())
names = {}

for i in range(n):
    name = input().split(" ")[0]
    
    if name in names:
        names[name] += 1 
    else:
        names[name] = 1 

print(max(names.values()))