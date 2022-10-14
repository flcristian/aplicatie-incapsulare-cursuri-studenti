#include "controller-enrolment.h"

struct View {
private :
	ControlEnrolment controlenrolment;
	ControlCourse controlcourse;
	ControlStudent controlstudent;
	Student student;

	int login(bool& logged, Student& student) {
		string email, password;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti email-ul : ";
		cin >> email;
		cout << "Introduceti parola : ";
		cin >> password;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		for (int i = 0; i < controlstudent.getDim(); i++) {
			Student x = controlstudent.getStudent(i);
			if (x.getEmail() == email && x.getPassword() == password) {
				logged = true;
				student = x;
				cout << "Ati fost logat!" << endl;
				cout << "Salutare, " << x.getFirstName() << " " << x.getLastName() << "!" << endl;
				return 0;
			}
		}
		if (!logged) {
			cout << "Email-ul sau parola sunt gresite!" << endl;
			return 0;
		}
	}

	void logout(bool& logged) {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Ati fost delogat!" << endl;
		logged = false;
	}

	void afisareCoursesEnroled() {
		int c = 0;
		for (int i = 0; i < controlenrolment.getDim(); i++) {
			Enrolment enrolment = controlenrolment.getEnrolment(i);
			if (enrolment.getStudentID() == this->student.getID()) {
				int enroled = enrolment.getCourseID();
				Course course = controlcourse.getCourse(enroled - 1);
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				course.descriereCourse();
				c++;
			}
		}
		if (c == 0) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Nu sunteti inscris/a la niciun curs!" << endl;
		}
	}

	bool inscrisLaCurs(int course_id, int student_id) {
		for (int i = 0; i < controlenrolment.getDim(); i++) {
			Enrolment x = controlenrolment.getEnrolment(i);
			if (x.getCourseID() == course_id && x.getStudentID() == student_id) {
				return true;
			}
		}
		return false;
	}

	void adaugareCourseStudent(int& course_id) {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti ID-ul cursului la care doriti sa va inscrieti :" << endl;
		cin >> course_id;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		if (inscrisLaCurs(course_id, student.getID())) {
			cout << "Sunteti deja inscris la acest curs!" << endl;
		}
		else {
			controlenrolment.addEnrolment(student.getID(), course_id);
			cout << "Ati fost inscris la acest curs!" << endl;
		}
		
	}

	int stergereCourseStudent(int& course_id) {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti ID-ul cursului la care doriti sa renuntati :" << endl;
		cin >> course_id;
		int c = 0;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		for (int i = 0; i < controlenrolment.getDim(); i++) {
			Enrolment x = controlenrolment.getEnrolment(i);
			if (x.getCourseID() == course_id && x.getStudentID() == this->student.getID()) {
				controlenrolment.removeEnrolment(x.getID() - 1);
				c++;
				cout << "Ai renuntat la acest curs!" << endl;
				return 0;
			}
		}
		cout << "Nu esti inscris la acest curs!" << endl;
		return 0;
	}

	void menu() {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti :" << endl;
		cout << "- 1 pentru a va deloga" << endl;
		cout << "- 2 pentru a vedea toate cursurile disponibile" << endl;
		cout << "- 3 pentru a afisa cursurile la care sunteti inscris" << endl;
		cout << "- 4 pentru a va inscrie la un curs" << endl;
		cout << "- 5 pentru a renunta la un curs" << endl;
	}

	void play() {
		bool logged = false;
		bool running = true;
		int p;
		int course_id;

		while (running) {
			if (!logged) {
				login(logged, this->student);
			}
			else {
				menu();
				cin >> p;

				switch (p)
				{
				case 1:
					logout(logged);
					break;
				case 2:
					afisareCourse();
					break;
				case 3:
					afisareCoursesEnroled();
					break;
				case 4:
					adaugareCourseStudent(course_id);
					break;
				case 5:
					stergereCourseStudent(course_id);
					break;
				default:
					break;
				}
			}
		}
	}

public :

	View() {
		this->play();
	}

	void afisareCourse() {
		for (int i = 0; i < controlcourse.getDim(); i++) {
			Course course = controlcourse.getCourse(i);
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			course.descriereCourse();
		}
	}

	//void afisareEnrolment() {
	//	for (int i = 0; i < controlenrolment.getDim(); i++) {
	//		Enrolment enrolment = controlenrolment.getEnrolment(i);
	//		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	//		enrolment.descriereEnrolment();
	//	}
	//}

};
