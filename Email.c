#include <stdio.h>
#include <string.h> //library die string funktionen inkludieren

int main() {
	char email[255]; //wieviele zeichen in die variable email eingelesen werden können

	while (1) {
		printf("Geben Sie eine E-Mail-Adresse ein: ");
		scanf_s("%254s", email, (unsigned int)sizeof(email)); //%s format specifier für string. unsigned int alle positiven Zahlen + 0

		int at = 0;
		int dot = 0;


		int atposition = -1;				//Position @, -1 da at noch nicht gefunden wurde
		int dotposition = -1;				// Gleich wie bei @

			for (int i = 0; email[i]; i++) {		// läuft durch bis die zeichen gefunden werden    
			if (email[i] == '@') {					//einfache Anführungszeichen für einzelnes Zeichen, normales Anführungszeichen für string
				at++;
				atposition = i;						//wird auf die gleiche stelle wie zb email[i] gesetzt, also speichert die position des at zeichens
			}
			if (email[i] == '.') {
				dot++;
				atposition = i;
			}
		}
		if (at == 1 && dot >= 1 && atposition > 0 && dotposition > atposition + 1 && dotposition < strlen(email) - 1) { //at und dot sind enthalten, at ist nicht an erster stelle, dot is nach at + eine zwischenstelle, dot ist nicht die letzte stelle
			printf("Diese E-Mail ist gueltig!\n");
		}
		else {
			printf("Diese E-Mail ist ungueltig!\n");
		}
	}
	return 0;
}