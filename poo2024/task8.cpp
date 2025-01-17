#include <iostream>
#include<fstream>

using namespace std;

class Stilou {
private:
	string culoareStilou;
	int lungime;
	char* producator;
	static int numarStilouri;
	const int id;

public:
	Stilou() : id(++numarStilouri) {
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

	Stilou(const Stilou& s) :id(s.id) {
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
		if (s.lungime > 0) {
			output << "Lungime: " << s.lungime << endl;
		}
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

	friend ifstream& operator>>(ifstream& input, Stilou& s) {
		input >> s.culoareStilou;
		input >> s.lungime;
		char buffer[50];
		input >> buffer;
		s.producator = new char[strlen(buffer) + 1];
		strcpy_s(s.producator,strlen(buffer) +1, buffer);
		return input;
	}

	friend ofstream& operator<<(ofstream& output, Stilou s) {
		output << s.id << endl;
		output << s.culoareStilou << endl;
		if (s.lungime > 0) {
			output << s.lungime << endl;
		}
		if (s.producator != NULL) {
			output << s.producator << endl;
		}
		return output;
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
	Highlighter() :cod(++numarHighlightere) {
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

	/*Highlighter(string culoareH, const char* brand, int cod) :cod(cod) {
		this->culoareH = culoareH;
		this->brand = new char[strlen(brand) + 1];
		strcpy_s(this->brand, strlen(brand) + 1, brand);
	}*/

	~Highlighter() {
		if (this->brand) {
			delete[]this->brand;
		}
	}

	Highlighter(const Highlighter& h) :cod(h.cod) {
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

	void scriereFisierBinar(fstream& f) {
		int lungime = culoareH.length();
		f.write((char*)&lungime, sizeof(int));
		f.write((char*)(culoareH.c_str()), lungime * sizeof(char));
		f.write((char*)&greutate, sizeof(int));
		int lungime2 = strlen(this->brand);
		f.write((char*)&lungime2, sizeof(int));
		for (int i = 0; i < lungime2; i++) {
			f.write((char*)&this->brand[i], sizeof(char));
		}
	}

	void citesteFisierBinar(fstream& f) {
		int lungime = 0;
		f.read((char*)&lungime, sizeof(int));
		f.read((char*)(culoareH.c_str()), lungime * sizeof(char));
		f.read((char*)&this->greutate, sizeof(int));
		int lungime2;
		f.read((char*)&lungime2, sizeof(int));
		if (this->brand != NULL) {
			delete[]this->brand;
		}
		this->brand = new char[lungime2 + 1];
		for (int i = 0; i < lungime2; i++) {
			f.read((char*)&this->brand[i], sizeof(char));
		}
		this->brand[lungime2] = '\0';
	}

};
int Highlighter::numarHighlightere = 4;

ostream& operator<<(ostream& output, Highlighter h) {
	output << "Cod: " << h.cod << endl;
	output << "Culoare: " << h.culoareH << endl;
	if (h.brand != NULL) {
		output << "Brand: " << h.brand << endl;
	}
	if (h.greutate > 0) {
		output << "Greutate: " << h.greutate << endl;
	}
	return output;
}

class Caiet {
private:
	int nrPagini;
	float pret;
	char* tipCaiet;
	const int codC;
	static int TVA;
	static int numarCaiete;
public:
	Caiet() :codC(++numarCaiete) {
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

	/*Caiet(int nrPagini, float pret, int codC) :codC(codC) {
		this->nrPagini = nrPagini;
		this->pret = pret;
	}*/

	~Caiet() {
		if (this->tipCaiet) {
			delete[]this->tipCaiet;
		}
	}

	Caiet(const Caiet& c) : codC(c.codC) {
		this->nrPagini = c.nrPagini;
		this->pret = c.pret;
		if (c.tipCaiet) {
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

	void scriereFisierBinar(fstream& f) {
		f.write((char*)&nrPagini, sizeof(int));
		f.write((char*)&pret, sizeof(float));
		int lungime = strlen(this->tipCaiet);
		f.write((char*)&lungime, sizeof(int));
		for (int i = 0; i < lungime; i++) {
			f.write((char*)&this->tipCaiet[i], sizeof(char));
		}
	}

	void citesteFisierBinar(fstream& f) {
		f.read((char*)&this->nrPagini, sizeof(int));
		f.read((char*)&pret, sizeof(float));
		int lungime;
		f.read((char*)&lungime, sizeof(int));
		if (this->tipCaiet != NULL) {
			delete[]this->tipCaiet;
		}
		this->tipCaiet = new char[lungime + 1];
		for (int i = 0; i < lungime; i++) {
			f.read((char*)&this->tipCaiet[i], sizeof(char));
		}
		this->tipCaiet[lungime] = '\0';
	}



	friend void modificaNrPagini(Caiet c);
};
int Caiet::TVA = 19;
int Caiet::numarCaiete = 2;

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


class Magazin {
private:
	char* nume;
	Stilou* stilou;
	Highlighter highlighter;
	int nrCaiete;
	Caiet** caiete;

public:
	Magazin() {
		this->nume = NULL;
		this->stilou = new Stilou("Albastru", "Stabilo", 12);
		this->nrCaiete = 0;
		this->caiete = NULL;
	}

	Magazin(const char* nume, Stilou* s, Highlighter h, int nrCaiete, Caiet** caiete) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->stilou = new Stilou(*s);
		this->highlighter = h;
		this->nrCaiete = nrCaiete;
		this->caiete = new Caiet * [this->nrCaiete];
		for (int i = 0; i < this->nrCaiete; i++) {
			this->caiete[i] = new Caiet(*caiete[i]);
		}
	}

	Magazin(const Magazin& m) {
		this->nume = new char[strlen(m.nume) + 1];
		strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);
		this->stilou = new Stilou(*(m.stilou));
		this->highlighter = m.highlighter;
		this->nrCaiete = m.nrCaiete;
		this->caiete = new Caiet * [this->nrCaiete];
		for (int i = 0; i < this->nrCaiete; i++) {
			this->caiete[i] = new Caiet(*(m.caiete[i]));
		}
	}

	~Magazin() {
		if (this->nume) {
			delete[]this->nume;
		}
		if (this->stilou) {
			delete this->stilou;
		}
		for (int i = 0; i < this->nrCaiete; i++) {
			if (this->caiete[i]) {
				delete this->caiete[i];
			}
		}
		if (this->caiete) {
			delete[]this->caiete;
		}
	}

	Magazin operator=(const Magazin& m) {
		if (this != &m) {
			if (this->nume) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(m.nume) + 1];
			strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);
			if (this->stilou) {
				delete this->stilou;
			}
			this->stilou = new Stilou(*(m.stilou));
			this->highlighter = m.highlighter;
			for (int i = 0; i < this->nrCaiete; i++) {
				if (this->caiete[i]) {
					delete this->caiete[i];
				}
			}
			if (this->caiete) {
				delete[]this->caiete;
			}
			this->nrCaiete = m.nrCaiete;
			this->caiete = new Caiet * [this->nrCaiete];
			for (int i = 0; i < this->nrCaiete; i++) {
				this->caiete[i] = new Caiet(*(m.caiete[i]));
			}
		}
		return *this;
	}

	Highlighter getHighlighter()const {
		return this->highlighter;
	}

	const char* getNume() {
		return this->nume;
	}

	int getNrCaiete() {
		return this->nrCaiete;
	}

	void setNrCaiete(int nrCaiete) {
		if (nrCaiete > 0) {
			this->nrCaiete = nrCaiete;
		}
	}

	friend ostream& operator<<(ostream& output, const Magazin& m) {
		if (m.nume) {
			output << "Numele magazinului: " << m.nume << endl;
		}
		if (m.stilou) {
			output << "Stilou: " << endl;
			output << *m.stilou << endl;
		}
		output << "Highlighter: " << endl;
		output << m.highlighter << endl;
		if (m.nrCaiete > 0) {
			output << "Avem " << m.nrCaiete << " caiete in magazin: " << endl;
			for (int i = 0; i < m.nrCaiete; i++) {
				output << *m.caiete[i] << endl;
			}
		}
		output << endl;
		return output;
	}

	friend istream& operator>>(istream& input, Magazin& m) {
		cout << "Numele magazinului: ";
		char buffer[100];
		input >> buffer;
		if (m.nume) {
			delete[]m.nume;
		}
		m.nume = new char[strlen(buffer) + 1];
		strcpy_s(m.nume, strlen(buffer) + 1, buffer);
		cout << "Stilou " << endl;
		if (m.stilou) {
			delete m.stilou;
		}
		m.stilou = new Stilou();
		input >> *m.stilou;
		cout << "Highlighter " << endl;
		input >> m.highlighter;
		cout << "Numar caiete: ";
		input >> m.nrCaiete;
		if (m.caiete) {
			for (int i = 0; i < m.nrCaiete; i++) {
				if (m.caiete[i]) {
					delete m.caiete[i];
				}
			}
			if (m.caiete) {
				delete[]m.caiete;
			}
		}
		if (m.nrCaiete > 0) {
			m.caiete = new Caiet * [m.nrCaiete];
			for (int i = 0; i < m.nrCaiete; i++) {
				cout << "caiet[" << i << "]: " << endl;
				m.caiete[i] = new Caiet();
				input >> *m.caiete[i];
			}
		}
		return input;
	}

	friend ifstream& operator>>(ifstream& input, Magazin& m) {
		char buffer[100];
		input >> buffer;
		if (m.nume) {
			delete[]m.nume;
		}
		m.nume = new char[strlen(buffer) + 1];
		strcpy_s(m.nume, strlen(buffer) + 1, buffer);
		if (m.stilou) {
			delete m.stilou;
		}
		m.stilou = new Stilou();
		input >> *m.stilou;
		input >> m.highlighter;
		input >> m.nrCaiete;
		if (m.caiete) {
			for (int i = 0; i < m.nrCaiete; i++) {
				if (m.caiete[i]) {
					delete m.caiete[i];
				}
			}
			if (m.caiete) {
				delete[]m.caiete;
			}
		}
		if (m.nrCaiete > 0) {
			m.caiete = new Caiet * [m.nrCaiete];
			for (int i = 0; i < m.nrCaiete; i++) {
				m.caiete[i] = new Caiet();
				input >> *m.caiete[i];
			}
		}
		return input;
	}

	friend ofstream& operator<<(ofstream& output, Magazin m) {
		if (m.nume) {
			output << m.nume << endl;
		}
		if (m.stilou) {
			output << *m.stilou << endl;
		}
		output << m.highlighter << endl;
		if (m.nrCaiete > 0) {
			output << m.nrCaiete << endl;
			for (int i = 0; i < m.nrCaiete; i++) {
				output << *m.caiete[i] << endl;
			}
		}
		output << endl;
		return output;
	}
};

class Librarie : public Magazin {
private:
	char* oras;
	int nrCartiDisponibile;
	int nrCartiVandute;
	float pretCarte;

public:
	Librarie() :Magazin() {
		this->oras = NULL;
		this->nrCartiDisponibile = 0;
		this->nrCartiVandute = 0;
		this->pretCarte = 0;
	}

	Librarie(const char* oras, int nrCartiDisponibile, int nrCartiVandute, float pretCarte) :Magazin() {
		this->oras = new char[strlen(oras) + 1];
		strcpy_s(this->oras, strlen(oras) + 1, oras);
		this->nrCartiDisponibile = nrCartiDisponibile;
		this->nrCartiVandute = nrCartiVandute;
		this->pretCarte = pretCarte;
	}

	Librarie(const char* oras, int nrCartiDisponibile, int nrCartiVandute, float pretCarte, const char* nume, Stilou* s, Highlighter h, int nrCaiete, Caiet** caiete) :Magazin(nume, s, h, nrCaiete, caiete) {
		this->oras = new char[strlen(oras) + 1];
		strcpy_s(this->oras, strlen(oras) + 1, oras);
		this->nrCartiDisponibile = nrCartiDisponibile;
		this->nrCartiVandute = nrCartiVandute;
		this->pretCarte = pretCarte;
	}

	~Librarie() {
		if (this->oras) {
			delete[]this->oras;
		}
	}

	Librarie(const Librarie& l) :Magazin(l) {
		this->oras = new char[strlen(l.oras) + 1];
		strcpy_s(this->oras, strlen(l.oras) + 1, l.oras);
		this->nrCartiDisponibile = l.nrCartiDisponibile;
		this->nrCartiVandute = l.nrCartiVandute;
		this->pretCarte = l.pretCarte;
	}

	operator int() {
		return this->nrCartiDisponibile;
	}

	float getPretCarte() {
		return this->pretCarte;
	}

	void setPretCarte(float pretCarte) {
		if (pretCarte > 0) {
			this->pretCarte = pretCarte;
		}
	}

	int getNumarCartiDupaVanzare() {
		int nrCartiRamase = this->nrCartiDisponibile - this->nrCartiVandute;
		return nrCartiRamase;
	}

	float getIncasariPeZi() {
		return this->nrCartiVandute * this->pretCarte;
	}

	Librarie operator=(const Librarie& l) {
		if (this != &l) {
			Magazin::operator=(l);
			if (this->oras) {
				delete[]this->oras;
			}
			this->oras = new char[strlen(l.oras) + 1];
			strcpy_s(this->oras, strlen(l.oras) + 1, l.oras);
			this->nrCartiDisponibile = l.nrCartiDisponibile;
			this->nrCartiVandute = l.nrCartiVandute;
			this->pretCarte = l.pretCarte;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& output, const Librarie& l) {
		output << (Magazin)l;
		output << "Oras: " << l.oras << endl;
		output << "Numar carti disponibile: " << l.nrCartiDisponibile << endl;
		output << "Numar carti vandute la finalul zilei: " << l.nrCartiVandute << endl;
		output << "Pret carte: " << l.pretCarte << endl;
		return output;
	}

	friend istream& operator>>(istream& input, Librarie& l) {
		input >> (Magazin&)l;
		cout << "Oras: ";
		char buffer[100];
		input >> buffer;
		if (l.oras) {
			delete[]l.oras;
		}
		l.oras = new char[strlen(buffer) + 1];
		strcpy_s(l.oras, strlen(buffer) + 1, buffer);
		cout << "Numar carti disponibile: ";
		input >> l.nrCartiDisponibile;
		cout << "Numar carti vandute la finalul zilei: ";
		input >> l.nrCartiVandute;
		cout << "Pret carte: ";
		input >> l.pretCarte;
		return input;
	}
};

class PapetarieOnline :public Magazin {
private:
	char* site;
	int nrColaboratori;
public:
	PapetarieOnline() :Magazin() {
		this->site = NULL;
		this->nrColaboratori = 0;
	}

	PapetarieOnline(const char* site, int nrColaboratori, const char* nume, Stilou* s, Highlighter h, int nrCaiete, Caiet** caiete) :Magazin(nume, s, h, nrCaiete, caiete) {
		this->site = new char[strlen(site) + 1];
		strcpy_s(this->site, strlen(site) + 1, site);
		this->nrColaboratori = nrColaboratori;
	}

	PapetarieOnline(PapetarieOnline& po) :Magazin(po) {
		this->site = new char[strlen(po.site) + 1];
		strcpy_s(this->site, strlen(po.site) + 1, po.site);
		this->nrColaboratori = po.nrColaboratori;
	}

	~PapetarieOnline() {
		if (this->site) {
			delete[]this->site;
		}
	}

	PapetarieOnline operator=(const PapetarieOnline& po) {
		if (this != &po) {
			Magazin::operator=(po);
			if (this->site) {
				delete[]this->site;
			}
			this->site = new char[strlen(po.site) + 1];
			strcpy_s(this->site, strlen(po.site) + 1, po.site);
			this->nrColaboratori = po.nrColaboratori;
		}
		return *this;
	}

	explicit operator int() {
		return this->nrColaboratori;
	}

	const char* getSite() {
		return this->site;
	}

	int getNrColaboratori() {
		return this->nrColaboratori;
	}

	void setNrColaboratori(int nrColaboratori) {
		if (nrColaboratori > 0) {
			this->nrColaboratori = nrColaboratori;
		}
	}

	friend ostream& operator<<(ostream& output, const PapetarieOnline& po) {
		output << (Magazin)po;
		output << "Site-ul papetariei: ";
		output << po.site << endl;
		output << "Numar colaboratori: " << po.nrColaboratori << endl;
		return output;
	}

	friend istream& operator>>(istream& input, PapetarieOnline& po) {
		input >> (Magazin&)po;
		cout << "Site-ul papetariei: ";
		char buffer[100];
		input >> buffer;
		if (po.site) {
			delete[]po.site;
		}
		po.site = new char[strlen(buffer) + 1];
		strcpy_s(po.site, strlen(buffer) + 1, buffer);
		cout << "Numar colaboratori: ";
		input >> po.nrColaboratori;
		return input;
	}
};


int main() {
	//---------task8--------
	ofstream fisierStilou("fisierStilou.txt", ios::app);
	Stilou s1("Albastru", 12, "Schneider", 13);
	fisierStilou << s1;
	Stilou s2("Roz", 14, "Stabilo", 14);
	fisierStilou << s2;
	fisierStilou.close();
	/*ifstream fisierStilou1("fisierStilou1.txt", ios::in);
	Stilou s3;
	fisierStilou1 >> s3;
	cout << s3 << endl;
	fisierStilou1.close();*/

	Highlighter h("Roz", 23, "Daco", 20);
	fstream fisierBinar("fisierBinar.txt", ios::binary | ios::out);
	h.scriereFisierBinar(fisierBinar);
	fisierBinar.close();

	/*fstream fisierBinar1("fisierBinar.txt", ios::binary | ios::in);
	Highlighter h1;
	h1.citesteFisierBinar(fisierBinar1);
	cout << h1;
	fisierBinar1.close();*/

	Caiet caiet1(120, 7, "A4", 103);
	fstream fisierBinar2("fisierBinar2.txt", ios::binary | ios::out);
	caiet1.scriereFisierBinar(fisierBinar2);
	fisierBinar2.close();

	/*fstream fisierBinar3("fisierBinar.txt", ios::binary | ios::in);
	Caiet caiet2;
	caiet2.citesteFisierBinar(fisierBinar3);
	cout << caiet2 << endl;
	fisierBinar3.close();*/

	ofstream fisierMagazin("fisierMagazin.txt", ios::app);
	Stilou* s = new Stilou();
	Highlighter h2("Roz", 14, "Daco", 8);
	Caiet** caiete = new Caiet * [3];
	caiete[0] = new Caiet();
	caiete[1] = new Caiet(134, 25, "A4", 27);
	caiete[2] = new Caiet(100, 10, "A4", 20);
	Magazin magazin1("Papetarie", s, h2, 3, caiete);
	fisierMagazin << magazin1;
	fisierMagazin.close();
	/*ifstream fisierMagazin1("fisierMagazin2.txt", ios::in);
	Magazin magazin;
	cout << magazin << endl;*/

	return 0;
}