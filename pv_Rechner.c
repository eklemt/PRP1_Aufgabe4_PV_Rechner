/***

Name:			TicTacToe
Beschreibung:	Programm, in welchem der Nutzer TicTacToe gegen den Computer spielen kann und entweder gegen diesen verlieren, gewinnen oder unentschieden spielen kann.
				Dabei kann der Nutzer immer weiterspielen und der Spielstand wird über mehrere Runden bestimmt.
				Zudem kann der Nutzer entscheiden, wie schwer der Computer spielt und ob er selbst oder der Computer beginnt
Autorinnen:	    Emily Klemt, Carolin Altstaedt
Datum:		    19.11.2023
Version:		1

***/

#define _CRT_SECURE_NO_WARNINGS
#define ausgabe_berechnung
//#define abfrage_user

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


short einlesenEinerZahl(char text[], short min, short max);
void inDateiSpeichern();
float mittelBerechnen(float mittlererkwhWertMonat[][12], float kwhProTagUndTageImMonat[][12], char monate[][12]);

int main(void) {
	
	float anzahlMonate = 12.0;
	float gesamtkwhJahr = 0;
	float mittlererkwhWertMonat[12];
	char monate[12][12] = { "Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember" };

	//aufgabe 2-2
	float kwhProTagUndTageImMonat[12][2] = { {0.52, 31}, {1.13, 28}, {2.23, 31}, {3.55, 30}, {4.67, 31}, {5.44, 30}, {4.82, 31}, {4.34, 31}, {2.79, 30}, {1.49, 31}, {0.67, 30}, {0.40, 31} };
	//aufgabe 2-3
	//array das bestrahlungswinkel enthält
	float monatlichesMittelJeStadt[][12] = {
		//hamburg (0)
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
		//berlin (1)
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
		//kassel (2)
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
		//stuttgart (3)
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
		//freiburg (4)
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
	};


	#ifdef ausgabe_berechnung
		// Berechnung der mittleren monatlichen Strahlung + Ausgabe für Hamburg
		printf("Mittlerer monatlicher Kwh Wert:\n");

		// Berechnung der mittleren monatlichen Strahlung + Ausgabe 
		for (int i = 0; i < 12; i++) {
			mittlererkwhWertMonat[i] = kwhProTagUndTageImMonat[i][0] * kwhProTagUndTageImMonat[i][1];
			printf("%s: %.2f\n", monate[i], mittlererkwhWertMonat[i]);
		}
		

		printf("\n\n");
		// Berechnung des Jahresmittels + Ausgabe 
		for (int i = 0; i < 12; i++) {
			gesamtkwhJahr += mittlererkwhWertMonat[i];
		}
		float jahresmittel = gesamtkwhJahr / anzahlMonate;
		printf("Jahresmittel: %.2f kWh\n", jahresmittel);

		inDateiSpeichern();
	#else
		printf("andere option\n");
		int ort = NULL;
		int ausrichtung = NULL;
		int spitzenleistung = NULL;

		ort = einlesenEinerZahl("Bitte wähle einen Ort aus? (1=Berlin, 2=Kassel, 3=Hamburg)", 1, 3);
		ausrichtung = einlesenEinerZahl("Wie wird die PV-Anlage ausgerichtet? (1=horizontal, 2=Sued 30, 3=Sued 45, 4=Sued 60)", 1, 4);
		spitzenleistung = einlesenEinerZahl("Wie gross ist die Spitzenleisung (kWp)? (1-30)", 1, 30);

		printf("%d %d %d", ort, spitzenleistung, ausrichtung);

		//user eingabe (Zahl) auf wert zu berechnugn aus werte-array zuordnen
		//funktion aufrufen, werte von user als berechnugnsparameter übergeben



	#endif
	
}


float mittelBerechnen(float* zeiger_array[12], float kwhProTagUndTageImMonat[][12], char monate[][12]) {
	float a = *zeiger_array[12];

	for (int i = 0; i < 12; i++) {
		
		a = kwhProTagUndTageImMonat[i][0] * kwhProTagUndTageImMonat[i][1];
		zeiger_array++;
	}

	return a;
}

short einlesenEinerZahl( // Funktion, um eine Zahl einzulesen 
	char text[],
	short min,
	short max)
{
	short eingelesenerWert;		//eingegebene Zahl des Benutzers
	bool fertig = false;	// Variable, die anzeigt, ob die Eingabe den Anforderungen einer Lottozahl entspricht
	char ch;			//möglicher Buchstabe nach der eingegebenen Zahl
	int Rückgabewert;			//Rückgabewert von scanf

	do {
		//Einlesen der Zahl 
		printf("%s: ", text);
		ch = '\0';
		Rückgabewert = scanf("%hd%c", &eingelesenerWert, &ch);

		// Überprüfen, ob die Zahl den Anforderungen entspricht
		if (Rückgabewert != 2) printf("Das war keine korrekte Zahl!\n");
		else if (ch != '\n') printf("Unerwartete Zeichen hinter der Zahl!\n");
		else if (eingelesenerWert < min || eingelesenerWert > max) printf("Zahl muss zwischen 1 und %d liegen.\n", max);
		else fertig = true;
		// Input stream leeren 
		while (ch != '\n') {
			char checkChar = scanf("%c", &ch);
		}
		// wiederholen, wenn es nicht beendet ist 
	} while (!fertig);

	// Rückgabe der eingelesenen Zahl 
	return eingelesenerWert;
}

void inDateiSpeichern() { // Inhalt des arrays in .txt-Datei abspeichern
	char dateiname[] = "kwh_werte.txt";
	FILE* datei = fopen(dateiname, "w");


	if (datei == NULL) {
		printf("Fehler: Datei konnte nicht geöffnet werden");
	}

	fprintf("hallo meine kleine datei;)", "\n");

	fclose(datei);
}
