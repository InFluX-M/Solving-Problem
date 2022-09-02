from cmath import tan
import math
x = int(input())
y = math.gcd(math.ceil(math.pow(x,1.0*5/3) + math.tan(math.radians(x))), 
         math.floor(math.pow(math.pi, (2+math.atan(math.pow(math.sin(math.radians(x)),2))))))
print(y)