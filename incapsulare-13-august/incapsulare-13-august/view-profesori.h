#include "view-student.h"

struct ViewProfesori {
private:
	ControlCourse controlcourse;
	ControlStudent controlstudent;
	ControlEnrolment controlenrolment;
	Profesor profesor;
	
	void menu() {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "\nBine ai venit, " << profesor.getFirstName() << " " << profesor.getLastName() << ".\n" << endl;
		cout << "Introduceti :" << endl;
		cout << "- 1 pentru a afisa cursurile tale" << endl;
		cout << "- 2 pentru a vedea studentii inscrisi la un curs" << endl;
	}

	void logout(bool& running) {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "V-ati delogat cu succes!" << endl;
		running = false;
	}

	void afisareCursuriProfesor() {
		int cursuri[100];
		int n;
		controlcourse.cursuriProfesor(cursuri, profesor.getID(), n);
		controlcourse.afisareCursuriVector(cursuri, n);
		if (n == 0) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Nu aveti niciun curs!" << endl;
		}
	}

	void afisareStudentiCurs() {
		string numeCurs;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti numele cursului la care doriti sa vedeti participantii :" << endl;
		cin >> numeCurs;
		Course curs = controlcourse.findByName(numeCurs);
		int idCurs = curs.getID();
		if (idCurs != -1) {
			int cursuri[100];
			int n;
			controlcourse.cursuriProfesor(cursuri, profesor.getID(), n);
			if (n == 0) {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Nu aveti niciun curs!" << endl;
			}
			else {
				int c = 0;
				for (int i = 0; i < n && c == 0; i++) {
					if (idCurs == cursuri[i]) {
						int studenti[100];
						int n2;
						controlenrolment.studentiEnrolled(studenti, idCurs, n2);
						controlstudent.afisareStudentiVector(studenti, n2);
						if (n2 == 0) {
							cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
							cout << "Niciun student nu este inscris." << endl;
						}
						c++;
					}
				}
				if (c == 0) {
					cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
					cout << "Acest curs nu este al dumneavoastra." << endl;
				}
			}
		}
		else {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Acest curs nu exista." << endl;
		}
	}

public:

	ViewProfesori() {
	}

	ViewProfesori(Profesor profesor) {
		this->profesor = profesor;
	}

	void play() {
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
				afisareCursuriProfesor();
				break;
			case 2:
				afisareStudentiCurs();
				break;
			default:
				break;
			}
		}
 	}
};