#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
using namespace std;

struct question{
	string questiontxt;
	char answer;
	vector<char>options;
};

struct user{
	string username;
	string password;
	int score;
};

vector<user> val_id;
vector<question> Questions;

void readquestions(string filename){
	ifstream file(filename);
	if (!file.is_open()) {
		cout<<"Unable to open file: " << filename << endl;
		return; 
	}
	
	question a;
	while(getline(file, a.questiontxt)){
		file >> a.answer;
		file.ignore();
		string options;
		getline(file, options);
		
		for (char option : options) {
			if (option != ' ') {
				a.options.push_back(option);
			}
		}
		Questions.push_back(a);
	}
	file.close();
}

void readusers(const string& filename){
	ifstream file(filename);
	
	if (!file.is_open()){
		cout<<"Error opening file: "<< filename << endl;
		exit(1);
	}
	
	
	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		string username, password;
		
		getline(ss, username, ',');
		getline(ss, password, ',');
		val_id.push_back({username, password});
		
	}
	
	user u_ser;
bool validateLogin(string username, string password) {
    for (const user& u_ser : val_id) {
        if (u_ser.username == username && u_ser.password == password) {
            return true;
        }
    }
    return false;
}

int main() {
	readquestions("C:\\Users\\Henry\\OneDrive\\Documents\\CSC201\\Projects\\Holiday Assignment (VER1)\\questions.csv");
	readusers("C:\\Users\\Henry\\OneDrive\\Documents\\CSC201\\Projects\\Holiday Assignment (VER1)\\UserValidationFile(CSC201).csv");
	

	string username, password;
	cin >> username;
	cout << "Enter Password: " << endl;
	cin >> password;
	
	if(validatelogin(username, password)){
		cout << "Login successful"<<endl;
	} else {
		cout<<"Invalid login details."<<endl;
	}
	
	
	
	//cout << "Your score is: " << user.score << "/" << 10<<endl;
	return 0;
}


