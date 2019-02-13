for _ in range(int(input())):
    result = [0, 0]
    for char in input():
        result[0] += 1 if char in "(" else -1 if char in ")" else 0
        result[1] += 1 if char in "{" else -1 if char in "}" else 0
        if -1 in result: break
    else:
        print(1)
        break
    print(0) 
