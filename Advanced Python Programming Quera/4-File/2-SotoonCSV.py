def process(path):
    
    with open("ans.csv", 'w') as p:
        with open(path, 'r+') as f:
        
         def csv_reader(path):
            with open(path) as csv:
                for row in csv.readlines():
                    yield row.rstrip().split(',')
             
        sum = 0       
        for line in csv_reader(path):
            for c in line:
                sum = sum + int(c)
            line = line + "," + str(sum)
            p.write(line+'\n')
            p.flush()

                
    
                
process("1.csv")