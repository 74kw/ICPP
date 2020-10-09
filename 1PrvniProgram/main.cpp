#include <iostream>

struct Trojuhelnik {
	int a,b,c;
	};

bool lzeSestrojit(Trojuhelnik t) {
	if ((t.a + t.b) > t.c && (t.a + t.c) > t.b && (t.b + t.c) > t.a)
	{
		std::cout << "Lze sestrojit" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Nelze sestrojit" << std::endl;
		return false;
	}
}
bool lzeSestrojit(Trojuhelnik* t) {
	if ((t->a + t->b) > t->c && (t->a + t->c) > t->c && (t->b + t->c) > t->a)
	{
		std::cout << "Lze sestrojit" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Nelze sestrojit" << std::endl;
		return false;
	}
}


int main() {
	std::cout << "Zadej pocet trojuhelniku, ktere chces zadat" << std::endl;
	int pocetT;
	std::cin >> pocetT;

	Trojuhelnik** pole;
	pole = new Trojuhelnik*[pocetT];


	for (int i = 0; i < pocetT; i++)
	{
		pole[i] = new Trojuhelnik; 
		std::cout << "Zadej strany trojuhelnika a,b,c" << std::endl;
		std::cout << "a: ";
		std::cin >> pole[i]->a;

		std::cout << "b: ";
		std::cin >> pole[i]->b;

		std::cout << "c: ";
		std::cin >> pole[i]->c;
		lzeSestrojit(pole[i]);
	}
	for (int i = 0; i < pocetT; i++)
	{
		delete pole[i];
	}
	delete[] pole;
	////std::cout << "Zadej strany trojuhelnika a,b,c" << std::endl;
	////Trojuhelnik t;
	//Trojuhelnik* t = new Trojuhelnik;
	//std::cout << "a: ";
	//std::cin >> t->a;

	//std::cout << "b: ";
	//std::cin >> t->b;

	//std::cout << "c: ";
	//std::cin >> t->c;
	////Trojuhelnik* ukazatel = &t;
	//lzeSestrojit(*t);
	//lzeSestrojit(t);
	////lzeSestrojit(ukazatel);
	////delete t;

	return 0;
}