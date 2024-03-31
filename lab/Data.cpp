#include "Data.h"
#include <iostream>

using namespace std;


Data::Data(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
	void Koryguj();

}

void Data::Ustaw(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
	Koryguj();
}
void Data::Koryguj() {
	bool czyprzystepny;
	//sprawdzenie przystepnosci roku 
	if (m_nRok % 4 == 0) {
		if (m_nRok % 100 == 0) {
			if (m_nRok % 400 == 0) {
				czyprzystepny = true;
			}
			else {
				czyprzystepny = false;
			}
		}
		else {
			czyprzystepny = true; // jest przystepny
		}
	}
	else {
		czyprzystepny = false; // nie jest przystêny
	}

	int dniMiesiaca[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//jezeli miesiac jest nie przystepny
	//rozpoczecie poprawy daty
	if (m_nDzien < 1)
		m_nDzien = 1;
	if (m_nMiesiac == 0)
		m_nMiesiac = 1;

	if (m_nMiesiac > 12)
		m_nMiesiac = 12;

	//jezeli jest rokiem przystepny - ma 29 dni 
	//jezeli nie jest rokiem przystepnym - ma 28 dni
	if (!czyprzystepny) { //gdy jest nie przystepny
		if (m_nDzien > dniMiesiaca[m_nMiesiac - 1]) {
			if (m_nMiesiac == 2) {
				if (m_nDzien > 28)
					m_nDzien = 28;
			}
			else {
				m_nDzien = dniMiesiaca[m_nMiesiac - 1];
			}
		}
	}
	else //gdy jest przystepny
	{
		if (m_nDzien > dniMiesiaca[m_nMiesiac - 1]) {
			if (m_nMiesiac == 2) {
				if (m_nDzien > 29)
					m_nDzien = 29;
			}
			else {
				m_nDzien = dniMiesiaca[m_nMiesiac - 1];
			}
		}
	}


}
int Data::Porownaj(const Data& wzor) const 
{
	if(m_nDzien == wzor.Dzien() && m_nMiesiac == wzor.Miesiac() && m_nRok == wzor.Rok())
		return 0;// sa takie same

	if (m_nRok < wzor.Rok()) { //jezeli wzor STARSZY jest wiekszy wypisz 1 jezeli nie -1
		return 1;
	}
	if (m_nRok == wzor.Rok() && m_nMiesiac < wzor.Miesiac()) {
		return 1;
	}
	else
		return -1;
	if (m_nRok == wzor.Rok() && m_nMiesiac == wzor.Miesiac() && m_nRok == wzor.Rok() && m_nDzien < wzor.Dzien()) 
		return 1;
	else
		return -1; 

}
int Data::Dzien() const {
	return m_nDzien;
}
int Data::Miesiac() const {
	return m_nMiesiac;
}
int Data::Rok() const {
	return m_nRok;
}


void Data::Wypisz() const {
	cout << m_nDzien <<"-" << m_nMiesiac<< "-"<< m_nRok<< endl;
}

void Data::Wpisz() {
	cout << " Podaj dzien" << endl;;
	cin >> m_nDzien;
	cout << " Podaj miesiac"<<endl;
	cin >> m_nMiesiac;
	cout << " Podaj rok"<<endl;
	cin >> m_nRok;
	Koryguj();
}



ostream& operator<<(ostream& wy, const Data& d) {
	wy << d.m_nDzien << " " << d.m_nMiesiac << " " << d.m_nRok;
	return wy;
}
istream& operator>>(istream& we, Data& d){
	we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;
	d.Koryguj();
	return we;
}
