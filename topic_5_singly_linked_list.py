print("Implementing a singly linked list:")

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")
# Usage
linked_list = SinglyLinkedList()
linked_list.insert("Course 1")
linked_list.insert("Course 2")
print('after adding data to the list:')
linked_list.display()
