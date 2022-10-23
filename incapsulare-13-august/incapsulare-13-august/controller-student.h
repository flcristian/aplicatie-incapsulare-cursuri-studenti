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
			return students[dim].getID() + 1;
		}
	}

	int findByName(string nume, string prenume) {
		for (int i = 0; i < dim; i++) {
			if (prenume == students[i].getFirstName() && nume == students[i].getLastName()) {
				return i;
			}
		}
	}

	void afisareStudentiVector(int studenti[], int n) {
		for (int i = 0; i < n; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			students[studenti[i] - 1].descriereStudent();
		}
	}

	Student isStudent(string email, string parola) {
		for (int i = 0; i < dim; i++) {
			if (students[i].getEmail() == email && students[i].getPassword() == parola) {
				return students[i];
			}
		}
		return Student();
	}

	/*void updateStudents() {
		ofstream f("students.txt");
		for (int i = 0; i < dim; i++) {
			Student x = students[i];
			f << x.getID() << " " << x.getFirstName() << " " << x.getLastName() << " " << x.getEmail() << " " << x.getPassword() << " " << x.getAge() << endl;
		}
		f.close();
	}*/

	void addStudent(Student student) {
		students[dim] = student;
		dim++;
	}

	void removeStudent(int id) {
		for (int i = id; i < dim - 1; i++) {
			students[i] = students[i + 1];
		}
		dim--;
	}

};