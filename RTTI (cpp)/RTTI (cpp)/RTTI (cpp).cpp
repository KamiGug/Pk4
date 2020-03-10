// RTTI (cpp).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//#include <typeinfo>

//dane do zadania 1
////////////////////////////////////////////////////////
class Grzegorz {
	virtual void f() {};
};
class Nina : public Grzegorz {
	virtual void f() {};
};
class Patryk : public Nina {};
class Kamil :public Grzegorz {};
class Dominik {
	virtual void f() {};
};
class Zuzanna :public Dominik {};
class Marek {
	virtual void f() {};
};

static  Grzegorz* A = new Grzegorz;
static Grzegorz* D = new Nina;
static Nina* E = new Patryk;
static Grzegorz* B = new Kamil;
static Dominik* F = new Dominik;
static Dominik* C = new Zuzanna;
static Marek* G = new Marek;


////////////////////////////////////////////////////////


//Zadanie 3
////////////////////////////////////////////////////////
	class Dzialanie
	{
	public:
		Dzialanie() {};
		~Dzialanie() {};
		virtual double oblicz(double a, double b) = 0;
	};

	class Suma : public Dzialanie
	{
	public:
		Suma() {};
		~Suma() {};

		double oblicz(double a, double b)
		{
			return a + b;
		}
	};

	class Roznica : public Dzialanie
	{
	public:
		Roznica() {};
		~Roznica() {};

		double oblicz(double a, double b)
		{
			return a - b;
		}
	};

	class Iloczyn : public Dzialanie
	{
	public:
		Iloczyn() {};
		~Iloczyn() {};

		double oblicz(double a, double b)
		{
			return a * b;
		}
	};

	class Iloraz : public Dzialanie
	{
	public:
		Iloraz() {};
		~Iloraz() {};

		double oblicz(double a, double b)
		{
			return a / b;
		}
	};

	class Potega : public Dzialanie
	{
	public:
		Potega() {};
		~Potega() {};

		double oblicz(double a, double b)
		{
			return pow(a,b);
		}
	};

	class Pierwiastek : public Dzialanie
	{
	public:
		Pierwiastek() {};
		~Pierwiastek() {};

		double oblicz(double a, double b)
		{
			return pow(a, 1/b);
		}
	};
////////////////////////////////////////////////////////


//Zadanie 4
////////////////////////////////////////////////////////
	class Pionki
	{
	public:
		Pionki() {};
		Pionki(std::string a) { type = a; }
		~Pionki() {};
		std::string GiveType() { return type; };
	protected:
		std::string type;
	};

	class Biale : public Pionki
	{
	public:
		Biale() {};
		Biale(std::string a) { type = a; }
		~Biale() {};

	private:
	};

	class Czarne : public Pionki
	{
	public:
		Czarne() {};
		Czarne(std::string a) { type = a; }
		~Czarne() {};

	private:
	};
////////////////////////////////////////////////////////
void zadanie1()
{


	std::cout << "Obiekt A:" << std::endl << "Bazowy Pointer: " << typeid(A).name() << " wskazuje na: " << typeid(*A).name() << std::endl
		<< "Obiekt B:" << std::endl << "Bazowy Pointer: " << typeid(B).name() << " wskazuje na: " << typeid(*B).name() << std::endl
		<< "Obiekt C:" << std::endl << "Bazowy Pointer: " << typeid(C).name() << " wskazuje na: " << typeid(*C).name() << std::endl
		<< "Obiekt D:" << std::endl << "Bazowy Pointer: " << typeid(D).name() << " wskazuje na: " << typeid(*D).name() << std::endl
		<< "Obiekt E:" << std::endl << "Bazowy Pointer: " << typeid(E).name() << " wskazuje na: " << typeid(*E).name() << std::endl
		<< "Obiekt F:" << std::endl << "Bazowy Pointer: " << typeid(F).name() << " wskazuje na: " << typeid(*F).name() << std::endl
		<< "Obiekt G:" << std::endl << "Bazowy Pointer: " << typeid(G).name() << " wskazuje na: " << typeid(*G).name() << std::endl;
}

void zadanie2()
{
	char Char_ = 'U';
	int Int_ = -45;
	double Double_ = 21.37;
	unsigned int U_Int= 5;
	bool bool_ = true;
	float float_ = 34.12;
	float sum = static_cast<float>(Char_) + static_cast<float>(Int_)
		+ static_cast<float>(Double_) + static_cast<float>(U_Int) +
		static_cast<float>(bool_) + static_cast<float>(float_);


	std::cout << "sum = " << sum;
}

void zadanie3()
{
	Dzialanie* tab[6];
	tab[0] = new Suma;
	tab[1] = new Roznica;
	tab[2] = new Iloczyn;
	tab[3] = new Iloraz;
	tab[4] = new Potega;
	tab[5] = new Pierwiastek;

	std::cout << tab[3]->oblicz(tab[2]->oblicz(tab[4]->oblicz(tab[1]->oblicz(2, 14), 2), tab[5]->oblicz(tab[1]->oblicz(30, 5), 2)), 6);
}

void zadanie4()
{
	Pionki* tab[32];
	bool Colour = 0;
	int a = 0;
	for (int i = 0; i < 16; i++)
	{
		if (Colour)
		{
			tab[a] = new Biale("pawn");
		}
		else
		{
			tab[a] = new Czarne("pawn");
		}
		a++;
		Colour = (Colour + 1) % 2;
	}
	for (int i = 0; i < 4; i++)
	{
		if (Colour)
		{
			tab[a] = new Biale("rook");
		}
		else
		{
			tab[a] = new Czarne("rook");
		}
		a++;
		Colour = (Colour + 1) % 2;
	}
	for (int i = 0; i < 4; i++)
	{
		if (Colour)
		{
			tab[a] = new Biale("knight");
		}
		else
		{
			tab[a] = new Czarne("knight");
		}
		a++;
		Colour = (Colour + 1) % 2;
	}
	for (int i = 0; i < 4; i++)
	{
		if (Colour)
		{
			tab[a] = new Biale("bishop");
		}
		else
		{
			tab[a] = new Czarne("bishop");
		}
		a++;
		Colour = (Colour + 1) % 2;
	}
	for (int i = 0; i < 2; i++)
	{
		if (Colour)
		{
			tab[a] = new Biale("queen");
		}
		else
		{
			tab[a] = new Czarne("queen");
		}
		a++;
		Colour = (Colour + 1) % 2;
	}
	for (int i = 0; i < 2; i++)
	{
		if (Colour)
		{
			tab[a] = new Biale("king");
		}
		else
		{
			tab[a] = new Czarne("king");
		}
		a++;
		Colour = (Colour + 1) % 2;
	}
/*
	for (int i = 0; i < 32; i++)
	{
		std::cout << typeid((tab[i])).name() << ", ";
	}*/


	for (int i = 0; i < 32; i++)
	{
		if (typeid(*(tab[i])).name() == "class Czarne")
		{
			std::cout << tab[i]->GiveType() << ", ";
		}
	}
}


int main()
{
	std::cout << "Zadanie 1:\n";
	zadanie1();

	std::cout << "\nZadanie 2:\n";
	zadanie2();

	std::cout << "\nZadanie 3:\n";
	zadanie3();

	std::cout << "\nZadanie 4:\n";
	zadanie4();

	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
