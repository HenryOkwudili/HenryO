#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// My functions
bool login();
void displayQuestions(const vector<string>& questions);
int takeQuiz(const vector<string>& questions);

int main() {
	
ifstream questionsFile("question_bank.txt");
if (!questionsFile.is_open()) {
    cerr << "Error opening questions file.\n";
    return 1;
}

vector<string> questions;
string line;
while (getline(questionsFile, line)) {
    questions.push_back(line);
}

if (questions.empty()) {
    cerr << "No questions found in the file.\n";
    questionsFile.close();
    return 1;
}

questionsFile.close();
//...................................................................................................................
    if (login()) {
        // Read questions from a file
        ifstream questionsFile("question_bank.txt");
        if (!questionsFile.is_open()) {
            cerr << "Error opening questions file.\n";
            return 1;
        }

        vector<string> questions;
        string line;
        while (getline(questionsFile, line)) {
            questions.push_back(line);
        }

        questionsFile.close();

        // Display and take the quiz
        displayQuestions(questions);
        int score = takeQuiz(questions);

        // Display the score
        cout << "\nYour score: " << score << "/" << questions.size() << endl;
    }

    return 0;
}

bool login() {
    string username, password;

    cout << "Welcome to the CBT program\n";

    // Get username and password
    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    // Check credentials against a file
    ifstream userFile("users.txt");
    if (!userFile.is_open()) {
        cerr << "Error opening user file.\n";
        return false;
    }

    string storedUsername, storedPassword;
    while (userFile >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            userFile.close();
            return true; // Successful login
        }
    }

    cout << "Invalid username or password. Please try again.\n";
    userFile.close();
    return false;
}

void displayQuestions(const vector<string>& questions) {
    cout << "\n=== Quiz Questions ===\n";
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << i + 1 << ". " << questions[i] << endl;
    }
}

int takeQuiz(const vector<string>& questions) {
    int score = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        string answer;
        cout << "\nQuestion " << i + 1 << ": " << questions[i] << endl;
        cout << "Your answer: ";
        cin >> answer;

        // For simplicity, let's assume the correct answers are 'A', 'B', 'C', etc.
        char correctAnswer = static_cast<char>('A' + i % 26);

        if (answer.size() == 1 && toupper(answer[0]) == correctAnswer) {
            cout << "Correct!\n";
            ++score;
        } else {
            cout << "Incorrect. The correct answer is " << correctAnswer << ".\n";
        }
    }

    return score;
}
