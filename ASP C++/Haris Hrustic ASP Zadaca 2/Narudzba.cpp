#pragma once
class Narudzba
{
private: 
	char naziv[30];
	float cijena;
	int kolicina;
public:
	void setNaziv();
	void setCijena();
	void setKolicina();
	char* getNaziv();
	float getCijena();
	int getKolicina();
	void napraviNarudzbu();
	Narudzba();
	~Narudzba();
};


// HRUSTIC HARIS BR INDEKSA 46
