#include "Pracownik.h"
#include <iostream>
#include "Napis.h"
#include "Data.h"
#include "ListaPracownikow.h"

using namespace std;

int main() {

	ListaPracownikow lista;
	Pracownik pracownik1;
	pracownik1.Imie("Filip");
	pracownik1.Nazwisko("Stepien");
	pracownik1.DataUrodzenia(15, 11, 2002);
	int wybor;
	char imie[50] = "";
	char nazwisko[50] = "";
	while (1) {
		
		cout << "1. Zwroc imie\n";
		cout << "2. Zwroc nazwisko\n";
		cout << "3. Ustaw nowe imie\n";
		cout << "4. Ustaw nowe nazwisko\n";
		cout << "5. Ustaw nowe dane\n";
		cout << "6. Wypisz dane\n";
		cout << "7. Sprawdz imie\n";
		cout << "8. Sprawdz nazwisko\n";
		cout << "9 Dodaj pracownika do listy\n";
		cout << "10.Usun pracownika z listy\n";
		cout << "11. Wypisz liste pracownikow\n";
		cout << "12. Szukaj pracownika w liscie\n";
		cout << "13. Zapisz do pliku\n";
		cout << "14. Wczytaj z pliku\n\n";
		cin >> wybor;


		switch (wybor) {
		case 1:
			cout << "Imie pracownika: " << pracownik1.Imie() <<"\n";
			break;
		case 2:
			cout << "Nazwisko pracownika: " << pracownik1.Nazwisko() <<"\n";
			break;
		case 3:
			cout << "Ustaw nowe imie\n";
			cin >> imie;
			pracownik1.Imie(imie);
			break;
		case 4:
			cout << "Ustaw nowe nazwisko\n";
			cin >> nazwisko;
			pracownik1.Nazwisko(nazwisko);
			break;
		case 5:
			cout << "Ustaw nowe dane:\n";
			pracownik1.Wpisz();
			break;
		case 6:
			cout << "Wypisz dane:\n";
			pracownik1.Wypisz();
			break;
		case 7:
			cout << "Sprawdz imie:\n";
			cin >> imie;
			if (pracownik1.SprawdzImie(imie) == 0) {
				cout << "Imiona sa takie same\n";
			
			}
			else {
				cout << "Imiona nie sa takie same\n";
			}
			break;
		case 8:
			cout << "Sprawdz nazwisko\n" << endl;
			cin >> nazwisko;
			if (pracownik1.SprawdzNazwisko(nazwisko) == 0) {
				cout << "Nazwiska sa takie same\n";
			}
			else {
				cout << "Nazwiska nie sa takie same\n";
			}
			break;
		case 9: {
			Pracownik tworz;
			tworz.Wpisz();
			lista.Dodaj(tworz);
			break;
		}
		case 10: {
			Pracownik kasuj;
			kasuj.Wpisz();
			lista.Usun(kasuj);
			break;
		}
		case 11:
			lista.WypiszPracownikow();
			break;
		case 12: {
			cout << "podaj imie ktore chcesz wyszukac: \n";
			cin >> imie;
			cout << "podaj nazwisko ktore chcesz wyszukac: \n";
			cin >> nazwisko;
			cout << "Szukany pracownik: ";
			const Pracownik* temp = lista.Szukaj(nazwisko, imie);
			if (temp != nullptr) {
				temp->Wypisz();
			}
			else {
				cout << "Nie znaleziono" << endl;
			}
			break;
		}
		case 13:
			lista.ZapiszDoPliku("baza_danych.txt");
			break;
		case 14:
			lista.WczytajZPliku("baza_danych.txt");
			break;
		}

		
	}
	return 0;
}