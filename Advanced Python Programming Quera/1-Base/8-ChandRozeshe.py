from datetime import datetime

def day_calculator(date):
    date1 = datetime.datetime.strptime(date, '%Y-%m-%d')
    date2 = datetime.datetime.strptime("1999-1-14", '%Y-%m-%d')
    i = (date1 - date2).days
    
    if i<0: return "Not yet born"
    else: return i