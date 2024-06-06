#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to add student information to the file
void addStudent(const string& roll_number, const string& name, const string& division, const string& address) {
    ofstream file("student_info.txt", ios::app);
    if (file.is_open()) {
        file << roll_number << "," << name << "," << division << "," << address << "\n";
        cout << "Student information added successfully." << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }
}

// Function to delete student information from the file
void deleteStudent(const string& roll_number) {
    ifstream inFile("student_info.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.substr(0, roll_number.size()) != roll_number) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("student_info.txt");
    rename("temp.txt", "student_info.txt");

    if (found) {
        cout << "Student information deleted successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

// Function to display student information
void displayStudent(const string& roll_number) {
    ifstream file("student_info.txt");
    string line;

    bool found = false;
    while (getline(file, line)) {
        if (line.substr(0, roll_number.size()) == roll_number) {
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main() {
    while (true) {
        cout << "\n1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string roll_number, name, division, address;
                cout << "Enter Roll Number: ";
                cin >> roll_number;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Division: ";
                cin >> division;
                cout << "Enter Address: ";
                cin >> address;
                addStudent(roll_number, name, division, address);
                break;
            }
            case 2: {
                string roll_number;
                cout << "Enter Roll Number to delete: ";
                cin >> roll_number;
                deleteStudent(roll_number);
                break;
            }
            case 3: {
                string roll_number;
                cout << "Enter Roll Number to display: ";
                cin >> roll_number;
                displayStudent(roll_number);
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
