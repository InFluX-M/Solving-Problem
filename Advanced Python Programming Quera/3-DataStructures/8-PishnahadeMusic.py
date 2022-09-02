all_users = {}
all_albums = {}


def add_user(username, age, city, albums, all_users, all_albums):
    alb = ""
    for name in albums:
        alb = alb + name + "-"
    alb = alb[:-1]
    all_users[username] = f"{age} {city} {alb}"


def add_album(name, artist_name, genre, tracks, all_users, all_albums):
    all_albums[name] = f"{artist_name} {genre} {tracks}"


def query_user_artist(username, artist_name, all_users, all_albums):
    alb = all_users[username].split(" ")[2]
    nameAlb = []
    for name in alb.split("-"):
        nameAlb.append(name)
        
    i=0
    for name in nameAlb:
        if(all_albums[name].split(" ")[0] == artist_name): i = i + int(all_albums[name].split(" ")[2])
    
    return i

def query_user_genre(username, genre, all_users, all_albums):
    alb = all_users[username].split(" ")[2]
    nameAlb = []
    for name in alb.split("-"):
        nameAlb.append(name)
        
    i=0
    for name in nameAlb:
        if(all_albums[name].split(" ")[1] == genre): i = i + int(all_albums[name].split(" ")[2])
    
    return i


def query_age_artist(age, artist_name, all_users, all_albums):
    
    userAim = []
    for key, value in all_users.items():
        if(int(value.split(" ")[0])==age): userAim.append(key)
        
    i = 0
    for username in userAim:
        alb = all_users[username].split(" ")[2]
        nameAlb = []
        for name in alb.split("-"):
            nameAlb.append(name)
            
        for nameAlbum in nameAlb:
            if all_albums[nameAlbum].split(" ")[0]==artist_name: i = i + int(all_albums[nameAlbum].split(" ")[2])
            
    return i

def query_age_genre(age, genre, all_users, all_albums):
    userAim = []
    for key, value in all_users.items():
        if(int(value.split(" ")[0])==age): userAim.append(key)
        
    i = 0
    for username in userAim:
        alb = all_users[username].split(" ")[2]
        nameAlb = []
        for name in alb.split("-"):
            nameAlb.append(name)
            
        for nameAlbum in nameAlb:
            if all_albums[nameAlbum].split(" ")[1]==genre: i = i + int(all_albums[nameAlbum].split(" ")[2])
            
    return i


def query_city_artist(city, artist_name, all_users, all_albums):
    userAim = []
    for key, value in all_users.items():
        if(value.split(" ")[1]==city): userAim.append(key)
        
    i = 0
    for username in userAim:
        alb = all_users[username].split(" ")[2]
        nameAlb = []
        for name in alb.split("-"):
            nameAlb.append(name)
            
        for nameAlbum in nameAlb:
            if all_albums[nameAlbum].split(" ")[0]==artist_name: i = i + int(all_albums[nameAlbum].split(" ")[2])
            
    return i


def query_city_genre(city, genre, all_users, all_albums):
    userAim = []
    for key, value in all_users.items():
        if(value.split(" ")[1]==city): userAim.append(key)
        
    i = 0
    for username in userAim:
        alb = all_users[username].split(" ")[2]

        nameAlb = []
        for name in alb.split("-"):
            nameAlb.append(name)
            
        for nameAlbum in nameAlb:
            if all_albums[nameAlbum].split(" ")[1]==genre: i = i + int(all_albums[nameAlbum].split(" ")[2])
            
    return i