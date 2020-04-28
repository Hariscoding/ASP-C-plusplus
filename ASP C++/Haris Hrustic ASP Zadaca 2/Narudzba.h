#include "Narudzba.h"
#include <iostream>

using namespace std;

// HRUSTIC HARIS BR INDEKSA 46

void Narudzba::setNaziv()
{
	cout << "Unesite naziv narudzbe ";
	cin.getline(this->naziv, 30); 
}

void Narudzba::setCijena()
{
	cout << "Unesite cijenu narudzbe ";
	cin >> this->cijena;
	cin.ignore();
}

void Narudzba::setKolicina()
{
	cout << "Unesite kolicinu narudzbe ";
	cin >> this->kolicina;
	cin.ignore();
}

// HRUSTIC HARIS BR INDEKSA 46

char* Narudzba::getNaziv()
{
	return this->naziv;
}

float Narudzba::getCijena()
{
	return this->cijena;
}

int Narudzba::getKolicina()
{
	return this->kolicina;
}

void Narudzba::napraviNarudzbu()
{
	this->setNaziv();
	this->setCijena();
	this->setKolicina();
}

Narudzba::Narudzba()
{
}

Narudzba::~Narudzba()
{
}

// HRUSTIC HARIS BR INDEKSA 46
