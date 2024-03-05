#include <iostream>
#include <fstream>
#include <vector>
#include <cctype> // tolowoer function for options

using namespace std;

struct Question {
	string question;
	char cAnswer;
	char uAnswer;
};

void displayMenu() {
	cout<<"1. Start Test\n";
	cout<<"2. View Test Script\n";
	cout<<"3. Exit\n";
}

void readquestions(vector<Question>& questions, const string& filename) {
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			size_t hyphenPos = line.find('-');//Using this to find the position of the hyphen that comes before the option in the question bank file.
			
			if(hyphenPos != string::npos && hyphenPos + 2 < line.length()) {
				Question q;
				q.question = line.substr(0, hyphenPos);
				q.cAnswer = line[hyphenPos + 2];
				q.uAnswer = ' ';
				questions.push_back(q);
			}
		}
		file.close();
	} else{
		cout<< "Error opening file: "<< filename<<endl;
	}
}

void readusers(vector<string>& users, vector<string>& passwords, const string& filename) {
	ifstream file(filename);
    if (file.is_open()) {
        string user, password;
        while (file >> user >> password) {
            users.push_back(user);
            passwords.push_back(password);
        }
        file.close();
    } else {
        cout << "Could not open file: " << filename << endl;
    }
}

bool authenticateUser(const vector<string>& users, const vector<string>& passwords, string& username, string& password) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i] == username && passwords[i] == password) {
            return true;  // Successful Authentication
        }
    }
    return false;  // Authentication failed
}


void startTest(vector<Question>& questions) {
	char answer;
	int choice;
	
	do{
		for(size_t i = 0; i < questions.size(); ++i) {
			if(questions[i].uAnswer == ' '){
				cout<<"Q"<<i+1<<": "<<questions[i].question<<endl;
				cout<<"Enter either A, B, C, D or S to skip: ";
				cin >> answer;
				answer = tolower(answer);
				
				if (answer == 's') {
					cout<<"Question skipped.\n";
				} else if (answer >= 'a' && answer <= 'd') {
					questions[i].uAnswer = answer;
				}else {
					cout<<"Invalid choice, please select either either A, B, C, D or S to skip: \n";
					--i;
				}
			}
		}
		
		cout << "1. Continue\n";
        cout << "2. Return to skipped questions\n";
        cout << "3. Finish Test\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                break;
            case 2:
                cout << "Returning to skipped questions.\n";
                break;
            case 3:
                cout << "Test completed!\n";
                return;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
	} while(true);
}

void viewTestScript(const vector<Question>& questions) {
    cout << "Test Script:\n";
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "Q" << i + 1 << ": " << questions[i].question << " - Your Answer: " << questions[i].uAnswer << endl;
    }
}

void score(const vector<Question>& questions) {
	int tQuestions = questions.size();
	int cAnswers; //= 0;
	
	for(size_t i = 0; i < questions.size(); ++i) {
		if (questions[i].uAnswer == questions[i].cAnswer){
			++cAnswers;
		}
	}
	
	cout<<"Your Score: " << cAnswers << "/" << tQuestions<<endl;
}

int main() {
    vector<Question> questions;
    vector<string> users;
    vector<string> passwords;

    readquestions(questions, "question_bank.txt");
    readusers(users, passwords, "users.txt");

    string username, password;

    // Authentication loop
    do {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        if (authenticateUser(users, passwords, username, password)) {
            cout << "Authentication successful!\n";
            break;
        } else {
            cout << "Authentication failed. Please try again.\n";
        }
    } while (true);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                startTest(questions);
                break;
            case 2:
                viewTestScript(questions);
                break;
            case 3:
            	cout<<"Score\n";
            	score(questions);
            	cout<<"Exiting the program\n";
            	return 0;
            default:
                cout << "Invalid choice. Choose from options listed above.\n";
        }

    } while (true);

    return 0;
}