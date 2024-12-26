#include <iostream>

using namespace std;

class Stilou {
private:
	string culoareStilou;
	int lungime;
	char* producator;
	static int numarStilouri;
	const int id;

public:
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

	Stilou(const Stilou& s):id(++numarStilouri) {
		this->culoareStilou = s.culoareStilou;
		this->lungime = s.lungime;
		if (s.producator != NULL) {
			this->producator = new char[strlen(s.producator) + 1];
			strcpy_s(this->producator, strlen(s.producator) + 1, s.producator);
		}
		else {
			this->producator = NULL;
		}
	}

	string getCuloareStilou() {
		return this->culoareStilou;
	}

	void setCuloareStilou(string culoareStilou) {
		if (culoareStilou.length() > 2) {
			this->culoareStilou = culoareStilou;
		}
	}

	int getLungime() {
		return this->lungime;
	}

	void setLungime(int lungime) {
		if (lungime > 0) {
			this->lungime = lungime;
		}
	}

	static int getNumarStilouri() {
		return numarStilouri;
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

	friend void modifCuloare(Stilou s);
};
int Stilou::numarStilouri = 3;

class Highlighter {
private:
	string culoareH;
	int greutate;
	char* brand;
	const int cod;
	static int numarHighlightere;
	
public:
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

	Highlighter(const Highlighter& h) :cod(++numarHighlightere) {
		this->culoareH = h.culoareH;
		this->greutate = h.greutate;
		if (h.brand != NULL) {
			this->brand = new char[strlen(h.brand) + 1];
			strcpy_s(this->brand, strlen(h.brand) + 1, h.brand);
		}
		else {
			this->brand = NULL;
		}
	}

	string getCuloareH() {
		return this->culoareH;
	}

	void setCuloareH(string culoareH) {
		if (culoareH.length() > 2) {
			this->culoareH = culoareH;
		}
	}

	int getGreutate() {
		return this->greutate;
	}

	void setGreutate(int greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	static int getNumarHighlightere() {
		return numarHighlightere;
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
private:
	int nrPagini;
	float pret;
	char* tipCaiet;
	const int codC;
	static int TVA;

public:
	Caiet() :codC(1004) {
		this->nrPagini = 100;
		this->pret = 8.99;
		this->tipCaiet = NULL;
	}

	Caiet(int nrPagini, float pret, const char* tipCaiet, int codC) : codC(codC) {
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

	Caiet(const Caiet& c) : codC(c.codC) {
		this->nrPagini = c.nrPagini;
		this->pret = c.pret;
		if (c.tipCaiet != NULL) {
			this->tipCaiet = new char[strlen(c.tipCaiet) + 1];
			strcpy_s(this->tipCaiet, strlen(c.tipCaiet) + 1, c.tipCaiet);
		}
		else {
			this->tipCaiet = NULL;
		}
	}

	int getNrPagini() {
		return this->nrPagini;
	}

	void setNrPagini(int nrPagini) {
		if (nrPagini > 0) {
			this->nrPagini = nrPagini;
		}
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}

	static int getTVA() {
		return TVA;
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
	friend void modificaNrPagini(Caiet c);
};
int Caiet::TVA = 19;

void modificaNrPagini(Caiet c) {
	c.nrPagini += 10;
	cout << c.nrPagini << endl;
	c.pret += c.pret * Caiet::TVA / 100;
	cout << c.pret << endl;
}

void modifCuloare(Stilou s) {
	s.culoareStilou = "Verde";
	cout << s.culoareStilou << endl;
}

int main() {

	//----------task2----------
	//stilouri
	Stilou stilou1;
	Stilou stilou2("Albastru", 14, "Schneider", 2);
	Stilou stilou3("Roz", "Stabilo", 23);
	//stilou1.afisareStilou();
	stilou2.afisareStilou();
	//stilou3.afisareStilou();

	//highlightere
	Highlighter h1;
	Highlighter h2("Gri", "Daco", 10);
	Highlighter h3("Portocaliu", 14, "Stabilo", 234);
	//h1.afisareHighlighter();
	//h2.afisareHighlighter();
	h3.afisareHighlighter();

	//caiete
	Caiet caiet1;
	Caiet caiet2(100, 24, 30);
	Caiet caiet3(120, 7, "A4", 103);
	//caiet1.afisareCaiet();
	caiet2.afisareCaiet();
	//caiet3.afisareCaiet();
	
	//----------task3----------
	Stilou s4(stilou2);
	s4.afisareStilou();

	Highlighter h4(h3);
	h3.afisareHighlighter();

	Caiet caiet4(caiet2);
	caiet4.afisareCaiet();

	stilou1.setCuloareStilou("Negru");
	cout << stilou1.getCuloareStilou() << endl;
	cout << Stilou::getNumarStilouri() << endl;

	h2.setCuloareH("Magenta");
	cout << h2.getCuloareH() << endl;
	cout << Highlighter::getNumarHighlightere() << endl;

	caiet3.setNrPagini(120);
	cout << caiet3.getNrPagini() << endl;
	cout << Caiet::getTVA() << endl;


	//cout << caiet3.getNrPagini() << ", " << caiet3.getPret();
	modificaNrPagini(caiet3);

	modifCuloare(stilou3);

	return 0;
}