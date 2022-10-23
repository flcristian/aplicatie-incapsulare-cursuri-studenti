#include "enrolment.h"

struct Book {
private:
	int id = -1;
	int count = -1;
	string author_first_name = "";
	string author_last_name = "";
	string book_name = "";
	
public:

	Book() {
	}

	Book(int id, int count, string author_first_name, string author_last_name, string book_name) {
		this->id = id;
		this->count = count;
		this->author_first_name = author_first_name;
		this->author_last_name = author_last_name;
		this->book_name = book_name;
	}

	int getID() {
		return this->id;
	}

	int getCount() {
		return this->count;
	}

	string getAuthorFirstName() {
		return this->author_first_name;
	}

	string getAuthorLastName() {
		return this->author_last_name;
	}

	string getBookName() {
		return this->book_name;
	}

	void setID(int id) {
		this->id = id;
	}

	void setCount(int id) {
		this->count = count;
	}

	void setAuthorFirstName(string author_first_name) {
		this->author_first_name = author_first_name;
	}

	void setAuthorLastName(string author_last_name) {
		this->author_last_name = author_last_name;
	}

	void setBookName(string book_name) {
		this->book_name = book_name;
	}

	void descriereBook() {
		cout << "ID : " << this->id << endl;
		cout << "Numar Total De Carti : " << this->count << endl;
		cout << "Prenume Autor : " << this->author_first_name << endl;
		cout << "Nume Autor : " << this->author_last_name << endl;
		cout << "Book Name : ";
		for (int i = 0; book_name[i] > 40 && book_name[i] < 250; i++) {
			cout << this->book_name[i];
			if (this->book_name[i + 1] < 90) {
				cout << " ";
			}
		}
		cout << endl;
	}
};
