
def merge(array,start,half,end):
    left = []
    right = []
    left_n  = half - start + 1
    right_n = end - half
    
    for i in range(left_n):
        left.append(array[start+i])
    for i in range(right_n):
        right.append(array[half+i+1])
    # put sentinels each
    left.append(999999)
    right.append(999999)
    #now merging
    l=0
    r=0
    for idx in range(end-start+1):
        if left[l] <= right[r]:
            array[start+idx] = left[l]
            l += 1
        else:
            array[start+idx] = right[r]
            r += 1
def merge_sort(array,start,end):
    if start < end:
        half = int((start+end)/2)
        merge_sort(array, start, half)
        merge_sort(array, half+1, end)
        merge(array, start, half, end)
        print(array)


array = [4, 3,6,7,8,9,123,4,5,6,767,768,123,7889,121,213,1234,123,11213]

merge_sort(array,0,len(array)-1)
print(array)
