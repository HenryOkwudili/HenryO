#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Question{
	string question;
	char correctAnswer;
};

void menu(){
	cout<< "1. Start Test\n";
	cout<< "2. View Test Script\n";
	cout<< "3. Exit\n";
}

void readquestions(vector<Question>& questions, const string& filename) {
	ifstream file(filename);
	if(file.is_open()){
		string line;
		while (getline(file, line)) {
			size_t hyphenPos = line.find('-');
			
			if(hyphenPos != string::npos && hyphenPos + 2 < line.length()) {
				Question q;
				q.question = line.substr(0, hyphenPos);
				q.correctAnswer = line[hyphenPos + 2];
				questions.push_back(q);
			}
		}
		file.close();
	} else{
		cout<<"Erro opening file: "<< filename << endl;
	}
}

void readusers(vector<string>& users, vector<string>& passwords, const string& filename){
	ifstream file(filename);
	if(file.is_open()) {
		string user, password;
		while (file >> user >> password) {
			users.push_back(user);
			passwords.push_back(password);
		}
		file.close();
	} else{
		cout<<"Error opening file: "<< filename<< endl;
	}
}

bool validUser(const vector<string>& users, const vector<string>& passwords, const string&username, const string& password) {
	for(size_t i = 0; i < users.size(); ++i) {
		if (users[i] == username && passwords[i] == password) {
			return true;
		}
	}
	return false;
}

void startTest(const vector<Question>& questions) {
	char answer;
	for(size_t i = 0; i < questions.size(); ++i){
		cout << "Q" << i + 1 << ": " << questions[i].question << endl;
        cout << "Enter your answer (A, B, C, D): ";
        cin >> answer;
	}
	cout << "Test completed";
}

void viewTestScript(const vector<Question>& questions, const vector<char>& userAnswers) {
    
   /* const int Qwidth = 50;
    const int Awidth = 10;
    
    cout << setw(Qwidth) << left << "Question" << setw(Awidth) << left << "Your Answer" << endl;
    
    for(size_t i = 0; i < questions.size(); ++i) {
    	cout<< setw(Qwidth) << left << "Q" << i + 1 << ": " +questions[i].question
    		<< setw(Awidth) << left << " - " << userAnswers[i] << endl;
	} */
	
	cout << "Question                                               Your Answer" << endl;

    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "Q" << i + 1 << ": " << setw(50) << left << questions[i].question
             << setw(10) << left << " - " << userAnswers[i] << endl;
    }
} 

int main(){
	vector<Question> questions;
	vector<char>userAnswers;
	
	readquestions(questions, "question_bank.txt");
	vector<string> users;
	vector<string> passwords;
	
	readusers(users, passwords, "users.txt");
	
	string username, password;
	
	do{
		cout<<"Enter your username: ";
		cin>>username;
		cout<<"Enter your password: ";
		cin>>password;
		
		if(validUser(users, passwords, username, password)) {
			cout<<"Login successful.\n";
			break;
		} else{
			cout<<"Login failed, Incorrect username or password.\n";
		}
	} while(true);
	
	int choice;
	
	do{
		menu();
		cout<<"Pick a number from the menu: ";
		cin>>choice;
		
		switch (choice) {
			case 1:
				startTest(questions);
				break;
			case 2:
				viewTestScript(questions, userAnswers);
				break;
			case 3:
				cout<<"Exiting the program.\n";
				break;
			default:
				cout<<"Not available, please pick a choice displayed above.\n"	;
		}
	} while(choice !=3);
	
	return 0;
}

