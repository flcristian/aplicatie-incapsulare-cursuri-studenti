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
		return this->dim + 1;
	}

	void afisareCursuri() {
		for (int i = 0; i < this->dim; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			this->courses[i].descriereCourse();
		}
	}

	void afisareCursuriVector(int cursuri[], int n) {
		for (int i = 0; i < n; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			this->courses[cursuri[i] - 1].descriereCourse();
		}
	}

	int idUnic() {
		if (dim == 0) {

			return 1;
		}
		else {
			return dim;
		}
	}

	Course findByName(string numeCurs) {
		for (int i = 0; i < dim; i++) {
			if (courses[i].getName() == numeCurs) {
				return courses[i];
			}
		}
		return Course();
	}

	void sortareFrecventa(int frecventa[], int n) {
		bool flag = true;
		do {
			flag = true;
			for (int i = 0; i < n - 1; i++) {
				if (frecventa[i] < frecventa[i + 1]) {
					int r = frecventa[i];
					Course curs = courses[i];
					courses[i] = courses[i + 1];
					courses[i + 1] = curs;
					frecventa[i] = frecventa[i + 1];
					frecventa[i + 1] = r;
					flag = false;
				}
			}
		} while (flag == false);
	}

	void afisareCuFrecventa(int frecventa[], int n) {
		for (int i = 0; i < n; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			courses[i].descriereCourse();
			cout << "Numarul de participanti : " << frecventa[i] << endl;
		}
	}
};