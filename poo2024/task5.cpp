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

	Stilou(const Stilou& s) :id(++numarStilouri) {
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

	Stilou operator=(const Stilou& s) {
		if (this != &s) {
			this->culoareStilou = s.culoareStilou;
			this->lungime = s.lungime;
			if (this->producator != NULL) {
				delete[]this->producator;
			}
			this->producator = new char[strlen(s.producator) + 1];
			strcpy_s(this->producator, strlen(s.producator) + 1, s.producator);
		}
		return *this;
	}

	Stilou operator+(const Stilou& s) const {
		Stilou temp = *this;
		temp.lungime = this->lungime + s.lungime;
		return temp;
	}

	Stilou& operator+=(Stilou s) {
		*this = *this + s;
		return *this;
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

	friend ostream& operator<<(ostream& output, Stilou s) {
		output << "Id:" << s.id << endl;
		output << "Culoare: " << s.culoareStilou << endl;
		output << "Lungime: " << s.lungime << endl;
		if (s.producator != NULL) {
			output << "Producator: " << s.producator << endl;
		}
		return output;
	}

	friend istream& operator>>(istream& input, Stilou& s) {
		cout << "Culoare:";
		input >> s.culoareStilou;
		cout << "Lungime: ";
		input >> s.lungime;
		cout << "Producator: ";
		char buffer[50];
		input >> buffer;
		if (s.producator) {
			delete[]s.producator;
		}
		s.producator = new char[strlen(buffer) + 1];
		strcpy_s(s.producator, strlen(buffer) + 1, buffer);
		return input;
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

	Highlighter operator=(const Highlighter& h) {
		if (this != &h) {
			this->culoareH = h.culoareH;
			this->greutate = h.greutate;
			if (this->brand != NULL) {
				delete[]this->brand;
			}
			this->brand = new char[strlen(h.brand) + 1];
			strcpy_s(this->brand, strlen(h.brand) + 1, h.brand);
		}
		return *this;
	}

	bool operator>(Highlighter h) {
		return this->greutate > h.greutate;
	}

	bool operator==(Highlighter h) {
		return this->greutate == h.greutate;
	}

	explicit operator int() {
		return this->greutate;
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

	friend ostream& operator<<(ostream& output, Highlighter h);

	friend istream& operator>>(istream& input, Highlighter& h) {
		cout << "Culoare: ";
		input >> h.culoareH;
		cout << "Greutate: ";
		input >> h.greutate;
		cout << "Brand: ";
		char buffer[50];
		input >> buffer;
		if (h.brand) {
			delete[]h.brand;
		}
		h.brand = new char[strlen(buffer) + 1];
		strcpy_s(h.brand, strlen(buffer) + 1, buffer);
		return input;
	}

};
int Highlighter::numarHighlightere = 4;

ostream& operator<<(ostream& output, Highlighter h) {
	output << "Cod: " << h.cod << endl;
	output << "Culoare: " << h.culoareH << endl;
	if (h.brand != NULL) {
		output << "Brand: " << h.brand << endl;
	}
	output << "Greutate: " << h.greutate << endl;
	return output;
}

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
		this->pret = 8;
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

	Caiet operator=(const Caiet& c) {
		if (this != &c) {
			this->nrPagini = c.nrPagini;
			this->pret = c.pret;
			if (this->tipCaiet != NULL) {
				delete[]this->tipCaiet;
			}
			this->tipCaiet = new char[strlen(c.tipCaiet) + 1];
			strcpy_s(this->tipCaiet, strlen(c.tipCaiet) + 1, c.tipCaiet);
		}
		return *this;
	}

	friend Caiet operator+(float adaosPret, Caiet c) {
		Caiet temp = c;
		temp.pret += adaosPret;
		return temp;
	}

	Caiet operator++() {
		this->pret = this->pret + 1;
		return *this;
	}

	Caiet operator++(int) {
		Caiet aux = *this;
		this->pret = this->pret + 1;
		return aux;
	}

	explicit operator float() {
		return this->pret;
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

	friend istream& operator>>(istream& input, Caiet& c) {
		cout << "Numar pagini: ";
		input >> c.nrPagini;
		cout << "Pret: ";
		input >> c.pret;
		cout << "Tip caiet: ";
		char buffer[50];
		input >> buffer;
		if (c.tipCaiet) {
			delete[]c.tipCaiet;
		}
		c.tipCaiet = new char[strlen(buffer) + 1];
		strcpy_s(c.tipCaiet, strlen(buffer) + 1, buffer);
		return input;
	}

	friend ostream& operator<<(ostream& output, Caiet c) {
		output << "Cod: " << c.codC << endl;
		output << "Numar pagini: " << c.nrPagini << endl;
		if (c.tipCaiet != NULL) {
			output << "Tip caiet: " << c.tipCaiet << endl;
		}
		output << "Pret: " << c.pret << endl;
		output << "TVA: " << Caiet::TVA << endl;
		return output;
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
	//----------task5----------
	Stilou* vectorS;
	vectorS = new Stilou[3];
	for (int i = 0; i < 3; i++) {
		cin >> vectorS[i];
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << vectorS[i] << endl;
	}


	Highlighter* vectorH;
	vectorH = new Highlighter[2];
	for (int i = 0; i < 2; i++) {
		cin >> vectorH[i];
		cout << endl;
	}
	for (int i = 0; i < 2; i++) {
		cout << vectorH[i] << endl;
	}


	Caiet* vectorC;
	vectorC = new Caiet[4];
	for (int i = 0; i < 4; i++) {
		cin >> vectorC[i];
		cout << endl;
	}
	for (int i = 0; i < 4; i++) {
		cout << vectorC[i] << endl;
	}

	const int randuriS = 2;
	const int coloaneS = 2;
	Stilou stilou[randuriS][coloaneS];

	for (int i = 0; i < randuriS; i++) {
		for (int j = 0; j < coloaneS; j++) {
			cout << "[" << i << "][" << j << "]" << endl;
			cin >> stilou[i][j];
		}
	}
	cout << endl << "----Matrice de stilouri----" << endl;

	for (int i = 0; i < randuriS; ++i) {
		for (int j = 0; j < coloaneS; ++j) {
			//cout << "[" << i << "][" << j << "] : ";
			cout << stilou[i][j] << endl;
		}
	}

	delete[]vectorS;
	delete[]vectorH;
	delete[]vectorC;
	return 0;
}