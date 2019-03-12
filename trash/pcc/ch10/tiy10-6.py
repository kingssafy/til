while True:
    try:
        a = int(input("first"))
        b = int(input("second"))
    except ValueError:
        print("Number Only")
    else:
        print(a/b)
        if a == 7:
            break
