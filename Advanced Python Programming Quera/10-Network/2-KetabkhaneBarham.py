import requests
import json

math_url = "http://127.0.0.1:8000/math/"
physic_url = "http://127.0.0.1:8000/physic/"
chess_url = "http://127.0.0.1:8000/chess/"

def process(book):
    
    if(book["category"]=="physic"):
        for dic in requests.get(physic_url).json():
            if(dic["name"]==book["name"]): return "bad query" 
            
        requests.post(physic_url, data = book)
        
    elif(book["category"]=="math"):
        for dic in requests.get(math_url).json():
            if(dic["name"]==book["name"]): return "bad query" 

        requests.post(math_url, data = book)

    elif(book["category"]=="chess"):
        for dic in requests.get(chess_url).json():
            if(dic["name"]==book["name"]): return "bad query" 

        requests.post(chess_url, data = book)