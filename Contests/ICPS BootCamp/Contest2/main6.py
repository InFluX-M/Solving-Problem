k = int(input())

fact = list()
fact.append(1)
fact.append(1)
for i in range(2, 1000000+1):
    fact.append(i * fact[i-1])

ls = list()
mx = 1
for i in range(k):
    s = input()
    l, r = int(s.split(" "))[0], int(s.split(" ")[1])
    mx = max(r, mx)

