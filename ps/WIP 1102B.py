n, k = 5, 2 # n = len(array), colors

array = [3, 2, 1, 2, 3] #given array 
answersheet = [0]*n
sorted_array = sorted(array)

while sorted_array:
    for color in range(1,k+1):
        current_num = sorted_array.pop(0)
        answersheet[array.index(current_num)] += color
        array[array.index(current_num)] = 0
        if not sorted_array:
            break
print(answersheet)

