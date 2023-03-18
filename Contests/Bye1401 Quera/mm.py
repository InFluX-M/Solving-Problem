mod = int(1e9 + 7)

t = int(input())
d = dict()
d[0] = 1
for i in range(1, 500000):
    d[i] = (d[i-1]*2) % mod

while t:
    t -= 1
    a, b = map(int, input().split())
    if min(a, b) == 1:
        cnt2 = 4 * (int(pow(3, max(a, b) - 1)) % mod)
        print(cnt2)

    elif max(a, b) <= 2:
        print(24)

    else:
        cnt1 = 4 * 3 * 2 * d[int((max(a, b) - 2) / 2)]
        cnt2 = 4 * 3 * 2 * d[int(max(a, b) - 2)]
        print(((cnt1 % mod) + (cnt2 % mod)) % mod)
