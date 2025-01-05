print("Implementing a tree to represent hierarchical data:")

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def display(self, level=0):
        print(" " * level * 4 + self.data)
        for child in self.children:
            child.display(level + 1)

# Usage
root = TreeNode("LMS Root")
student_section = TreeNode("Students")
course_section = TreeNode("Courses")
root.add_child(student_section)
root.add_child(course_section)
student_section.add_child(TreeNode("Student 1"))
course_section.add_child(TreeNode("Course 1"))
root.display()
