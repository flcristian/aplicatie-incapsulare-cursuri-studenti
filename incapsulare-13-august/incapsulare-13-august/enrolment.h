#include "course.h"

struct Enrolment {
private:
	int id = -1;
	int course_id = -1;
	int student_id = -1;

public:

	Enrolment() {
	}

	Enrolment(int id, int course_id, int student_id) {
		this->id = id;
		this->course_id = course_id;
		this->student_id = student_id;
	}

	int getID() {
		return this->id;
	}

	int getCourseID() {
		return this->course_id;
	}

	int getStudentID() {
		return this->student_id;
	}

	void setID(int id) {
		this->id = id;
	}

	void setCourseID(int course_id) {
		this->course_id = course_id;
	}

	void setStudentID(int student_id) {
		this->student_id = student_id;
	}

	void descriereEnrolment() {
		cout << "ID : " << this->id << endl;
		cout << "Course ID : " << this->course_id << endl;
		cout << "Student ID : " << this->student_id << endl;
	}
};