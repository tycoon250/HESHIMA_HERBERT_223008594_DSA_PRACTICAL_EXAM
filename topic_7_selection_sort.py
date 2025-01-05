print("Implementing a Selection Sort to sort data based on priority:")

def selection_sort(data):
    for i in range(len(data)):
        min_idx = i
        for j in range(i + 1, len(data)):
            if data[j][1] < data[min_idx][1]:
                min_idx = j
        data[i], data[min_idx] = data[min_idx], data[i]
    return data

# Usage
tasks = [("Task A", 3), ("Task B", 1), ("Task C", 2)]
print(f'data before sorting:{tasks}')
sorted_tasks = selection_sort(tasks)
print("Sorted tasks by priority:", sorted_tasks)
