#include "ListaPracownikow.h"

ListaPracownikow::ListaPracownikow()
{
	this->m_pPoczatek = nullptr;
	this->m_nLiczbaPracownikow = 0;
}

ListaPracownikow::~ListaPracownikow()
{

	Pracownik* prac = this->m_pPoczatek;
	while (prac != nullptr) {
		Pracownik* nextPracownik = prac->m_pNastepny;
		delete prac;
		prac = nextPracownik;
	}
	this->m_pPoczatek = nullptr;
	this->m_nLiczbaPracownikow = 0;
}

void ListaPracownikow::Dodaj(const Pracownik& p)
{
	Pracownik* temp;
	Pracownik* temp_2 = new Pracownik(p);
	if (this->m_nLiczbaPracownikow == 0) {
		this->m_pPoczatek = new Pracownik(p);
		this->m_pPoczatek->m_pNastepny = nullptr;
		this->m_nLiczbaPracownikow++;
	}
	else {
		temp = m_pPoczatek;
		if (this->m_pPoczatek->Porownaj(p) > 0) {
			m_pPoczatek = temp_2;
			temp_2->m_pNastepny = temp;
			m_nLiczbaPracownikow++;
		}
		else {
			
			while (temp) {
				if (temp->Porownaj(p) == 0) { 
					break;
				}
				//rozp rosnacego
				if (temp->m_pNastepny != nullptr) { 
					if (temp->Porownaj(p) < 0 && temp->m_pNastepny->Porownaj(p) > 0) {
						temp_2->m_pNastepny = temp->m_pNastepny;
						temp->m_pNastepny = temp_2;
						m_nLiczbaPracownikow++;
					}
				}

				if (temp->Porownaj(p) < 0 && temp->m_pNastepny == nullptr) {
					temp->m_pNastepny = temp_2;
					temp_2->m_pNastepny = nullptr;
					m_nLiczbaPracownikow++;
					
				}
				temp = temp->m_pNastepny;
			}
		}
	}
}

void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
	if (this->m_nLiczbaPracownikow > 0) {
		Pracownik* temp;
		if (m_pPoczatek->Porownaj(wzorzec) == 0) {
			m_pPoczatek = m_pPoczatek->m_pNastepny;
			m_nLiczbaPracownikow--;
		}
		else {
			temp = m_pPoczatek;
			for (int i = 1; i < m_nLiczbaPracownikow; i++) {
				if (temp->m_pNastepny->Porownaj(wzorzec) == 0) {
					temp->m_pNastepny = temp->m_pNastepny->m_pNastepny;
					break;
				}
				temp = temp->m_pNastepny;
			}

		}
		std::cout << "usunieto pracownika \n";
	}
	else
		std::cout << "brak pracownikow do usuniecia\n";
}

void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik* temp = m_pPoczatek;
	std::cout << "lista pracownikow:\n";
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		temp->Wypisz();
		temp = temp->m_pNastepny;
	}

}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
	if (this->m_nLiczbaPracownikow > 0) {
		Pracownik* temp = m_pPoczatek;
		for (int i = 0; i < m_nLiczbaPracownikow; i++) {
			if (temp->SprawdzImie(imie) == 0 && temp->SprawdzNazwisko(nazwisko) == 0) {
				return temp;
			}
		}
	}
	return nullptr;
}

void ListaPracownikow::ZapiszDoPliku(std::string nazwa) const
{
	ofstream Plik(nazwa, std::ios::trunc);

	Pracownik* aktualny = this->m_pPoczatek;

	while (aktualny != nullptr) {
		Plik << *(aktualny) << "\n";
		aktualny = aktualny->m_pNastepny;
	}

	Plik.close();
}

void ListaPracownikow::WczytajZPliku(std::string nazwa)
{
	ifstream Plik(nazwa, ifstream::in);
	Pracownik tymczasowy;

	while (Plik >> tymczasowy) {
		Dodaj(tymczasowy);
	}
	Plik.close();
}
