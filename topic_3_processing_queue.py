print("Implementing a Circular Queue and Performing enqueue a operations for processing:")

class LMSProcessingQueue:
    def __init__(self, size):
        self.queue = [None] * size
        self.size = size
        self.front = self.rear = -1

    def enqueue(self, task):
        if (self.rear + 1) % self.size == self.front:
            print("Queue is full")
        elif self.front == -1:
            self.front = self.rear = 0
            self.queue[self.rear] = task
        else:
            self.rear = (self.rear + 1) % self.size
            self.queue[self.rear] = task

    def dequeue(self):
        if self.front == -1:
            print("Queue is empty")
        elif self.front == self.rear:
            task = self.queue[self.front]
            self.front = self.rear = -1
            return task
        else:
            task = self.queue[self.front]
            self.front = (self.front + 1) % self.size
            return task
    def display(self):
      if self.front == -1:
        print("Queue is empty")
      elif self.rear >= self.front:
        print("Queue:", self.queue[self.front : self.rear + 1])
      else:
        print("Queue:", self.queue[self.front:] + self.queue[: self.rear + 1])
# Usage
processing_queue = LMSProcessingQueue(5)
print('after enqueue operation:')
processing_queue.enqueue("Grade Assignment")
processing_queue.enqueue("Update Student Info")
processing_queue.display()
processing_queue.dequeue()
print('after dequeue operation:')
processing_queue.display()
