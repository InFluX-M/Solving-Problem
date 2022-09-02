import re


def validate_email(email):
    return re.match(r'^[\w\.]+@[a-zA-Z0-9]+\.[a-zA-Z]{3}$', email)


def validate_phone(number):
    return re.match(r'^09[\d]{9}$', number) or re.match(r'^\+989[\d]{9}$', number) or re.match(r'^00989[\d]{9}$', number)