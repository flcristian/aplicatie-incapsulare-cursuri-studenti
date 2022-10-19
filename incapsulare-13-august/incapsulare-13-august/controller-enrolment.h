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

	int idUnic() {
		if (dim == 0) {

			return 1;
		}
		else {
			return dim + 1;
		}
	}

	bool existaDeja(int student_id, int course_id) {
		for (int i = 0; i < dim; i++) {
			if (student_id == enrolments[i].getStudentID() && course_id == enrolments[i].getCourseID()) {
				return true;
			}
		}
		return false;
	}

	void addEnrolment(Enrolment x) {
		enrolments[dim] = x;
		dim++;
	}

	void frecventaCursuri(int frecventa[], int n) {
		for (int i = 0; i < dim; i++) {
			frecventa[enrolments[i].getCourseID() - 1]++;
		}

	}

	void cursuriEnrolled(int cursuri[], int& n, int student_id) {
		n = 0;
		for (int i = 0; i < dim; i++) {
			if (enrolments[i].getStudentID() == student_id) {
				cursuri[n] = enrolments[i].getCourseID();
				n++;
			}
		}
	}
};