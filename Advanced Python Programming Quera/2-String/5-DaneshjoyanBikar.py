import re


def solve(arr):
    
    n1 = str(arr).split("+")[0].replace(" ", "")
    n2 = str(arr).split("+")[1].split("=")[0].replace(" ", "")
    n3 = str(arr).split("+")[1].split("=")[1].replace(" ", "")

    aim = 0
    if(n1.find("#")>=0):
        aim = int(n3) - int(n2)
        n1 = n1.replace("#", "[0-9]+")
        n1 = "^" + n1 + "$"
        n1 = r''+ n1
        
        if(re.match(n1, str(aim))): 
            return str(aim) + " + " + str(n2) + " = " + str(n3)
        else: return '-1'
            
    elif(n2.find("#")>=0):
        aim = int(n3) - int(n1)
        n2 = n2.replace("#", "[0-9]+")
        n2 = "^" + n2 + "$"
        n2 = r''+ n2
        
        if(re.match(n2, str(aim))): 
            return str(n1) + " + " + str(aim) + " = " + str(n3)
        else: return '-1'

    elif(n3.find("#")>=0):
        aim = int(n1) + int(n2)
        n3 = n3.replace("#", "[0-9]+")
        n3 = "^" + n3 + "$"
        n3 = r''+ n3
        
        if(re.match(n3, str(aim))): 
            return str(n1) + " + " + str(n2) + " = " + str(aim)
        else: return '-1'
        
print(solve(input()))