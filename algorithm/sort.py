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
    if len(sequence) >= 2 * i + 2: # for length we need index+1 length
                                   # because off-by-zero property of list
        return sequence[2*i + 1] #abbriviation of 2(i+1)-1
    return None
def right(sequence, i):
    """Returns you right child"""
    if len(sequence) >= 2 * i + 3:
        return sequence[2*i + 2]
def parent(sequence, i):
    """Returns you the parent number"""
    return sequence[int(i/2)]

def max_heapify(sequence, i):

