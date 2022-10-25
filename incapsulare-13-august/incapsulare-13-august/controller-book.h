#include "controller-student.h"

struct ControlBook {
private:
	Book books[100];
	int dim;

	void citire() {
		ifstream f("books.txt");
		dim = 0;
		
		while (!f.eof()) {
			int id;
			int count;
			string author_first_name;
			string author_last_name;
			string book_name;

			f >> id;
			f >> count;
			f >> author_first_name;
			f >> author_last_name;
			f >> book_name;

			Book x(id, count, author_first_name, author_last_name, book_name);
			books[dim] = x;
			dim++;
		}
	}
	
public:

	ControlBook() {
		citire();
	}

	int idUnic() {
		if (dim == 0) {
			return 1;
		}
		else {
			return books[dim - 1].getID() + 1;
		}
	}

	Book getBook(int i) {
		return this->books[i];
	}

	int getDim() {
		return this->dim;
	}

	void afisareBooks() {
		for (int i = 0; i < dim; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			books[i].descriereBook();
		}
	}

	void afisareBooksVector(Book x[], int n) {
		for (int i = 0; i < n; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			x[i].descriereBook();
		}
	}
};