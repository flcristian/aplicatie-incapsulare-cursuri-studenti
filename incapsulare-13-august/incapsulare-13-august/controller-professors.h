#include "controller-enrolment.h"

struct ControlProfesor {
private:
	Profesor profesori[100];
	int dim;

	void citire() {
		ifstream f("professors.txt");
		dim = 0;

		while (!f.eof()) {
			int id;
			string first_name;
			string last_name;
			string email;
			string password;

			f >> id;
			f >> first_name;
			f >> last_name;
			f >> email;
			f >> password;

			Profesor x(id, first_name, last_name, email, password);
			profesori[dim] = x;
			dim++;
		}
		f.close();
	}

public:

	ControlProfesor() {
		this->citire();
	}

	int getDim() {
		return this->dim;
	}

	Profesor getProfesor(int i) {
		return this->profesori[i];
	}

	int idUnic() {
		if (dim == 0) {

			return 1;
		}
		else {
			return profesori[dim - 1].getID() + 1;
		}
	}

	Profesor isProfesor(string email, string parola) {
		for (int i = 0; i < dim; i++) {
			if (profesori[i].getEmail() == email && profesori[i].getPassword() == parola) {
				return profesori[i];
			}
		}
		return Profesor();
	}

	void afisareProfesori() {
		for (int i = 0; i < dim; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			profesori[i].descriereProfesor();
		}
	}

};