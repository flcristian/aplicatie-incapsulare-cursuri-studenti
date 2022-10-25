#include "controller-course.h"

struct ControlRent {
private:
	Rent rents[100];
	int dim;

	void citire() {
		ifstream f("rents.txt");
		dim = 0;

		while (!f.eof()) {
			int id, book_id, student_id;

			f >> id;
			f >> book_id;
			f >> student_id;

			Rent x(id, book_id, student_id);
			rents[dim] = x;
			dim++;
		}
		f.close();
	}

public:
	
	ControlRent() {
		citire();
	}

	int idUnic() {
		if (dim == 0) {
			return 1;
		}
		else {
			return rents[dim - 1].getID() + 1;
		}
	}

	Rent getRent(int i) {
		return this->rents[i];
	}

	int getDim() {
		return this->dim;
	}

	bool stillInStock(int book_id, int total_count) {
		for (int i = 0; i < dim; i++) {
			if (rents[i].getBookID() == book_id) {
				total_count--;
			}
		}
		if (total_count != 0) {
			return true;
		}
		else {
			return false;
		}
	}
};