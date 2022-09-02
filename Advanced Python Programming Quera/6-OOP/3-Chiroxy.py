class ExceptionProxy(Exception):
    pass


def transform_exceptions(func_ls):
    exeption_list = []
    for func in func_ls:
        try:
            func()
        except Exception as e:
            r = ExceptionProxy()
            r.msg = str(e)
            r.function = func.__name__
            exeption_list.append(r)
        else:
            r = ExceptionProxy()
            r.msg = "ok!"
            r.function = func.__name__
            exeption_list.append(r)
            
    return exeption_list

def f():
    1/0

def g():
    pass

for ex in transform_exceptions([f, g]):
    print("msg: "+ex.msg)
    print("function name: "+ex.function)
    