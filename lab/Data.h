#pragma once
#include <iostream>
#include <ostream>
#include <istream>
using namespace std;
class Data

{
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
	void Koryguj();
	//mam dostep do tych zmiennych mimo tego ze nie podaje je w argumentach funkcji, 
public:
	Data(int d, int m, int r);
	friend ostream& operator<<(ostream& wy, const Data& d);
	friend istream& operator>>(istream& we, Data& d);
	void Ustaw(int d, int m, int r);
	void Wypisz() const;
	void Wpisz();
	int Porownaj(const Data& wzor) const; //& oracuje na obiekcie nie na kopii
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;

	
	
};

