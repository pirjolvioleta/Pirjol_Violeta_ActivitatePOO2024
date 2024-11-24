#include<iostream>

using namespace std;

struct Bloc {
	char* strada;
	int nrScari;
	int nrApartamente;
	string tipConstructie;
	int anConstructie;
};

Bloc* citire() {
	Bloc* b= new Bloc();
	cout << "Strada: ";
	char buffer[100];
	cin >> buffer;
	b->strada = new char[strlen(buffer) + 1];
	strcpy_s(b->strada, strlen(buffer) + 1, buffer);
	cout << "Numar scari: ";
	cin >> b->nrScari;
	cout << "Numar apartamente: ";
	cin >> b->nrApartamente;
	cout << "Tip constructie: ";
	cin >> b->tipConstructie;
	cout << "An constructie: ";
	cin >> b->anConstructie;
	cout << endl;
	return b;
}

void informatiiBloc(Bloc* bloc) {
	cout << "Blocul de pe strada " << bloc->strada << ", are " << bloc->nrScari << " scari si un numar total de "
		<< bloc->nrApartamente << " apartamente. Acest bloc dateaza din " << bloc->anConstructie 
		<< " si este construit din " << bloc->tipConstructie << "." << endl;
}

int main() {
	int nrBlocuri = 10;
	Bloc** pointeri;
	pointeri = new Bloc * [nrBlocuri];

	for (int i = 0; i < nrBlocuri; i++) {
		pointeri[i] = citire();
		informatiiBloc(pointeri[i]);
		cout << endl;
	}
	
	for (int i = 0; i < nrBlocuri; i++) {
		delete[]pointeri[i]->strada;
		delete pointeri[i];
	}
	delete[]pointeri;
	
	return 0;
}