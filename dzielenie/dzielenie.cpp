#include <iostream>
#include <string>     
#include <math.h>
using namespace std;

int dajLiczbeZMiejsca(string liczbaJakoStr, int miejsceOd, int miejsceDo) {
	int ileCyfr = liczbaJakoStr.length();
	int liczba = 0;
	int x = 1;
	for (int i = miejsceDo; i >= miejsceOd; i--) {
		int cyfra1 = liczbaJakoStr[i] - '0';
		liczba = liczba + cyfra1 * x;
		x = x * 10;
	}
	return liczba;
}

int main() {
	string li1, li2, dl;
	string napis2, napis1;
	//cout << "jaka jesli 1 liczba?";
	//cin >> li1;
	//cout << "jaka jesli 2 liczba?";
	//cin >> li2;
	li1 = "1844674400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	li2 = "184467440";
	napis1 = li1;
	napis2 = li2;
	int dziel = stoi(li2);
	int suma = 0;
	int ileCyfr1 = napis1.length();
	int ileCyfr2 = napis2.length();
	int x = 1;
	int liczba1 = 0;
	bool poczatek = true;
	bool koniec = false;
	unsigned _int64 cala = 0;
	unsigned _int64 reszta = 0;
	int j = ileCyfr1;
	int znacznikStart = 0;
	int znacznikKoniec = 0;
	string wynik = "";
	int liczba = 0;
	while (j >= 0) {
		
		if (poczatek) {
			// pierwsze obliczenia. Szukamy liczby większej lub równej dzielnikowi
			// i obliczamy pierwszą cyfrę wyniku dzielenia oraz resztę
			liczba = dajLiczbeZMiejsca(napis1, znacznikStart, znacznikKoniec);
			if (liczba >= dziel) {
				cala = liczba / dziel;
				reszta = liczba % dziel;
				znacznikStart++;
				znacznikKoniec++;
				wynik += to_string(cala);
				poczatek = false;
				//pierwszy wynik się pojawił od teraz tu nie wchodzimy tylko jedziemy niżej
				//po jednej cyfrze
			}
			else {
				znacznikKoniec++;
			}
		}

		if (!poczatek && !koniec) {
			//liczenie jak na kartce
			znacznikStart = znacznikKoniec;
			liczba = dajLiczbeZMiejsca(napis1, znacznikStart, znacznikKoniec);
			cala = (reszta * 10 + liczba) / dziel;
			wynik += to_string(cala);
			reszta = (reszta * 10 + liczba) - (cala * dziel);
			znacznikKoniec++;
			if (znacznikKoniec == ileCyfr1) koniec = true;
		}
		j--;
	}
	cout << "wynik: " << wynik << endl;
	cout << "reszta: " << reszta << endl;
}


