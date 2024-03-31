#include "Kierownik.h"

Kierownik::Kierownik(const char* im, const char* naz, int dzien,
    int miesiac, int rok, const char* dzia, int liczbap)
    : Pracownik(im, naz, dzien, miesiac, rok), m_NazwaDzialu(dzia), m_nLiczbaPracownikow(liczbap) {}
Kierownik::Kierownik(const Kierownik& wzor) : Pracownik(wzor)
{
    m_NazwaDzialu = wzor.m_NazwaDzialu;
    m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
}
Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
    if (this == &wzor)
        return *this;
    Pracownik::operator=(wzor);
    m_NazwaDzialu = wzor.m_NazwaDzialu;
    m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
    return *this;
}
bool Kierownik::operator==(const Kierownik& wzor) const
{
    if (Pracownik::operator==(wzor) &&
        m_NazwaDzialu == wzor.m_NazwaDzialu &&
        m_nLiczbaPracownikow == wzor.m_nLiczbaPracownikow)
        return true;
    return false;
}
void Kierownik::WypiszDane()
{
    std::cout << "Kierownik ";
    Pracownik::WypiszDane();
    std::cout << "nazwa dzialu : " << m_NazwaDzialu << ' '
        << "liczba pracownikow: " << m_nLiczbaPracownikow;
}
Pracownik* Kierownik::KopiaObiektu() const
{
    return new Kierownik(*this);
}
ostream& operator<<(ostream& wy, const Kierownik& s)
{
    return wy << (const Pracownik&)s << ' '
        << s.m_NazwaDzialu << ' '
        << s.m_nLiczbaPracownikow;
}
istream& operator>>(istream& we, Kierownik& s)
{
    if (&we == &std::cin)
    {
        we >> (Pracownik&)s; //rzutowanie
        std::cout << "Podaj nazwe dzialu: ";
        we >> s.m_NazwaDzialu;
        std::cout << "Podaj liczbe pracownikow: ";
        we >> s.m_nLiczbaPracownikow;
    }
    else
    {
        we >> (Pracownik&)s;
        we >> s.m_NazwaDzialu;
        we >> s.m_nLiczbaPracownikow;
    }
    return we;
}

