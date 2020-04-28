#include <iostream>
#include <iomanip>
#include <fstream>
#include "Narudzba.h"

// HRUSTIC HARIS BR INDEKSA 46

using namespace std;

string uredi = "----------------------------------------------------------------------\n";
string info = "     Dobro dosli! - ZADACA 2 ASP - Haris Hrustic - br.Indeksa: 46     \n\n";

void meni() {
	cout << uredi << endl << info;

	// HRUSTIC HARIS BR INDEKSA 46

	cout << "Za pregled nezavrsenih narudzbi unesite: ";
	cout << setw(10);
	cout << " 1\n";
	cout << "Za pregled zavrsenih narudzbi unesite: ";
	cout << setw(12);
	cout << " 2\n";
	cout << "Za oznacavanje narudzbe da je zavrsena : ";
	cout << setw(10);
	cout << " 3\n";
	cout << "Za pregled izvjestaja zavrsenih narudzbi: ";
	cout << setw(9);									
	cout << " 4\n";
	cout << "Za izvrsavanje narudzbe pritisnite: ";
	cout << setw(15);
	cout << " 5\n";
	cout << "Za izlaz iz menija pritisnite: ";
	cout << setw(20);
	cout << " 6\n";

	cout << endl;
	cout << uredi;
	// HRUSTIC HARIS BR INDEKSA 46
}

void upisiUFajl(int brD,Narudzba got[]) {

	system("pause");
	system("cls");
	cout << "Upisujemo u fajl sve do sada zavrsene narudzbe! \n";
	system("pause");
	fstream fajl;
	fajl.open("narudzbe.txt", ios::app | ios::out);
	for (int i = 0; i < brD; i++ ) {
		fajl << (i + 1) << "#" << endl;
		fajl << got[i].getNaziv() << "     " << got[i].getCijena() << "     " << got[i].getKolicina() << "X " << endl;
	}
	fajl.close();
	cout << "Uspjesno upisano u fajl! Provjerite! ";
	system("pause");
	system("cls");
}

// HRUSTIC HARIS BR INDEKSA 46

int main() {

	Narudzba narudzba;
	Narudzba gotoveNarudzbe[100];
	Narudzba nedovrseneNarudzbe[100];
	int brojiDovrsene = 0;
	int brojiNedovrsene = 0;

	int izbor;
	do {
		meni();
		cout << "Unesite vas izbor: ";
		cin >> izbor;
		cin.ignore();
		switch (izbor) {
		case 1:
			system("pause");
			system("cls");
			cout << uredi << info;
			cout << "Ispis nedovrsenih narudzbi: \n\n\n";

			if (brojiNedovrsene == 0) {
				cout << "Trenutno nema narudzbi!!! \n";
			} else {
				cout << "Naziv \t\t Kolicina \t Cijena \n";
			for (int i = 0; i < brojiNedovrsene; i++) {
				cout << nedovrseneNarudzbe[i].getNaziv() << "\t\t   " << nedovrseneNarudzbe[i].getKolicina() << "\t\t" <<
					nedovrseneNarudzbe[i].getCijena() << "KM \t\t + redni broj: " << i << endl;
			}
			}
			cout << "\n\n";
			cout << info << uredi;
			system("pause");
			system("cls");
			break;
		case 2:
			system("pause");
			system("cls");
			cout << uredi << info;
			cout << "Ispis dovrsenih narudzbi: \n\n\n";

			if (brojiDovrsene == 0) {
				cout << "Trenutno nema narudzbi!!! \n";
			}
			else {
				cout << "Naziv \t\t Kolicina \t Cijena \n";
				int brojac = 0;
				for (int i = brojiDovrsene-1; i > -1; i--) { // brojiDovrsene = 1 i=0
					cout << gotoveNarudzbe[i].getNaziv() << "\t\t   " << gotoveNarudzbe[i].getKolicina() << "\t\t" <<
						gotoveNarudzbe[i].getCijena() << "KM \t\t + redni broj: " << brojac << endl;
					brojac++;
				}
			}

			cout << "\n\n";
			cout << info << uredi;
			system("pause");
			system("cls");
			break;
		case 3:
			system("pause");
			system("cls");
			cout << uredi << info;
			cout << "Oznacavanje neke narudzbe kao dovrsena!: \n\n\n";

			if (brojiNedovrsene == 0) {
				cout << "Trenutno nema narudzbi!!! \n";
			}
			else {
				cout << "Naziv \t\t Kolicina \t Cijena \n";
				for (int i = 0; i < brojiNedovrsene; i++) {
					cout << nedovrseneNarudzbe[i].getNaziv() << "\t\t   " << nedovrseneNarudzbe[i].getKolicina() << "\t\t" <<
						nedovrseneNarudzbe[i].getCijena() << "KM \t\t + redni broj: " << i << endl;
				}
				int izbor3;
				cout << "Izaberite koju narudzbu zelite postaviti kao zavrsenu: ";
				cin >> izbor3;
				cin.ignore();
				gotoveNarudzbe[brojiDovrsene] = nedovrseneNarudzbe[izbor3];
				brojiDovrsene++;
				nedovrseneNarudzbe[izbor3] = nedovrseneNarudzbe[brojiNedovrsene - 1];
				brojiNedovrsene--;
			}

			cout << "\n\n";
			cout << info << uredi;
			system("pause");
			system("cls");
			break;
		case 4:
			upisiUFajl(brojiDovrsene,gotoveNarudzbe);
			brojiDovrsene = 0;
			break;
		case 5: 
			system("cls");
			cout << "Unos narudzbe: " << endl;
			narudzba.setNaziv();
			narudzba.setKolicina();
			narudzba.setCijena();
			int izbor2;
			cout << "Da li je vasa narudzba gotova?\n Unesite 1 ako jeste \n Unesite 0 ako nije \n";
			cin >> izbor2;
			cin.ignore();
			if (izbor2 == 1) {
				gotoveNarudzbe[brojiDovrsene] = narudzba;
				brojiDovrsene++;
				cout << "\n Uspjeno smjesteno u dovrsene narudzbe! \n";
			}
			else if (izbor2 == 0) {
				nedovrseneNarudzbe[brojiNedovrsene] = narudzba;
				brojiNedovrsene++;
				cout << "\n Uspjeno smjesteno u nedovrsene narudzbe! \n";
			}
			else {
				cout << "Vas izbor nije validan, narudzba se automatski odbacuje.";
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Izlaz iz programa! Dovidjenja. \n";
			system("pause");
			system("cls");
			break;
		default:
			cout << "Nije unesen validan broj\n";
			system("pause");
			system("cls");
		}
	} while (izbor != 6);

	return 0;
	// HRUSTIC HARIS BR INDEKSA 46
}
// HRUSTIC HARIS BR INDEKSA 46
