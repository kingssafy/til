a = [3, 2, 1, 5, 6, 4, 3, 8, 10, 9]
#BUILD-MAX-HEAP(a)
"""
                3
        2               1
    5        6      4        3
  8  10    9
"""

def left(sequence, i):
    """Returns you left child"""
    if len(sequence) >= 2 * (i + 1): # we need (index+1)*2 length of sequence
        return sequence[2*i + 1] #abbriviation of 2(i+1)-1
    return None
def right(sequence, i):
    if len(sequence) >= 2 * i + 1:
        return sequence[2*i + 1]

print(left(a, 1))