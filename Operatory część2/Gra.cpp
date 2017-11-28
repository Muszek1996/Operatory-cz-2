#include "Gra.h"

unsigned int Gra::licznik;



Gra &Gra::operator+=(Zawodnik & nowyZawodnik)
{
	zawodnicy[ilo��_zawodnik�w++] = &nowyZawodnik;
	stan=(ilo��_zawodnik�w == LIMIT ? 1 : 0);
	return *this;
}

Gra &Gra::operator-=(Zawodnik & delZawodnik)
{
	for (int i = 0; i<ilo��_zawodnik�w; i++)
	{	
		if(zawodnicy[i]==&delZawodnik)
		{
			if (i == 0)
			{
				zawodnicy[0] = zawodnicy[1];
			}
			--ilo��_zawodnik�w;
		}

	};
	stan = (ilo��_zawodnik�w == LIMIT ? 1 : 0);
	return *this;
}

bool Gra::operator==(const Gra & pZawodnik)
{
	
	if (id != pZawodnik.id)return false;
	if (LIMIT != pZawodnik.LIMIT)return false;
	if (stan != pZawodnik.stan)return false;
	if (ilo��_zawodnik�w != pZawodnik.ilo��_zawodnik�w)return false;
	for(int i=0;i<ilo��_zawodnik�w;i++)
	{
		if (zawodnicy[i]->dane != pZawodnik.zawodnicy[i]->dane) return false;
		if (zawodnicy[i]->kategoria != pZawodnik.zawodnicy[i]->kategoria) return false;
	}
	return true;

}

bool Gra::operator!=(const Gra & pZawodnik)
{
	return !(*this==pZawodnik);
}

Gra Gra::operator++()
{
	Gra backup(*this);
	for (int i = 0; i < ilo��_zawodnik�w; i++)
	{
		if (zawodnicy[i]->kategoria < 6)zawodnicy[i]->kategoria++;
	}
	return backup;
}

Gra Gra::operator++(int)
{
	for (int i = 0; i < ilo��_zawodnik�w; i++)
	{
		if (zawodnicy[i]->kategoria < 6)zawodnicy[i]->kategoria++;
	}
	return *this;
}




ostream & Gra::operator<<(ostream& wyjscie)
{
	wyjscie << endl << "+++++++DANE GRY++++++++" << endl;
	wyjscie << "ID: " << id << endl;
	wyjscie << "Stan: " << stan << endl;
	wyjscie << "Ilo�� Zawodnik�w:" << ilo��_zawodnik�w <<"/"<< LIMIT << endl;
	for(int i=0;i<ilo��_zawodnik�w;i++)
	{
		*zawodnicy[i] << cout;
	}
	wyjscie << "++++++KONIEC DANE GRY++++++++" << endl;
	return wyjscie;
}

Gra::Gra():
id(licznik++)
{
	cout << "Domyslny konstruktor GRA ID:" << id << endl;
	zawodnicy = new Zawodnik*[LIMIT];
	stan = false;
	ilo��_zawodnik�w = 0;
}

Gra::Gra(const Gra & zrodlo) :
	id(zrodlo.id)
{
	cout << "Konstruktor kopiuj�cy (BACKUP)" << endl;
	zawodnicy = new Zawodnik*[LIMIT];
	for(int i=0;i<zrodlo.ilo��_zawodnik�w;i++)
	{
		zawodnicy[i] = new Zawodnik(*zrodlo.zawodnicy[i]);
	}
	stan = zrodlo.stan;
	ilo��_zawodnik�w = zrodlo.ilo��_zawodnik�w;
}


Gra::~Gra()
{
	cout << "destruktor GRA ID:" << id<< endl;
}
