#include "enrolment.h"

struct ControlStudent {
private :
	Student students[100];
	int dim;

	void citire() {
		ifstream f("students.txt");
		dim = 0;

		while (!f.eof()) {
			int id;
			string first_name;
			string last_name;
			string email;
			string password;
			int age;
			
			f >> id;
			f >> first_name;
			f >> last_name;
			f >> email;
			f >> password;
			f >> age;

			Student x(id, first_name, last_name, email, password, age);
			students[dim] = x;
			dim++;
		}
		f.close();
	}

public :
	
	ControlStudent() {
		this->citire();
	}

	Student getStudent(int i) {
		return this->students[i];
	}

	int getDim() {
		return this->dim + 1;
	}

	int idUnic() {
		if (dim == 0) {

			return 1;
		}
		else {
			return dim;
		}
	}

};