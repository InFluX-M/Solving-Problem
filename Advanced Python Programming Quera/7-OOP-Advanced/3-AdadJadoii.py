from tokenize import String

class Strint(int):
    
    def __init__(self, number):
        
        number = str(number)
        while(number[0]=="0"):
            if number == "0": break
            number = number.removeprefix("0")
            
        self = int(number)
    
    def __lt__(self, other):
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")

        other = int(other)
        
        return int(str(self)[len(str(self))-1]) < int(str(other)[len(str(other))-1])

    def __gt__(self, other):
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")

        other = int(other)
        return int(str(self)[len(str(self))-1]) > int(str(other)[len(str(other))-1])

    def __le__(self, other):
        
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")

        other = int(other)
        return int(str(self)[len(str(self))-1]) <= int(str(other)[len(str(other))-1])

    def __ge__(self, other):
        
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")

        other = int(other)
        return int(str(self)[len(str(self))-1]) >= int(str(other)[len(str(other))-1])

    def __ne__(self, other):
        
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")
        other = int(other)
        return int(str(self)[len(str(self))-1]) != int(str(other)[len(str(other))-1])

    def __eq__(self, other):
        
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")
        other = int(other)
        return int(str(self)[len(str(self))-1]) == int(str(other)[len(str(other))-1])
  
    def __len__(self):
        return len(str(self))
    
    def __call__(self):
        persian_number = str(self)
        persian_number = persian_number.replace("0", '۰')
        persian_number = persian_number.replace("1", '۱')
        persian_number = persian_number.replace("2", '۲')
        persian_number = persian_number.replace("3", '۳')
        persian_number = persian_number.replace("4", '۴')
        persian_number = persian_number.replace("5", '۵')
        persian_number = persian_number.replace("6", '۶')
        persian_number = persian_number.replace("7", '۷')
        persian_number = persian_number.replace("8", '۸')
        persian_number = persian_number.replace("9", '۹')

        return persian_number

    def __add__(self, other):
        
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")
        other = int(other)
        return int(str(self) + str(other))

    def __sub__(self, other):
        
        other = str(other)
        while(other[0]=="0"):
            if other == "0": break
            other = other.removeprefix("0")
        
        other = int(other)
        if(str(self).removesuffix(str(other)) == str(self)): raise Exception('The subtraction is not valid!')
        else:
            if str(self).removesuffix(str(other)) == "": return 0
            return int(str(self).removesuffix(str(other)))
