#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

// Defining a structure for questions
struct Question {
    string questionText;
    char correctOption;
    vector<char> options;
};

// Function to take a test
void takeTest(const vector<Question>& questions) {
    int score = 0;

    for (const Question& q : questions) {
        cout << q.questionText << endl;
        
        for (char option : q.options) {
            cout << option << ". " << option << endl;
        }

        char choice;
        cin >> choice;

        if (tolower(choice) == tolower(q.correctOption)) {
            score++;
        }
    }

    cout << "Your score: " << score << "/" << questions.size() << endl;
}

int main() {
    // Sample questions
    vector<Question> questions = {
        {"What is 2 + 2?", 'D', {'A', 'B', 'C', 'D'}},
        {"Which planet is closest to the Sun?", 'A', {'A', 'B', 'C', 'D'}}
    };

    // Start test
    takeTest(questions);

    return 0;
}

