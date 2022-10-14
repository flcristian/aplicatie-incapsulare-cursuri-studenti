#include "controller-course.h"

struct ControlEnrolment {
private:
	Enrolment enrolments[100];
	int dim;

	void citire() {
		ifstream f("enrolments.txt");
		dim = 0;

		while (!f.eof()) {
			int id;
			int course_id;
			int student_id;

			f >> id;
			f >> course_id;
			f >> student_id;

			Enrolment x(id, course_id, student_id);
			enrolments[dim] = x;
			dim++;
		}
		f.close();
	}
	
public:

	ControlEnrolment() {
		this->citire();
	}

	Enrolment getEnrolment(int i) {
		return this->enrolments[i];
	}

	int getDim() {
		return this->dim;
	}

	void addEnrolment(int student_id, int course_id) {
		Enrolment x(this->dim, course_id, student_id);
		this->enrolments[dim] = x;
		this->dim++;
	}

	void removeEnrolment(int id){
		for (int i = id; i < this->dim - 1; i++) {
			this->enrolments[i] = this->enrolments[i + 1];
			this->enrolments[i].setID(this->enrolments[i].getID() - 1);
		}
		this->dim--;
	}
};