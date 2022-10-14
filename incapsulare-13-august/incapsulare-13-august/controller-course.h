#include "controller-student.h"

struct ControlCourse {
private:
	Course courses[100];
	int dim;

	void citire() {
		ifstream f("courses.txt");
		dim = 0;

		while (!f.eof()) {
			int id;
			string name;
			string department;

			f >> id;
			f >> name;
			f >> department;

			Course x(id, name, department);
			courses[dim] = x;
			dim++;
		}
		f.close();
	}

public:

	ControlCourse() {
		this->citire();
	}

	Course getCourse(int i) {
		return this->courses[i];
	}
	
	int getDim() {
		return this->dim;
	}
};