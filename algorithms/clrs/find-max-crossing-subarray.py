def find_max_crossing_subarray(A, low, mid, high):
    left_sum = -9999
    sum = 0
    for i in range(mid, low - 1, -1):
        sum += A[i]
        if sum > left_sum:
            left_sum = sum
            max_left = i
    right_sum = -9999
    sum = 0
    for i in range(mid+1, high + 1):
        sum += A[i]
        if sum > right_sum:
            right_sum = sum
            max_right = i

    return (max_left, max_right, left_sum + right_sum)


def find_maximum_subarray(A, low, high):
    if high == low:
        return(low, high, A[low])
    else:
        mid = int((low + high)/2)
        left_low, left_high, left_sum = find_maximum_subarray(A, low, mid)
        right_low, right_high, right_sum = find_maximum_subarray(A, mid+1, high)
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(A, low, mid, high)
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum

A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]

print(find_maximum_subarray(A, 0, len(A)-1))



def linear_maximum_subarray(A):
    M = -99999
    low_m, high_m = 0, 0
    temp_M = 0
    temp_left = 0
    for i in range(len(A)):
        temp_M += A[i]
        if temp_M > M:
            M = temp_M
            low_m = temp_left
            high_m = i
        if temp_M < 0:
            temp_left = i+1
            temp_M = 0
    return (low_m, high_m, M)

print(linear_maximum_subarray(A))
