def comb(n, k):
    if k>n: return 0
    else: return (factoriel(n))/factoriel(k)/factoriel(n-k)

def factoriel(n):
    if n==0: return 1
    return n*factoriel(n-1)