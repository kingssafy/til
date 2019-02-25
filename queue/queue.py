class Queue():
    
    def __init__(self):
        self.queue = [0]*100
        self.front = -1
        self.rear = -1
    def enqueue(self, data):
        if self.rear >= 100:
            return False
        self.rear += 1
        self.queue[self.rear] = data
        return True

    def dequeue(self):
        if not isEmpty(self) and len(self.queue)>=1 and self.front < 99:
            self.front += 1
            return self.queue[self.front]
        else:
            return False
    def isEmpty(self):
        return self.front == self.rear



def isFUll():
    global front, rear
    return (rear+1) % len(Q) == front

def isEmpty():
    global front, rear
    return front == rear

def enQueue(item):
    global rear
    if isFull(): print("Queue is full")
    else:
        rear = (rear+1) % len(Q)
        Q[rear] = item

def deQueue():
    global front
    if isEmpty(): print("Queue is empty")
    else:
        front = (front+1)%len(Q)
        return Q[front]
