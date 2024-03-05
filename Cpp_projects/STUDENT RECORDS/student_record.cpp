#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    char name[50];
    int rollNumber;
    float courseScore;
    // Add any other information as needed
};

void readStudentRecords(Student*& students, int& numStudents) {
    ifstream recordFile("records.txt");
    if (!recordFile) {
        cerr << "Error: Unable to open records file." << endl;
        exit(EXIT_FAILURE);
    }

    recordFile >> numStudents;
    students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        recordFile >> students[i].name >> students[i].rollNumber >> students[i].courseScore;
    }

    recordFile.close();
}

void writeStudentRecords(const Student* students, int numStudents) {
    ofstream recordFile("records.txt");
    if (!recordFile) {
        cerr << "Error: Unable to open records file." << endl;
        exit(EXIT_FAILURE);
    }

    recordFile << numStudents << endl;

    for (int i = 0; i < numStudents; ++i) {
        recordFile << students[i].name << " " << students[i].rollNumber << " " << students[i].courseScore << endl;
    }

    recordFile.close();
}

void storeRecordToFile() {
    int numStudents;
    Student* students;

    // Read existing records
    readStudentRecords(students, numStudents);

    // Prompt user for new record details
    cout << "\nEnter the details of the new student record:" << endl;
    cout << "Name: ";
    cin >> students[numStudents].name;

    cout << "Roll Number: ";
    cin >> students[numStudents].rollNumber;

    cout << "Course Score: ";
    cin >> students[numStudents].courseScore;

    // Increment the number of students
    numStudents++;

    // Write the updated records to file
    writeStudentRecords(students, numStudents);

    cout << "\nRecord stored successfully!" << endl;
}

int main(){
	
}