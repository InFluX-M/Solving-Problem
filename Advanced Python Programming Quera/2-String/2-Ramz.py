k = int(input())
password = input()

nO = 0

for i in range(k):
    p = input()
    if p.find(password[i]) > 4 : nO = nO + (len(p) - p.find(password[i]))
    else: nO = nO + p.find(password[i]) 
    
print(nO)