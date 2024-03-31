#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Napis
{
private:
	//char m_pszNapis[40];
	char* m_pszNapis;
	int m_nD1;

public:
	Napis(const char* nap = "");
	~Napis();
	Napis(const Napis& wzor);
	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;

	Napis& operator=(const Napis& wzor);
	bool operator==(const Napis& wzor) const;
	friend ostream& operator<<(ostream& wy, const Napis& n);
	friend istream& operator>>(istream& we, Napis& n);

};

