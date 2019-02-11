from math import ceil

class Heap():
    def __init__(self, array):
        self.heap = array
        self.heapsize = len(array) - 1
    
    def left(self, node):
        return 2*node + 1 if 2*node + 1 <= self.heapsize else False

    def right(self, node):
        return 2*node + 2 if 2*node + 2 <= self.heapsize else False

    def parent(self, node):
        return int(ceil(node/2)-1) if node > 0 else False

    def max_heapify(self, node):
        greatest = node
        if self.left(node) and self.heap[self.left(node)] > self.heap[greatest]:
            greatest = self.left(node)
        if self.right(node) and self.heap[self.right(node)] > self.heap[greatest]:
            greatest = self.right(node)
        if greatest != node:
            self.heap[greatest], self.heap[node] = self.heap[node], self.heap[greatest]
            self.max_heapify(greatest)
    def build_max_heap(self):
        for node in range(ceil(self.heapsize/2)-1, -1, -1):
            self.max_heapify(node) 
    
    def heapsort(self):
        self.build_max_heap()
        while self.heapsize > 0:
            self.heap[0], self.heap[self.heapsize] = self.heap[self.heapsize], self.heap[0]
            self.heapsize = self.heapsize - 1
            print(f"-----current heap size {self.heapsize}------")
            self.max_heapify(0)
    def tree(self):
        pass

    def maximum(self):
        return self.heap[0]

    def extract_max(self):
        if self.heapsize < 0:
            print("heap underflow")
        max = self.heap[0]
        self.heap[0] = self.heap[self.heapsize]
        self.heapsize -= 1
        self.max_heapify(0)
        return max
    
    def increase_key(self, node, key):
        if key < self.heap[node]:
            print("new key is smaller than current key")
            return
        self.heap[node] = key
        while node > 0 and self.heap[self.parent(node)] < self.heap[node]:
            self.heap[self.parent(node)], self.heap[node] = self.heap[node], self.heap[self.parent(node)]
            print(node, self.parent(node))
            node = self.parent(node) 
    
    def insert(self, key):
        self.heapsize += 1
        self.heap.append(-1)
        self.increase_key(self.heapsize, key)




a = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1, 4, 10, 20, 33, 2, 99999, 4, 16,52, 85, 42,12, 34, 21, 9, 43, 88]
if __name__ == "__main__":
    a = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1, 4, 10, 20, 33, 2, 99999, 4, 16,52, 85, 42,12, 34, 21, 9, 43, 88]
    heap = Heap(a)
    heap.heapsort()
    print(heap.heap)
