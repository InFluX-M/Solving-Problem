import requests

def process(url):
    response = requests.get(url)
    
    if(response.status_code!=200): return "Bad Query"
    
    ls = set()
    for dic in response.json():
        ls.add(dic["category"])
    
    if(len(ls) == 0): return "I can't recognize it"
    
    s = ls.pop()
    if(len(ls)==0): 
        return s
    else:
        return "I can't recognize it"