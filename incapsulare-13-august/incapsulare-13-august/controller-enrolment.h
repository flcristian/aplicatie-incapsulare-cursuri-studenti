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
			return (enrolments[dim].getID() + 1);
		}
	}

	int esteInscris(int student_id, int course_id) {
		for (int i = 0; i < dim; i++) {
			if (student_id == enrolments[i].getStudentID() && course_id == enrolments[i].getCourseID()) {
				return i;
			}
		}
		return -1;
	}

	void addEnrolment(Enrolment x) {
		enrolments[dim] = x;
		dim++;
	}

	void removeEnrolment(int id) {
		for (int i = id; i < dim; i++) {
			enrolments[i] = enrolments[i + 1];
		}
		dim--;
	}

	void removeCurs(int idCurs) {
		for (int i = 0; i < dim; i++) {
			if (enrolments[i].getCourseID() == idCurs) {
				removeEnrolment(i);
				i--;
			}
		}
	}

	// SE FOLOSESTE DE ID-UL SETAT AL CURSULUI, INCEPAND DE LA 1
	void studentiEnrolled(int studenti[], int idCurs, int& n) {
		n = 0;
		for (int i = 0; i < dim; i++) {
			if (enrolments[i].getCourseID() == idCurs) {
				studenti[n] = enrolments[i].getStudentID();
				n++;
			}
		}
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

	/*void updateEnrolments() {
		ofstream f("enrolments.txt");
		for (int i = 0; i < dim; i++) {
			f << enrolments[i].getID() << " " << enrolments[i].getCourseID() << " " << enrolments[i].getStudentID() << endl;
		}
		f.close();
	}*/
};