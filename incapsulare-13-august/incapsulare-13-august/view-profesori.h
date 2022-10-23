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
		cout << "- 3 pentru a crea un curs" << endl;
		cout << "- 4 pentru a inchide un curs" << endl;
		cout << "- 5 pentru a adauga un student la un curs" << endl;
		cout << "- 6 pentru a da afara un student de la un curs" << endl;
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
		int idCurs = controlcourse.findByName(numeCurs);
		Course curs = controlcourse.getCourse(idCurs);
		if (idCurs != -1) {
			if (curs.getProfesorID() == profesor.getID()) {
				int studenti[100];
				int n2;
				controlenrolment.studentiEnrolled(studenti, curs.getID(), n2);
				controlstudent.afisareStudentiVector(studenti, n2);
				if (n2 == 0) {
					cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
					cout << "Niciun student nu este inscris." << endl;
				}
			}
			else {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Acest curs nu este al dumneavoastra." << endl;
			}
			
		}
		else {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Acest curs nu exista." << endl;
		}
	}

	void adaugareCurs() {
		string numeCurs, departament;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti numele cursului :" << endl;
		cin >> numeCurs;
		cout << "Introduceti numele departamentului :" << endl;
		cin >> departament;
		int idProfesor = profesor.getID();
		int id = controlcourse.idUnic();
		Course x(id, numeCurs, departament, idProfesor);
		controlcourse.addCourse(x);
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Cursul a fost creat cu succes!" << endl;
	}

	void inchidereCurs() {
		string numeCurs;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti numele cursului pe care doriti sa il inchideti :" << endl;
		cin >> numeCurs;
		int i = controlcourse.findByName(numeCurs);
		if (i != -1) {
			Course curs = controlcourse.getCourse(i);
			int idCurs = curs.getID();
			if (curs.getProfesorID() == profesor.getID()) {
				controlcourse.removeCourse(i);
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Cursul a fost inchis cu succes!" << endl;
			}
			else {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Acest curs nu este al dumneavoastra." << endl;
			}
		}
		else {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Acest curs nu exista." << endl;
		}
	}

	void inscrieStudent() {
		string prenume, nume, numeCurs;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti prenumele studentului :" << endl;
		cin >> prenume;
		cout << "Introduceti numele studentului :" << endl;
		cin >> nume;
		cout << "Introduceti numele cursului :" << endl;
		cin >> numeCurs;
		int iStudent = controlstudent.findByName(nume, prenume);
		int iCurs = controlcourse.findByName(numeCurs);
		if (iStudent != -1 && iCurs != -1) {
			Student student = controlstudent.getStudent(iStudent);
			Course curs = controlcourse.getCourse(iCurs);
			if (curs.getProfesorID() == profesor.getID()) {
				int idStudent = student.getID();
				int idCurs = curs.getID();
				int idEnrolment = controlenrolment.idUnic();
				if (controlenrolment.esteInscris(idStudent, idCurs) == -1) {
					Enrolment x(idEnrolment, idCurs, idStudent);
					controlenrolment.addEnrolment(x);
					cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
					cout << "Ati inscris acest student cu succes la " << curs.getName() << "!" << endl;
				}
				else {
					cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
					cout << "Acest student este inscris deja!" << endl;
				}
			}
			else {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Acest curs nu este al dumneavoastra!" << endl;
			}
			
			
		}
		else {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Acest student sau curs nu exista!" << endl;
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
			case 3:
				adaugareCurs();
				break;
			case 4:
				inchidereCurs();
				break;
			case 5:
				inscrieStudent();
				break;
			case 6:
				controlcourse.afisareCursuri();
				break;
			default:
				break;
			}
		}
 	}
};