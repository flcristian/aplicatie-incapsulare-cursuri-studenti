#include "course.h"

struct Rent {
private:
	int id = -1;
	int book_id = -1;
	int student_id = -1;

public:

	Rent() {
	}

	Rent(int id, int book_id, int student_id) {
		this->id = id;
		this->book_id = book_id;
		this->student_id = student_id;
	}

	int getID() {
		return this->id;
	}

	int getBookID() {
		return this->book_id;
	}

	int getStudentID() {
		return this->student_id;
	}

	void setID(int id) {
		this->id = id;
	}

	void setBookID(int book_id) {
		this->book_id = book_id;
	}

	void setStudentID(int student_id) {
		this->student_id = student_id;
	}

	void descriereRent() {
		cout << "ID : " << id << endl;
		cout << "Book ID : " << book_id << endl;
		cout << "Student ID : " << student_id << endl;
	}
};

