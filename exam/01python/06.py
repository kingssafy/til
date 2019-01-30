def sumof(string):
    for char in string:
        if char not in "1234567890":
            string = string.replace(char,"  ")
    return sum(map(int,string.split()))
