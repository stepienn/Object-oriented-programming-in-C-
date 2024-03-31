#pragma once
#include "Data.h"
#include "Napis.h"
#include <iostream>


class Pracownik
{
private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	static int id;
public:
	Pracownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik& wzor);


	const char* Imie() const;
	const char* Nazwisko() const;
	
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wpisz() ;
	void Wypisz() const;

	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;


	Pracownik* m_pNastepny;
	int Porownaj(const Pracownik& wzorzec) const;

	Pracownik& operator=(const Pracownik& wzor);
	bool operator==(const Pracownik& wzor) const;
	friend ostream& operator<<(ostream& wy, const Pracownik& p); 
	friend istream& operator>>(istream& we, Pracownik& );

	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu() const;
	virtual ~Pracownik(); //zastepuje moj normalny destruktor o to zeby uciac funkcje wirtualne
};

