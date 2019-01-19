a = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1, 4, 10, 20, 33, 2, 1, 99999, 4, 16,52, 85, 42,12, 34, 21, 9, 43, 88]
#BUILD-MAX-HEAP(a)

def left(sequence, i, heap_size):
    """Returns you left child"""
    if heap_size >= 2 * i + 2: # for length we need index+1 length
                                   # because off-by-zero property of list data-type
        return 2*i + 1 # return sequence[2*i + 1] #abbriviation of 2(i+1)-1
    return None


def right(sequence, i, heap_size):
    """Returns you right child"""
    if heap_size >= 2 * i + 3:
        return 2*i + 2 # sequence[2*i + 2]
    return None


#def parent(sequence, i):
#    """Returns you the parent number"""
#    return sequence[int(i/2)]


def max_heapify(sequence, i, heap_size):
    """
    MAX-HEAPIFIES given value associated with given index and sequence.also the branches.
    make sure do not consider elements that are after heap_size 
    """
    l = left(sequence, i, heap_size)
    r = right(sequence, i, heap_size)
    if l  and sequence[l] > sequence[i]:
        largest = l
    else:
        largest = i
    if r and sequence[r] > sequence[largest]:
        largest = r
    if largest != i:
        sequence[i], sequence[largest] = sequence[largest], sequence[i]
        max_heapify(sequence, largest, heap_size)


def build_max_heap(sequence, heap_size):
    """make sure all root of given sequence has max heap property"""
    for i in range(int(heap_size/2) - 1, -1, -1):
        max_heapify(sequence, i, heap_size)


def heap_sort(sequence):
    """
    make an array ordered by the method named 'heap_sort'
    you need to consider heap_size all the time when you
    deal with heap_sort method
    """
    heap_size = len(sequence)
    build_max_heap(sequence, heap_size)
    print("build_max_heap done...", sequence)
    for i in range(len(sequence)-1, 0, -1):
        sequence[0], sequence[i] = sequence[i], sequence[0]
        heap_size -= 1
        max_heapify(sequence, 0, heap_size)
    print(f"heap_sort done...", sequence)

heap_sort(a)
