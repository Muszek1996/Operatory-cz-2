#include "Zawodnik.h"

string Zawodnik::rangi[] = {"V","IV","III","II","I","K","M"};

ostream & Zawodnik::operator<<(ostream & wyjscie)
{
	if (this)
	{
		wyjscie << "DANE:" << dane << " Kategoria: " << rangi[kategoria] << endl;
	}
	return wyjscie;
}

Zawodnik::Zawodnik()
{
}

Zawodnik::Zawodnik(const Zawodnik & zrodlo)
{
	dane = zrodlo.dane;
	kategoria = zrodlo.kategoria;
}

Zawodnik::Zawodnik(string imienazwisko, unsigned int ranga)
{
	dane = imienazwisko;
	kategoria = ranga;
}


Zawodnik::~Zawodnik()
{
}

