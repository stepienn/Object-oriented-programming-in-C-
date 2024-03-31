#include "Pracownik.h"


using namespace std;
Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok): m_nIDZatrudnienia{++id}, m_DataUrodzenia(dzien, miesiac, rok)
{
	m_Imie.Ustaw(im);
	m_Nazwisko.Ustaw(naz);
	m_pNastepny = nullptr;

}
int Pracownik::id = 1;

Pracownik::Pracownik(const Pracownik& wzor) : m_nIDZatrudnienia{ wzor.m_nIDZatrudnienia },
m_DataUrodzenia(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok())
{
	this->m_Imie.Ustaw(wzor.Imie());
	this->m_Nazwisko.Ustaw(wzor.Nazwisko());
	m_pNastepny = nullptr;
}
Pracownik::~Pracownik() {
	 m_pNastepny = NULL;
	 id--;
}
const char* Pracownik::Imie() const {
	return m_Imie.Zwroc();
}
Pracownik& Pracownik::operator=(const Pracownik& wzor) { 
	return *(new Pracownik(wzor));                                   
}

const char* Pracownik::Nazwisko() const {
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char* nowe_imie) {
	m_Imie.Ustaw(nowe_imie);
}


void Pracownik::Nazwisko(const char* nowe_nazwisko) {
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wpisz()
{
	m_Imie.Wpisz();
	m_Nazwisko.Wpisz();
	m_DataUrodzenia.Wpisz();
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << "    ";
	m_Nazwisko.Wypisz();
	cout << "    ";
	m_DataUrodzenia.Wypisz();
	
}

void Pracownik::WypiszDane() {
	cout << "Id" << m_nIDZatrudnienia << " " << "Nazwisko" << m_Nazwisko << " Imie:" << m_Imie << " Data urodzenia: " << m_DataUrodzenia << "";
}

int Pracownik::SprawdzImie(const char* por_imie) const{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const{
	int wynikNazwisko = this->SprawdzNazwisko(wzorzec.Nazwisko());
	if (wynikNazwisko != 0) {
		return wynikNazwisko;
	}
	int wynikImie = this->SprawdzImie(wzorzec.Imie());
	if (wynikImie != 0) {
		return wynikImie;
	}
	return this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
}

bool Pracownik::operator==(const Pracownik& wzor)const {
	if((this->Porownaj(wzor))==0)
		return true;
	else 
		return false;
}


ostream& operator<<(ostream& wy, const Pracownik& p) {
	wy << p.m_Imie << " " << p.m_Nazwisko << " " << p.m_DataUrodzenia;
	return wy;
}

istream& operator>>(istream& we, Pracownik& p) {
	we >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia;
	return we;
}
Pracownik* Pracownik::KopiaObiektu() const {
	return new Pracownik(*this);
}