#include "view-profesori.h"

struct ViewLogin {
private:
	ControlProfesor controlprofesor;
	ControlStudent controlstudent;

	void menu() {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti :" << endl;
		cout << "- 1 pentru a va loga" << endl;
		cout << "- 2 pentru a va inregistra" << endl;
		cout << "- 3 pentru a iesi" << endl;
	}

	void login() {
		string email, parola;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti email-ul : ";
		cin >> email;
		cout << "Introduceti parola : ";
		cin >> parola;
		Student student = controlstudent.isStudent(email, parola);
		if (student.getID() != -1) {
			View view(student);
			view.play();
		}
		else {
			Profesor profesor = controlprofesor.isProfesor(email, parola);
			if (profesor.getID() != -1) {
				ViewProfesori view(profesor);
				view.play();
			}
			else {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Email-ul sau parola sunt gresite." << endl;
			}
		}
	}

	void setGabi() {
		Profesor test = controlprofesor.isProfesor("gabiprof@a.c", "Parola13");
		ViewProfesori view(test);
		view.play();
	}

	void setGabiStudent() {
		Student test = controlstudent.isStudent("geogabi@gmail.com", "Parola12");
		View view(test);
		view.play();
	}

	void inregistrare() {
		string prenume, nume, email, parola;
		int varsta;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti prenumele : ";
		cin >> prenume;
		cout << "Introduceti numele de familie : ";
		cin >> nume;
		cout << "Introduceti varsta : ";
		cin >> varsta;
		cout << "Introduceti email-ul : ";
		cin >> email;
		cout << "Introduceti parola : ";
		cin >> parola;
		int id = controlstudent.idUnic();

		Student student(id, prenume, nume, email, parola, varsta);
		controlstudent.addStudent(student);
		/*controlstudent.updateStudents();*/
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "V-ati inregistrat cu succes!" << endl;
	}

public:

	ViewLogin() { 
	}

	void play() {
		Student student;
		bool running = true;
		int p;

		while (running) {
			menu();
			string al;
			cin >> al;
			p = stoi(al);

			switch (p)
			{
			case 1:
				login();
				break;
			case 2:
				inregistrare();
				break;
			case 3:
				running = false;
				break;
			case 4:
				setGabi();
				break;
			case 5:
				setGabiStudent();
				break;
			default:
				break;
			}
		}
	}
};
