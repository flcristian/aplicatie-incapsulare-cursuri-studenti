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
		cout << "- 7 pentru a inregistra un student" << endl;
		cout << "- 8 pentru a sterge un student" << endl;
		cout << "- 9 pentru a va deloga" << endl;
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
		/*controlcourse.updateCourse();*/
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
				controlenrolment.removeCurs(idCurs);
				/*controlenrolment.updateEnrolments();*/
				controlcourse.removeCourse(i);
				/*controlcourse.updateCourse();*/
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

	void inscrieStudentCurs() {
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
					controlenrolment.updateEnrolments();
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

	void removeStudentCurs() {
		string prenume, nume;
		string numeCurs;
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
			int iEnrolment = controlenrolment.esteInscris(student.getID(), curs.getID());
			if (iEnrolment != -1) {
				controlenrolment.removeEnrolment(iEnrolment);
				controlenrolment.updateEnrolments();
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "L-ati scos pe " << student.getFirstName() << " " << student.getLastName() << " de la " << curs.getName() << "." << endl;
			}
			else {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << student.getFirstName() << " " << student.getLastName() << " nu este inscris la " << curs.getName() << "." << endl;
			}
		}
		else {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Studentul sau cursul nu exista." << endl;
		}
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
		cout << "Ati inregistrat studentul cu succes!" << endl;
	}

	void unregister() {
		string prenume, nume;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti prenumele studentului :" << endl;
		cin >> prenume;
		cout << "Introduceti numele studentului :" << endl;
		cin >> nume;
		int i = controlstudent.findByName(nume, prenume);
		if (i != -1) {
			controlstudent.removeStudent(i);
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Ati sters cu succes studentul!" << endl;
		}
		else {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Studentul nu exista." << endl;
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
			case -1:
				running = false;
				break;
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
				inscrieStudentCurs();
				break;
			case 6:
				removeStudentCurs();
				break;
			case 7:
				inregistrare();
				break;
			case 8:
				unregister();
				break;
			case 9:
				logout(running);
				break;
			default:
				break;
			}
		}
 	}
};