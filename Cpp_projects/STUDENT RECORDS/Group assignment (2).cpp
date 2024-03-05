#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

struct Record{
    string StudentName;
    int score;
};

//Read Login Credentials
// Ibunkunle Emmanuel
map<string, string> readLoginDetailsFromFile(string filename) {
    map<string, string> loginDetails;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(" - ");
            if (pos != string::npos) {
                string username = line.substr(0, pos);
                string password = line.substr(pos + 3);
                loginDetails[username] = password;
            }
        }
        file.close();
    }
    return loginDetails;
}

//read results
// Henry Okwudili
vector<Record> ReadResults(const string& filename){
    vector<Record> records;
    ifstream file(filename);
    if (!file.is_open()){
        cerr << "Error opening file." << endl;
        exit(EXIT_FAILURE);
    }

    
   string line;
    while (getline(file, line)) {
        size_t pos = line.find(" - ");
        if (pos != string::npos) {
            Record record;
            record.StudentName = line.substr(0, pos);
            record.score = stoi(line.substr(pos + 3));
            records.push_back(record);
        }
    }

    file.close();
    return records;
}
//Ibunkunle Emmanuel & Dumebi Uwajeh
void ViewResults(const vector<Record>& studentRecords){

    // Display the read records
    for (const auto& record : studentRecords) {
        cout << "Name: " << record.StudentName << ", Score: " << record.score << endl;
    }
}

//Validate user login information
//Ibunkunle Emmanuel & Dumebi Uwajeh
bool validateLogin(const map<string, string>& loginDetails, string username, string password) {
    auto it = loginDetails.find(username);
    if (it != loginDetails.end() && it->second == password) {
        return true;
    }
    return false;
}

//Update student scores
//Abdul-Razzaq & Ikoli-spiff Ebifiri
void UpdateStudentScores(vector<Record>& studentRecords) {
    // Display a list of student names and grades
    cout << "List of Students:\n";
    for (const auto& record : studentRecords) {
        cout << "Name: " << record.StudentName << ", Score: " << record.score << endl;
    }

    cout << "\nEnter the name of the student whose score you want to update: ";
    string studentName;
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, studentName);

    // Find the student by name
    auto it = find_if(studentRecords.begin(), studentRecords.end(),
                      [studentName](const Record& record) {
                          return record.StudentName == studentName;
                      });

    if (it != studentRecords.end()) {
        // Student found, update the score
        cout << "Enter the new score for " << studentName << ": ";
        cin >> it->score;
        cout << "Score updated successfully." << endl;
    } else {
        // Student not found
        cout << "Student with name " << studentName << " not found." << endl;
    }
}

//Search for an individual student record
//Henry Okwuduli & Emmanuel Odey
void SearchStudentRecord(const vector<Record>& studentRecords) {
    string searchName;
    cout << "Enter the student name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& record : studentRecords) {
        if (record.StudentName == searchName) {
            cout << "Name: " << record.StudentName << ", Score: " << record.score << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found for student: " << searchName << endl;
    }
}

//Save individual student record to a file
//Ikoli-spiff Ebifiri & Abdul- Razzaq
void SaveIndividualRecord(const Record& studentRecord, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file for saving individual record." << endl;
        return;
    }

    outFile << "Name: " << studentRecord.StudentName << ", Score: " << studentRecord.score << endl;

    outFile.close();
    cout << "Individual record saved successfully." << endl;
}
// Fernando Ameh Stream 1 & Emmanuel Odey
void ManageStudentRecords(vector<Record>& studentRecords) {
    char choice;
    do {
        cout << "\nManage Student Records:" << endl;
        cout << "1. Update Student Scores [U]" << endl;
        cout << "2. Search for an Individual Record [S]" << endl;
        cout << "3. Save Individual Record [I]" << endl;
        cout << "4. Back to Main Menu [B]" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the buffer

        switch (toupper(choice)) {
            case 'U':
                UpdateStudentScores(studentRecords);
                break;
            case 'S':
                SearchStudentRecord(studentRecords);
                break;
            case 'I':
//                SaveIndividualRecord(studentRecords, "individual record.txt");
                break;
            case 'B':
                cout << "Returning to the main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (toupper(choice) != 'B');
}


int main() {
    cout<< "Result Management System"<<endl;
    map<string, string> loginDetails = readLoginDetailsFromFile("authorized users.txt");
    char choice;
    //Dumebi Uwajeh
    string username, password;
    bool loggedIn = false;
    do {
        cout << "Username: ";
        cin>>username;
        cout << "Password: ";
        cin>>password;
        loggedIn = validateLogin(loginDetails, username, password);
        if (!loggedIn) {
            cout << "Incorrect login details. Please try again." << endl;
        }

    } while (!loggedIn);
    cout<< "Login Successful"<< endl;
    cout<<"\nDashboard:\n"<< endl;
    
 // Emmanuel Odey & Fernanddo Ameh 
    vector<Record> studentRecords = ReadResults("student results.txt");
   
    do {
        cout << "1. View all Student Results [V]" << endl;
        cout << "2. Manage Student Records [M]" << endl;
        cout << "3. Exit [X]" << endl;

        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (toupper(choice)) {
            case 'V':
                ViewResults(studentRecords);
                break;
            case 'M':
                ManageStudentRecords(studentRecords);
                break;
            case 'X':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (toupper(choice) != 'X');
    return 0;
}
// Debugging by Emmanuel Odey And Ikoli- spiff Ebifiri
