#include <iostream>

using namespace std;

class Stilou {
public:
	string culoareStilou;
	int lungime;
	char* producator;
	static int numarStilouri;
	const int id;

	Stilou() : id(10) {
		this->culoareStilou = "Roz";
		this->lungime = 15;
		this->producator = NULL;
	}

	Stilou(string culoareStilou, int lungime, const char* producator, int id) :id(id) {
		this->culoareStilou = culoareStilou;
		this->lungime = lungime;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	Stilou(string culoareStilou, const char* producator, int id) :id(id) {
		this->culoareStilou = culoareStilou;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	~Stilou() {
		if (this->producator) {
			delete[]this->producator;
		}
	}

	void afisareStilou() {
		cout << "Id:" << Stilou::id << endl;
		cout << "Culoare: " << this->culoareStilou << endl;
		if (this->lungime) {
			cout << "Lungime:" << this->lungime << endl;
		}
		if (this->producator != NULL) {
			cout << "Producator: " << this->producator << endl;
		}
		cout << endl;
	}

	static void modificaNrStilouri(int numarStilouri) {
		if (numarStilouri > 0) {
			Stilou::numarStilouri = numarStilouri;
		}
	}
};
int Stilou::numarStilouri = 3;

class Highlighter {
public:
	string culoareH;
	int greutate;
	char* brand;
	const int cod;
	static int numarHighlightere;

	Highlighter() :cod(102) {
		this->culoareH = "Roz pastel";
		this->greutate = 12;
		this->brand = NULL;
	}

	Highlighter(string culoareH, int greutate, const char* brand, int cod) :cod(cod) {
		this->culoareH = culoareH;
		this->greutate = greutate;
		this->brand = new char[strlen(brand) + 1];
		strcpy_s(this->brand, strlen(brand) + 1, brand);
	}

	Highlighter(string culoareH, const char* brand, int cod) :cod(cod) {
		this->culoareH = culoareH;
		this->brand = new char[strlen(brand) + 1];
		strcpy_s(this->brand, strlen(brand) + 1, brand);
	}

	~Highlighter() {
		if (this->brand) {
			delete[]this->brand;
		}
	}

	void afisareHighlighter() {
		cout << "Cod:" << Highlighter::cod << endl;
		cout << "Culoare: " << this->culoareH << endl;
		if (this->greutate) {
			cout << "Greutate:" << this->greutate << endl;
		}
		if (this->brand != NULL) {
			cout << "Brand: " << this->brand << endl;
		}
		cout << endl;
	}

	static int calculNrHighlightere() {
		 return numarHighlightere;
	}
};
int Highlighter::numarHighlightere = 4;

class Caiet {
public:
	int nrPagini;
	float pret;
	char* tipCaiet;
	const int codC;
	static int TVA;

	Caiet() :codC(1004) {
		this->nrPagini = 100;
		this->pret = 8.99;
		this->tipCaiet = NULL;
	}

	Caiet(int nrPagini, float pret, const char* tipCaiet, int codC): codC(codC) {
		this->nrPagini = nrPagini;
		this->pret = pret;
		this->tipCaiet = new char[strlen(tipCaiet) + 1];
		strcpy_s(this->tipCaiet, strlen(tipCaiet) + 1, tipCaiet);
	}

	Caiet(int nrPagini, float pret, int codC) :codC(codC) {
		this->nrPagini = nrPagini;
		this->pret = pret;
	}

	~Caiet() {
		if (this->tipCaiet) {
			delete[]this->tipCaiet;
		}
	}

	void afisareCaiet() {
		cout << "Cod caiet: " << Caiet::codC << endl;
		cout << "Numar pagini:" << this->nrPagini << endl;
		cout << "Pret: " << this->pret << endl;
		if (this->tipCaiet != NULL) {
			cout << "Tip caiet: " << this->tipCaiet << endl;
		}
		cout << endl;
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Caiet::TVA = noulTVA;
		}
	}
};
int Caiet::TVA = 19;


int main() {
	//stilouri
	Stilou stilou1;
	Stilou stilou2("Albastru", 14, "Schneider", 2);
	Stilou stilou3("Roz", "Stabilo", 23);
	stilou1.afisareStilou();
	stilou2.afisareStilou();
	stilou3.afisareStilou();

	//highlightere
	Highlighter h1;
	Highlighter h2("Gri", "Daco", 10);
	Highlighter h3("Portocaliu", 14, "Stabilo", 234);
	h1.afisareHighlighter();
	h2.afisareHighlighter();
	h3.afisareHighlighter();

	//caiete
	Caiet caiet1;
	Caiet caiet2(100, 24, 30);
	Caiet caiet3(120, 7, "A4", 103);
	caiet1.afisareCaiet();
	caiet2.afisareCaiet();
	caiet3.afisareCaiet();

	return 0;
}