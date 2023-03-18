import math

n = int(input())
ls = map(int , input().split(" "))

fail = set()
a = set()

i = 0
for t in ls:
    
    if t != 0:
        a.add(t)
    else:
        fail.add(i+1)
        
    i += 1

s = set()

for j in range(1, n+1):
    if not j in a:
        s.add(j)
        
cnt = 0

for t in fail:
    if t in s:
        cnt += 1

if len(fail) == 0:
    print(0)
    
else:
    aim = math.factorial(len(fail))

    for i in range(1, cnt+1):
        aim += int(pow(-1, i)) * int(math.comb(cnt, i)) * int(math.factorial(len(fail) - i))
    
    print(aim % (1000000000+7))