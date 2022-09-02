def solve(path):

    i = 0
    with open(path, 'r+') as f:
        
        while True:
            line = f.readline()
            
            if(line.strip()==""): continue
            elif(line.strip()[0]=="#"): continue
            else: i = i+1
            if line=="": break

    return i