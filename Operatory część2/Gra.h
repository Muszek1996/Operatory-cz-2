#pragma once
#include "Zawodnik.h"
#include "Header.h"

class Gra
{
	const unsigned int id;
	static unsigned int licznik;
	Zawodnik ** zawodnicy;
	bool stan;
	unsigned int iloœæ_zawodników;
	const unsigned int LIMIT = 2;
public:
	friend class Zawodnik;
	Gra& operator +=(Zawodnik& nowyZawodnik);
	Gra& operator -=(Zawodnik& nowyZawodnik);
	bool operator ==(const Gra& pZawodnik);
	bool operator !=(const Gra& pZawodnik);
	Gra operator++();
	Gra operator++(int);
	ostream& operator<<(ostream& wyjscie);
	Gra();
	Gra(const Gra& zrodlo);
	~Gra();
};
