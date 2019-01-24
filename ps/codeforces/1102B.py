"""
idea
sort given array
iterate through sorted array
; you mark your color(1~k) in answersheet
    and flag +=1
get different number
reset the flag
"""
n, k = map(int, input().split())   #5, 2 # n = len(array), colors

array = list(map(int, input().split()))  # [3, 2, 1, 2, 3] #given array 
answersheet = [0]*n
sorted_array = sorted(array)
for key in set(array):  # was for key in range(1, n+1) <<-- counter-input 3 2; 5000 5000 5000; output = YES answer:no
    if array.count(key) > k:
        print(f"NO")
        break 
else:
    while sorted_array:
        for color in range(1,k+1): # i did this way because i have to use all of the given colours
            current_num = sorted_array.pop(0)
            answersheet[array.index(current_num)] += color
            array[array.index(current_num)] = 0
            if not sorted_array:
                break
    print("YES")
    print(" ".join(map(str, answersheet)))
