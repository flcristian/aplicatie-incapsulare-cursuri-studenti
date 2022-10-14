#include "student.h"

struct Course {
private:
	int id;
	string name;
	string department;

public:

	Course() {
	}

	Course(int id, string name, string department) {
		this->id = id;
		this->name = name;
		this->department = department;
	}

	int getID() {
		return this->id;
	}

	string getName() {
		return this->name;
	}

	string getDepartment() {
		return this->department;
	}

	void setID(int id) {
		this->id = id;
	}

	void setName(string name) {
		this->name = name;
	}

	void setDepartment(string department) {
		this->department = department;
	}

	void descriereCourse() {
		cout << "ID : " << this->id << endl;
		cout << "Name : " << this->name << endl;
		cout << "Department : " << this->department << endl;
	}
};
