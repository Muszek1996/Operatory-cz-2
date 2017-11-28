#pragma once
#include "Header.h"
class Zawodnik
{
	static string rangi[7];
	string dane;
	unsigned int kategoria;
public:
	friend class Gra;
	ostream& operator<<(ostream& wyjscie);
	Zawodnik();
	Zawodnik(const Zawodnik& zrodlo);
	Zawodnik(string imienazwisko,unsigned int ranga);
	~Zawodnik();
};
