inp = input()
n = int(inp.split(" ")[0])
m = int(inp.split(" ")[1])
game = [[0 for i in range(m)] for j in range(n)]

k = int(input())

for i in range(k):
    bomb = input()
    row = int(bomb.split(" ")[0])-1
    colm = int(bomb.split(" ")[1])-1
    game[row][colm] = "*"
    
    if(row==0 and colm==0):
        if not game[row+1][colm]=="*": game[row+1][colm] = game[row+1][colm]+1
        if not game[row+1][colm+1]=="*": game[row+1][colm+1] = game[row+1][colm+1]+1
        if not game[row][colm+1]=="*": game[row][colm+1] = game[row][colm+1]+1
    elif(row==n-1 and colm==m-1):
        if not game[row-1][colm]=="*": game[row-1][colm] = game[row-1][colm]+1
        if not game[row-1][colm-1]=="*": game[row-1][colm-1] = game[row-1][colm-1]+1
        if not game[row][colm-1]=="*": game[row][colm-1] = game[row][colm-1]+1
    elif(row==0 and colm==m-1):
        if not game[row][colm-1]=="*": game[row][colm-1] = game[row][colm-1]+1
        if not game[row+1][colm-1]=="*": game[row+1][colm-1] = game[row+1][colm-1]+1
        if not game[row+1][colm]=="*": game[row+1][colm] = game[row+1][colm]+1
    elif(row==n-1 and colm==0):
        if not game[row][colm+1]=="*": game[row][colm+1] = game[row][colm+1]+1
        if not game[row-1][colm]=="*": game[row-1][colm] = game[row-1][colm]+1
        if not game[row-1][colm+1]=="*": game[row][colm+1] = game[row][colm+1]+1
    elif(row==0):
        if not game[row][colm+1]=="*": game[row][colm+1] = game[row][colm+1]+1
        if not game[row][colm-1]=="*": game[row][colm-1] = game[row][colm-1]+1
        if not game[row+1][colm+1]=="*": game[row+1][colm+1] = game[row+1][colm+1]+1
        if not game[row+1][colm]=="*": game[row+1][colm] = game[row+1][colm]+1
        if not game[row+1][colm-1]=="*": game[row+1][colm-1] = game[row+1][colm-1]+1
    elif(colm==0):
        if not game[row+1][colm]=="*": game[row+1][colm] = game[row+1][colm]+1
        if not game[row-1][colm]=="*": game[row-1][colm] = game[row-1][colm]+1
        if not game[row+1][colm+1]=="*": game[row+1][colm+1] = game[row+1][colm+1]+1
        if not game[row][colm+1]=="*": game[row][colm+1] = game[row][colm+1]+1
        if not game[row-1][colm+1]=="*": game[row-1][colm+1] = game[row-1][colm+1]+1
    elif(row==n-1):
        if not game[row][colm+1]=="*": game[row][colm+1] = game[row][colm+1]+1
        if not game[row][colm-1]=="*": game[row][colm-1] = game[row][colm-1]+1
        if not game[row-1][colm+1]=="*": game[row-1][colm+1] = game[row-1][colm+1]+1
        if not game[row-1][colm]=="*": game[row-1][colm] = game[row-1][colm]+1
        if not game[row-1][colm-1]=="*": game[row-1][colm-1] = game[row-1][colm-1]+1
    elif(colm==m-1):
        if not game[row+1][colm]=="*": game[row+1][colm] = game[row+1][colm]+1
        if not game[row-1][colm]=="*": game[row-1][colm] = game[row-1][colm]+1
        if not game[row+1][colm-1]=="*": game[row+1][colm-1] = game[row+1][colm-1]+1
        if not game[row][colm-1]=="*": game[row][colm-1] = game[row][colm-1]+1
        if not game[row-1][colm-1]=="*": game[row-1][colm-1] = game[row-1][colm-1]+1
    else:
        if not game[row-1][colm-1]=="*": game[row-1][colm-1] = game[row-1][colm-1]+1
        if not game[row-1][colm]=="*": game[row-1][colm] = game[row-1][colm]+1
        if not game[row-1][colm+1]=="*": game[row-1][colm+1] = game[row-1][colm+1]+1
        if not game[row][colm+1]=="*": game[row][colm+1] = game[row][colm+1]+1
        if not game[row][colm-1]=="*": game[row][colm-1] = game[row][colm-1]+1
        if not game[row+1][colm-1]=="*": game[row+1][colm-1] = game[row+1][colm-1]+1
        if not game[row+1][colm]=="*": game[row+1][colm] = game[row+1][colm]+1
        if not game[row+1][colm+1]=="*": game[row+1][colm+1] = game[row+1][colm+1]+1


for ls in game:
    print(*ls, sep=" ")
    print()