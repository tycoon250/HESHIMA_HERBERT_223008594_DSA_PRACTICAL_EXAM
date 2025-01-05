print("Implementing a Circular Queue and Performing enqueue and deque operations for managing data:")
class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.queue = [None] * size
        self.front = self.rear = -1

    def enqueue(self, data):
        if (self.rear + 1) % self.size == self.front:
            print("Queue is full")
        elif self.front == -1:
            self.front = self.rear = 0
            self.queue[self.rear] = data
        else:
            self.rear = (self.rear + 1) % self.size
            self.queue[self.rear] = data

    def dequeue(self):
        if self.front == -1:
            print("Queue is empty")
        elif self.front == self.rear:
            item = self.queue[self.front]
            self.front = self.rear = -1
            return item
        else:
            item = self.queue[self.front]
            self.front = (self.front + 1) % self.size
            return item

    def display(self):
        if self.front == -1:
            print("Queue is empty")
        elif self.rear >= self.front:
            print("Queue:", self.queue[self.front : self.rear + 1])
        else:
            print("Queue:", self.queue[self.front:] + self.queue[: self.rear + 1])
# Usage

queue = CircularQueue(5)
queue.enqueue("Student 1")
queue.enqueue("Student 2")
print('after enqueue operation:')
queue.display()
queue.dequeue()
print('after dequeue operation:')
queue.display()
