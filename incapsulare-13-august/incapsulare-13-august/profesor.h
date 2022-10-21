#include "student.h"

struct Profesor {
private:
	int id = -1;
	string first_name = "";
	string last_name = "";
	string email = "";
	string password = "";
	
public:

	Profesor() {
	}

	Profesor(int id, string first_name, string last_name, string email, string password) {
		this->id = id;
		this->first_name = first_name;
		this->last_name = last_name;
		this->email = email;
		this->password = password;
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

	void descriereProfesor() {
		cout << "ID : " << this->id << endl;
		cout << "First Name : " << this->first_name << endl;
		cout << "Last Name : " << this->last_name << endl;
		cout << "Email : " << this->email << endl;
		cout << "Password : " << this->password << endl;
	}

};
