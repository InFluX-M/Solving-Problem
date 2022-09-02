def test():

    msg= "salam"

    def test_local():
        msg = "khoobi?"
        print("in function: " + msg)

    def test_nonlocal():
        nonlocal msg
        msg = "chetori?"
        print("in function: " + msg)

    def test_global():
        global msg
        msg = "chera?!"
        print("in function: " + msg)

    test_local()
    print(msg)
    test_nonlocal()
    print(msg)
    test_global()
    print(msg)

test()
print(msg)