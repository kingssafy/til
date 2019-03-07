def recurse(array, X, before=0):
    count = 0
    if len(array) == count:
        return True
    if not before:
        before = array[0]
    for idx, height in enumerate(array):
        if before == height:
            count += 1
            continue
        elif height == before + 1 and count >= X:
            return recurse(array[idx:], X)
        elif height == before - 1 and array[idx:idx+X] == [array[idx]]*(X):
            return recurse(array[idx+X:], X, height)
        elif height == before -1 and array[idx:] == [array[idx]] *len(array[idx:]) and len(array[idx:]) >= X:
            return True
        else:
            return False
    return True

a = [3, 3, 2, 2, 2, 1, 1, 1]
print(recurse(a,3))