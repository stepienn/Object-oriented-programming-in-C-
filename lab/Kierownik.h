#pragma once
#include "Napis.h"
#include "Pracownik.h"
#include <iostream>

using namespace std;
class Kierownik :public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;
public:
	Kierownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000,const char* m_NazwaDzialu = "", int m_nLiczbaPracownikow = 0);
	Kierownik(const Kierownik& wzor);
	Kierownik& operator=(const Kierownik& wzor);
	bool operator==(const Kierownik& wzor) const;
	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu() const;
	friend ostream& operator<<(ostream& wy, const Kierownik& s);
	friend istream& operator>>(istream& we, Kierownik& s);


 
};

