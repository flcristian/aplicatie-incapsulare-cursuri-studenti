#include "controller-professors.h"

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

	void afisareBooks() {
		for (int i = 0; i < dim; i++) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			books[i].descriereBook();
		}
	}
};