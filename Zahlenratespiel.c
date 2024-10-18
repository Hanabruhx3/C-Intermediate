#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/*Davor "void spiel(int hoechstzahl)" alleine ganz oben stehen gehabt, nun die ganze Funktion nach oben verschoben.
Spiel Funktion muss als erstes gelesen werden daher kommt diese vor dem main (man kann die auch nachher schreiben aber man muss dann einen platzhalter vorne dran schrieben)*/


//Function wird definiert
void spiel(int hoechstzahl) {
	int zufallszahl, geraten;
	int	versuche = 0;		
	int punkte = 100;							//Variablen werden deklariert
	srand(time(0));								//Eine Zahl wird ausgewählt abhängig von der jetztigen zeit (Es gibt kein random, die jetztige Zeit wird als startwert für den seed geholt)
	zufallszahl = rand() % (hoechstzahl + 1);	//soll eine Zufallszahl zwischen 0 und der "hoechstzahl" generieren (its taking the remainder of the division as the random number)

	printf("\nEine Zahl zwischen 0 und %d wurde ausgewaehlt. Versuchen Sie diese zu erraten!\n\n", hoechstzahl);

	do {
		printf("Geben Sie Ihren Tip ein: ");
		if (scanf_s("%d", &geraten) != 1) {		//Checkt ob der Input Zahl 
			printf("UNGUELTIGE EINGABE. Bitte geben Sie eine Zahl zwischen 0 und %d ein.\n", hoechstzahl);
			while (getchar() != '\n');			//loop liest und entfernt die ungültige eingabe bis zum leerzeichen enter (clean up loop)
			continue;
		}

		versuche++;								//versuche werden gezählt
		if (versuche > 1) {						//Beim ersten versuch werden noch keine Punkte abgezogen erst ab dem zweiten
			punkte -= 10;						//Pro Fehlversuch werden 10 Punkte abgezogen
			if (punkte < 0) punkte = 0;
		}
		
		if (geraten < zufallszahl) {			//meldung Zahl kleiner falls die Zahl kleiner als Zufallszahl ist
			printf("Zu niedrig! Versuchen Sie es nocheinmal.\n\n");
		}

		else if (geraten > zufallszahl) {		//meldung Zahl größer falls die Zahl kleiner als Zufallszahl ist
			printf("Zu hoch! Versuchen Sie es nocheinmal.\n\n");
		}

		else { 
			printf("Glueckwunsch! Sie haben die Zahl %d in %d Versuchen erraten!\n", zufallszahl, versuche);
			printf("Sie haben %d Punkte erhalten!\n", punkte);
		}

	} while (geraten != zufallszahl);			//Kondition solange die geratene Zahl ungleich der Zufallszahl entspricht wird die loop nicht verlassen!
}

//int main hat das menü, ist für inputs verantwortlich, und hat die neustart funktion implementiert.
int main() {
	int schwierigkeit;
	int hoechstzahl;
	char neustart;


	//do loop ist dafür verantwortlich, für den neustart
	//while loop soll checken ob die usereingabe mit einen von den schwierigkeitsstufen übereinstimmt. Falls nicht wird nocheinmalabgefragt.
	//Die breaks sind dafür da um die loops zu verlassen sollte die Eingabe mit EINES der SchwierigkeitsgradenZahlen übereinstimmen
	do {

		while (1) {
			printf("Wilkommen zum Zahlenratespiel! \n Bitte geben Sie die gewuenschte Schwierigkeitsstufe ein.\n");
			printf("1. Easy (0 - 10)\n");
			printf("2. Intermediate (0 - 100)\n");
			printf("3. Difficult (0 - 1000)\n");
			printf("4. Extreme (0 - 10 000)\n\n");
			scanf_s(" %d", &schwierigkeit);


			if (schwierigkeit == 1) {
				hoechstzahl = 10;
				break;
			}
			else if (schwierigkeit == 2) {
				hoechstzahl = 100;
				break;
			}
			else if (schwierigkeit == 3) {
				hoechstzahl = 1000;
				break;
			}
			else if (schwierigkeit == 4) {
				hoechstzahl = 10000;
				break;
			}
			else {
				printf("Ihre Eingabe ist UNGUELTIG bitte geben Sie eine gültige Schwiergkeitsstufe ein.\n");
			}
		}

		spiel(hoechstzahl);										//Spiel wird angefangen mit der höchstzahl der ausgewählten schwierigkeitsstufe

		printf("\nMoechten Sie nocheinmal spielen? ja=(j) nein=(beliebige Taste) ");
		scanf_s(" %c", &neustart);
	} while (neustart == 'j' || neustart == 'J');				// spiel wird bei 'j' oder 'J' neugestartet bei jedem anderen input wird die loop verlassen

	printf("Danke fuers Spielen! Aufwiedersehen.");

	return 0;
}




