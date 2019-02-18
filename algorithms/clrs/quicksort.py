#left quicksort

def quicksort(array,p, r):
    if p<r:
        key = partition(array, p, r)
        quicksort(array, p, key -1)
        quicksort(array, key + 1, r)


def partition(array, p, r): #possibly 0 or 1
    keyvalue = array[p]
    print(f"keyvalue=> {keyvalue}")
    i = p
    for j in range(p+1, r + 1):
        if array[j] <= keyvalue:
            i = i + 1
            array[j], array[j] = array[i], array[j]
    array[i], array[p] = array[p], array[i]
    print(f"partitioned array {array}")
    print(f"current(i,j) {i,j}")
    return i


array= [1,4,6,8,9,15,6,14]

quicksort(array,0,len(array)-1)

print(array)



