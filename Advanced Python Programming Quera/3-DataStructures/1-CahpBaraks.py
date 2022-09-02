# num = []

# i = 1
# while i!=0:
#     i = int(input())
#     num.append(i)

# num.pop()
# num.reverse()
# for i in num: print(i)

number = map(int, input().split())
print(list(number).remove(5))
print(list(number).remove(85))
