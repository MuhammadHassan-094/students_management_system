#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    string department;

public:
    // Default Constructor
    Student() {
        id = 0;
        name = "";
        age = 0;
        department = "";
    }

    // Parameterized Constructor
    Student(int i, string n, int a, string d) {
        id = i;
        name = n;
        age = a;
        department = d;
    }

    // Setter
    void setStudent(int i, string n, int a, string d) {
        id = i;
        name = n;
        age = a;
        department = d;
    }

    // Getters
    int getId() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    string getDepartment() { return department; }

    // Display
    void display() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Age: " << age
             << " | Department: " << department << endl;
    }
};

class StudentManagementSystem {
private:
    Student students[100]; // Fixed array (no vector)
    int count;

public:
    StudentManagementSystem() { count = 0; }

    void addStudent() {
        if (count >= 100) {
            cout << "Database full! Cannot add more students.\n";
            return;
        }
        int id, age;
        string name, dept;
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, dept);

        students[count].setStudent(id, name, age, dept);
        count++;
        cout << "Student added successfully!\n";
    }

    void displayAllStudents() {
        if (count == 0) {
            cout << "No students found.\n";
            return;
        }
        cout << "\n--- Student List ---\n";
        for (int i = 0; i < count; i++) {
            students[i].display();
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;
        for (int i = 0; i < count; i++) {
            if (students[i].getId() == id) {
                cout << "Student Found:\n";
                students[i].display();
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void updateStudent() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;
        for (int i = 0; i < count; i++) {
            if (students[i].getId() == id) {
                string name, dept;
                int age;
                cin.ignore();
                cout << "Enter New Name: ";
                getline(cin, name);
                cout << "Enter New Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter New Department: ";
                getline(cin, dept);

                students[i].setStudent(id, name, age, dept);
                cout << "Student updated successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;
        for (int i = 0; i < count; i++) {
            if (students[i].getId() == id) {
                // Shift all elements left
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                cout << "Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sms.addStudent();
            break;
        case 2:
            sms.displayAllStudents();
            break;
        case 3:
            sms.searchStudent();
            break;
        case 4:
            sms.updateStudent();
            break;
        case 5:
            sms.deleteStudent();
            break;
        case 6:
            cout << "Exiting... Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
