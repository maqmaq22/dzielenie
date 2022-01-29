#include <iostream>
#include <string>     
#include <math.h>
using namespace std;
int main() {
	string li1, li2, dl;
	string napis2, napis1;
	//cout << "jaka jesli 1 liczba?";
	//cin >> li1;
	//cout << "jaka jesli 2 liczba?";
	//cin >> li2;
	li1 = "458724";
	li2 = "48";
	napis1 = li1;
	napis2 = li2;
	int dziel = stoi(li2);
	int suma = 0;
	int ileCyfr1 = napis1.length();
	int ileCyfr2 = napis2.length();
	int x = 1;
	int liczba1 = 0;
	bool pierwszy_raz = true;
	for (int i = ileCyfr2 - 1; i >= 0; i--) {
		int cyfra1 = napis1[i] - '0';

		liczba1 = liczba1 + cyfra1 * x;
		x = x * 10;

		cout << liczba1 << endl;
	}

	if (liczba1 >= dziel) {
		int wyn = liczba1 - (liczba1 / dziel)*dziel;
		cout << "Wynik: ";
		cout << wyn << endl;
	}
	else {
		liczba1 = 0;
		pierwszy_raz = true;
		int x = 1;
		for (int i = ileCyfr2; i >= 0; i--) {
			int cyfra1 = napis1[i] - '0';
			liczba1 = liczba1 + cyfra1 * x;
			x = x * 10;
			cout << liczba1 << endl;
		}
		int wyn = liczba1 - (liczba1 / dziel)*dziel;
		cout << "Wynik: ";
		cout << wyn << endl;
	}

}