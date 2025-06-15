#include <iostream>    // for input and output (cin, cout)
#include <cmath>       // for math functions like sqrt()
#include <cstring>     // for string comparison (strcmp)

using namespace std;   // to avoid writing std:: everywhere

// ==============================
// STRUCT TO HOLD STUDENT DATA
// ==============================

struct StudentRecord {
    char name[30];     // student name
    float* grades;     // pointer to an array of grades
    int nGrades;       // number of grades
};

// ==============================
// ABSTRACT BASE CLASS (INTERFACE)
// ==============================

class Statistics {
public:
    // Pure virtual function: all children must implement this
    virtual float compute(const StudentRecord* student) = 0;
};

// ==============================
// CHILD CLASS TO CALCULATE MEAN
// ==============================

class MeanCalculator : public Statistics {
public:
    // Override compute function to calculate average
    float compute(const StudentRecord* student) {
        float sum = 0; // store total sum

        // loop through grades using normal array indexing
        for (int i = 0; i < student->nGrades; i++) {
            sum += student->grades[i]; // add each grade to sum
        }

        // avoid divide by zero
        if (student->nGrades == 0) return 0;

        // return the average
        return sum / student->nGrades;
    }
};

// ==============================
// CHILD CLASS TO CALCULATE STD DEVIATION
// ==============================

class StdDevCalculator : public Statistics {
public:
    float compute(const StudentRecord* student) {
        // create mean calculator object
        MeanCalculator meanCalc;

        // get the average of the student's grades
        float mean = meanCalc.compute(student);

        float sumSquares = 0; // total of squared differences

        // loop through grades
        for (int i = 0; i < student->nGrades; i++) {
            float diff = student->grades[i] - mean; // difference from mean
            sumSquares += diff * diff;              // square it and add to sum
        }

        if (student->nGrades == 0) return 0; // avoid divide by zero

        // return the square root of variance (std deviation)
        return sqrt(sumSquares / student->nGrades);
    }
};

// ==============================
// GLOBAL VARIABLES FOR STUDENT LIST
// ==============================

StudentRecord* students = nullptr; // pointer to dynamic student array
int studentCount = 0;              // number of students

// ==============================
// FUNCTION TO ADD STUDENT
// ==============================

void addStudent(StudentRecord newStudent) {
    // create a new bigger array
    StudentRecord* newList = new StudentRecord[studentCount + 1];

    // copy all old students to the new array
    for (int i = 0; i < studentCount; i++) {
        newList[i] = students[i];
    }

    // add the new student at the end
    newList[studentCount] = newStudent;

    // delete old student list from memory
    delete[] students;

    // point students to the new list
    students = newList;

    // increase the student count
    studentCount++;
}

// ==============================
// FUNCTION TO REMOVE A STUDENT BY NAME
// ==============================

void removeStudent(const char* name) {
    int index = -1; // index of student to remove

    // loop through students to find the one to delete
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, name) == 0) {
            index = i; // found it!
            break;
        }
    }

    // if student not found
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    // create a smaller array
    StudentRecord* newList = new StudentRecord[studentCount - 1];

    int j = 0; // index for new list
    for (int i = 0; i < studentCount; i++) {
        if (i != index) {
            newList[j++] = students[i]; // copy all but the one to remove
        } else {
            delete[] students[i].grades; // free memory for grades
        }
    }

    // delete old list
    delete[] students;

    // point to the new list
    students = newList;

    // reduce the count
    studentCount--;

    cout << "Student removed.\n";
}

// ==============================
// FUNCTION TO SHOW ALL STUDENTS
// ==============================

void showStudents() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    // print each student
    for (int i = 0; i < studentCount; i++) {
        cout << (i + 1) << ". " << students[i].name << "\n";
    }
}

// ==============================
// MAIN PROGRAM
// ==============================

int main() {
    // create objects for mean and std dev
    Statistics* meanCalc = new MeanCalculator();
    Statistics* stdDevCalc = new StdDevCalculator();

    int choice; // menu choice from user

    // loop until user exits
    while (true) {
        // show menu
        cout << "\n==== STUDENT MENU ====\n";
        cout << "1. Add student\n";
        cout << "2. Show student stats\n";
        cout << "3. Remove student\n";
        cout << "4. List all students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear newline from input buffer

        if (choice == 1) {
            // === ADD STUDENT ===
            StudentRecord s;

            cout << "Enter student name: ";
            cin.getline(s.name, 30); // get full name

            cout << "How many grades? ";
            cin >> s.nGrades;

            s.grades = new float[s.nGrades]; // allocate memory for grades

            for (int i = 0; i < s.nGrades; i++) {
                cout << "Enter grade " << (i + 1) << ": ";
                cin >> s.grades[i]; // get each grade
            }

            addStudent(s); // call the add function
            cout << "Student added.\n";
        }

        else if (choice == 2) {
            // === SHOW STATS ===
            char name[30];
            cout << "Enter student name: ";
            cin.ignore(); // in case previous input left a newline
            cin.getline(name, 30);

            bool found = false;

            for (int i = 0; i < studentCount; i++) {
                if (strcmp(students[i].name, name) == 0) {
                    // get stats
                    float mean = meanCalc->compute(&students[i]);
                    float stdDev = stdDevCalc->compute(&students[i]);

                    // print stats
                    cout << "Mean: " << mean << "\n";
                    cout << "Standard Deviation: " << stdDev << "\n";

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 3) {
            // === REMOVE STUDENT ===
            char name[30];
            cout << "Enter name to remove: ";
            cin.ignore();
            cin.getline(name, 30);

            removeStudent(name); // remove by name
        }

        else if (choice == 4) {
            // === LIST STUDENTS ===
            showStudents();
        }

        else if (choice == 5) {
            // === EXIT PROGRAM ===
            break;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    // ============================
    // CLEAN UP MEMORY ON EXIT
    // ============================

    for (int i = 0; i < studentCount; i++) {
        delete[] students[i].grades; // free each grade array
    }

    delete[] students;     // delete full student list
    delete meanCalc;       // delete mean calculator
    delete stdDevCalc;     // delete std dev calculator

    cout << "Goodbye!\n";
    return 0;
}
