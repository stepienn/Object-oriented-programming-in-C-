#include "Napis.h"

using namespace std;

Napis::Napis(const char* nap){
	m_pszNapis = nullptr;
	this->m_nD1 = 0;
	this->Ustaw(nap); 
}

Napis::~Napis(){
	delete m_pszNapis;
	m_nD1 = 0;
}

Napis::Napis(const Napis& wzor) :m_nD1{wzor.m_nD1}{
	this->Ustaw(wzor.m_pszNapis);
}

const char* Napis::Zwroc() const {
	return m_pszNapis;
}

void Napis::Ustaw(const char* nowy_napis){
	//strcpy_s(m_pszNapis, nowy_napis);
	this->~Napis();
	m_nD1 = strlen(nowy_napis) + 1;
	m_pszNapis = new char[m_nD1];
	strcpy(this->m_pszNapis, nowy_napis);
}
void Napis::Wpisz() {
	char wielkosc[100];
	cin >> wielkosc;
	this->Ustaw(wielkosc);
	//cout << "Podaj napis:" << endl;
	
}
void Napis::Wypisz() const {
	//cout << "Wypisz napis: \n";
	cout << m_pszNapis;
}

int Napis::SprawdzNapis(const char* por_napis) const {

	return strcmp(this->m_pszNapis, por_napis);
}

Napis& Napis::operator=(const Napis& wzor) {
	this->~Napis();										
	new (this)Napis(wzor);
	return *this;
}

bool Napis::operator==(const Napis& wzor)const {
	if (this->SprawdzNapis(wzor.Zwroc()) == 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& wy, const Napis& n) {
	return wy << n.m_pszNapis;
}

istream& operator>>(istream& we, Napis& n) {
	char wielkosc[100];
	we >> wielkosc;
	n.Ustaw(wielkosc);
	return we;
}