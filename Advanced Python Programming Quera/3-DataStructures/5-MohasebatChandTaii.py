def calc(a):
    
    numMax = max(a)
    avg = 0.0
    avg = avg + sum(a)
    avg = 1.0*avg/len(a)
    
    mid = 0.0
    if len(a)%2==0: mid = mid + (a[(len(a)-1)//2]+a[len(a)//2])/2
    else: mid = mid + a[len(a)//2]

    return (avg, mid, numMax)