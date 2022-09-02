def check_registration_rules(**kwargs):
    
    username = []
    
    for key, value in kwargs.items():
        if len(value)>=6 and len(key)>=4 and key!="quera" and key!="codecup" and (not value.isdigit()): username.append(key)
        
    return username