#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
private :
	int id;
	string first_name;
	string last_name;
	string email;
	string password;
	int age;

public:

	Student() {
	}

	Student(int id, string first_name, string last_name, string email, string password, int age) {
		this->id = id;
		this->first_name = first_name;
		this->last_name = last_name;
		this->email = email;
		this->password = password;
		this->age = age;
	}

	int getID() {
		return this->id;
	}

	string getFirstName() {
		return this->first_name;
	}

	string getLastName() {
		return this->last_name;
	}

	string getEmail() {
		return this->email;
	}

	string getPassword() {
		return this->password;
	}

	int getAge() {
		return this->age;
	}

	void setID(int id) {
		this->id = id;
	}

	void setFirstName(string first_name) {
		this->first_name = first_name;
	}

	void setLastName(string last_name) {
		this->last_name = last_name;
	}

	void setEmail(string email) {
		this->email = email;
	}

	void setPassword(string password) {
		this->password = password;
	}

	void setAge(int age) {
		this->age = age;
	}
	
	void descriereStudent() {
		cout << "ID : " << this->id << endl;
		cout << "First Name : " << this->first_name << endl;
		cout << "Last Name : " << this->last_name << endl;
		cout << "Email : " << this->email << endl;
		cout << "Password : " << this->password << endl;
		cout << "Age : " << this->age << endl;
	}
};
