def fruits(fruit_list):
    
    aim_fruit = {}
    for fruit_inf in fruit_list:
        flag = True

        values = list(fruit_list.values())
        if(values[1]=="sphere" and 300<=values[2]<=600 and 100<=values[3]<=500): 
            if(fruit_inf["name"] in aim_fruit): aim_fruit[fruit_inf["name"]] += 1
            else: aim_fruit[fruit_inf["name"]] = 1
                    
            
    return aim_fruit
    

 # for key, value in fruit_inf.items():
        #     if(key=="shape" and value=="sphere"): continue
        #     elif(key=="mass" and value>=300 and value<=600): continue
        #     elif(key=="volume" and value>=100 and value<=500): continue
        #     elif(key=="name"): continue
        #     else: 
        #         flag = False
        #         break