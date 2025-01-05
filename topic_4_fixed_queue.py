print("Implementing a queue to manage a fixed number of orders when they exceed it returns a warning:")
class FixedOrderQueue:
    def __init__(self, size):
        self.queue = []
        self.size = size

    def enqueue(self, order):
        if len(self.queue) >= self.size:
            print("Queue is full, cannot add order.")
        else:
            self.queue.append(order)

    def dequeue(self):
        if len(self.queue) == 0:
            print("Queue is empty.")
        else:
            return self.queue.pop(0)

    def display(self):
        print("Current orders in queue:", self.queue)
# Usage
order_queue = FixedOrderQueue(3)
print('after enqueue operation:')
order_queue.enqueue("Order 1")
order_queue.enqueue("Order 2")
order_queue.enqueue("Order 3")
order_queue.enqueue("Order 4")
order_queue.display()

order_queue.dequeue()
print('after dequeue operation:')
order_queue.display()
