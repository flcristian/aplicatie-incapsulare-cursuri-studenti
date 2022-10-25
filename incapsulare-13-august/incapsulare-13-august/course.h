#include "book.h"

struct Course {
private:
	int id = -1;
	string name = "";
	string department = "";
	int idProfesor = -1;
	
public:

	Course() {
	}

	Course(int id, string name, string department, int idProfesor) {
		this->id = id;
		this->name = name;
		this->department = department;
		this->idProfesor = idProfesor;
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

	int getProfesorID() {
		return this->idProfesor;
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

	void setIdProfesor(int idProfesor) {
		this->idProfesor = idProfesor;
	}

	void descriereCourse() {
		cout << "ID : " << this->id << endl;
		cout << "Name : " << this->name << endl;
		cout << "Department : " << this->department << endl;
	}
};
