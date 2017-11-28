#include "Header.h"
#include "Gra.h"



int main()
{
	setlocale(LC_ALL, "");
	
	Zawodnik jacek = Zawodnik("Jacek Karpl", 3);
	Zawodnik andrzej = Zawodnik("Andrzej Wajda", 6);
	jacek << cout;
	andrzej << cout;
	
	Gra * backup[10];
	Gra nowagra;
	nowagra += jacek;
	backup[0] = new Gra(nowagra);
	cout << (nowagra == *backup[0]?"==TRUE":"==FALSE")<< endl;
	nowagra += andrzej;
	backup[1] = new Gra(nowagra);
	nowagra -= jacek;
	backup[2] = new Gra(nowagra);
	nowagra += *new Zawodnik("Maciej Maleñczuk", 3);
	cout << (*backup[0] != *backup[2] ? "!=TRUE" : "!=FALSE") << endl;
	cout << "-----HISTORY:-----" << endl;
	for (int i = 0; i < 3; i++)
	*backup[i] << cout;
	cout << "----END HISTORY----" << endl;
	nowagra << cout;
	nowagra++;
	nowagra << cout;
	++nowagra;
	nowagra << cout;



	getchar();
	return 0;
}


