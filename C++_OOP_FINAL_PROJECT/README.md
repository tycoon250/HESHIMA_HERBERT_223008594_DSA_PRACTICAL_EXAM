# Student Grade Statistics – C++ Project

**Author:** Heshima Herbert 223008594
**Course Task:** Student Grade Analysis with Classes, Structs, and Polymorphism  

---

## Task Description

> Each student was assigned a unique project. This specific project required us to compute statistics on student grade arrays using C++ classes and struct-based design.

### The required tasks included:

- Defining a `StudentRecord` struct with a name, pointer to dynamically allocated grades, and a count of grades.
- Creating an abstract class `Statistics` with a pure virtual function `compute(const StudentRecord*)`.
- Creating two child classes:
  - `MeanCalculator` to compute the average grade.
  - `StdDevCalculator` to compute the standard deviation.
- Using `Statistics*` pointers to store and call these operations dynamically (polymorphism).
- Using pointer arithmetic or array indexing to process grades.
- Allowing users to add and remove students dynamically (no fixed input).
- Implementing a **user-friendly menu interface** (no hardcoded data).
- Annotating code with detailed comments for every line.

---

## How It Was Completed

The program was designed step-by-step, starting from the `StudentRecord` struct, all the way to a clean and functional menu-driven application. Here's how the task was tackled:

- **Defined Struct**: Used `char name[30]`, `float* grades`, and `int nGrades` to store student data.
- **Created Base Class**: The `Statistics` class declared a pure virtual method `compute()`.
- **Derived Classes**: `MeanCalculator` and `StdDevCalculator` inherited from `Statistics` and implemented the required logic.
- **Polymorphic Dispatch**: Used `Statistics* ops[]` to store and call operations dynamically.
- **Dynamic Input**: Used `cin`, `cin.getline()`, and `new[]` to take input without hardcoding.
- **User Interface**: Built a simple text-based menu to add/remove/list students and calculate stats.
- **Memory Management**: Used `delete[]` to avoid memory leaks when removing students or exiting.
- **Code Annotation**: Every line in the program is commented to explain its purpose.

---

## ▶️ How to Run the Program

> You need a C++ compiler like `g++`.

1. Save the code as `main.cpp`
2. Open your terminal or command prompt
3. Compile the code:
   ```bash
   g++ exam.cpp -o student_stats
