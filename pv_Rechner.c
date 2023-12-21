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
//#define ausgabe_berechnung

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


short einlesenEinerZahl(char text[], short min, short max);
int JahresMittelMonatsMittelAufgabe4(double neigungskorrekturfaktoren[12], double monatlichesmittelproStadt[12], char monate[][12], int kwP, bool inDatei); 
#ifndef ausgabe_berechnung
void jahresumsatz(double gesamtkwhJahr, double kwP);
#endif 

int main(void) {

	char monate[12][12] = { "Januar", "Februar", "Maerz", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember" };

	//aufgabe 2-2
	double kwhProTagUndTageImMonat[12][2] = { {0.52, 31}, {1.13, 28}, {2.23, 31}, {3.55, 30}, {4.67, 31}, {5.44, 30}, {4.82, 31}, {4.34, 31}, {2.79, 30}, {1.49, 31}, {0.67, 30}, {0.40, 31} };
	//aufgabe 2-3
	double neigungskorrekturfaktoren[4][12] = {
		// kein Faktor 
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
		//sued 30
		{1.44, 1.40, 1.17, 1.08, 1.0, 0.96, 0.97, 1.03, 1.17, 1.30, 1.47, 1.42},
		// sued 45
		{1.57, 1.50, 1.19, 1.05, 0.94, 0.90, 0.91, 1.00, 1.18, 1.37, 1.61, 1.55},
		// sued 60
		{1.63, 1.54, 1.15, 0.98, 0.85, 0.81, 0.83, 0.92, 1.14, 1.38, 1.68, 1.61} };


	//array das bestrahlungswinkel enthält
	double monatlichesMittelJeStadt[5][13] = {
		//hamburg (0)
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
		//berlin (1)
		{19, 33, 75, 128, 160, 166, 158, 134, 94, 51, 26, 15, 1059},
		//kassel (2)
		{20, 34, 77, 123, 150, 162, 154, 132, 90, 52, 25, 16, 1037},
		//stuttgart (3)
		{29, 45, 85, 130, 153, 174, 164, 140, 99, 62, 36, 24, 1139},
		//freiburg (4)
		{29, 45, 84, 129, 153, 172, 166, 141, 104, 63, 38, 24, 1150}
	};

	// Werte für Hamburg eintragen
	for (int i = 0; i < 12; i++) {
		monatlichesMittelJeStadt[0][i] = kwhProTagUndTageImMonat[i][0] * kwhProTagUndTageImMonat[i][1];
	};


#ifdef ausgabe_berechnung

	// Erklärung des Programms 
	printf("Hallo! Das folgende Programm gibt die mittlere Leistung einer Solaranalage im Monat und im Jahr aus, sowie die Jahresgesamtleistung.\n");
	printf("Das Programm gibt diese Werte fuer verschiedene Orte und Neigungsfaktoren aus, bei 1kwP.\n\n"); 

	char neigung[][100] = { {"horizontal"}, {"sued 30 Grad"}, {"sued 45 Grad"}, {"sued 60 Grad"} }; 
	char städte[][25] = { {"Hamburg"}, {"Berlin"}, {"Kassel"}, {"Stuttgart"}, {"Freiburg"} }; 
	int kwP = 1; // in dieser Ausführung wird durchgehend für 1kwP berechnet
	bool inDatei = false; 

	// 2 for-Schleifen einmal Neigungswinkel durchgehen
	for (int i = 0; i < 4; i++) {
		printf("Ausgabe fuer Hamburg, %s", neigung[i]);
		JahresMittelMonatsMittelAufgabe4(neigungskorrekturfaktoren[i], monatlichesMittelJeStadt[0], monate, kwP, inDatei); 
	}
	for (int i = 1; i < 5; i++) {
		printf("Ausgabe fuer %s, %s", städte[i], neigung[0]);
		JahresMittelMonatsMittelAufgabe4(neigungskorrekturfaktoren[0], monatlichesMittelJeStadt[i], monate, kwP, inDatei);
	}
	
	
#else
	int ort;
	int ausrichtung;
	int spitzenleistung;
	int abspeichern; 

	printf("Hallo! Das folgende Programm gibt die mittlere Leistung einer Solaranalage im Monat und im Jahr aus, sowie die Jahresgesamtleistung.\n");
	printf("Um den Wert zu berechnen, musst du vorher noch einige Parameter festlegen\n"); 
	ort = einlesenEinerZahl("Bitte wähle einen Ort aus? (1=Hamburg, 2=Berlin, 3=Kassel, 4=Stuttgart, 5=Freiburg)", 1, 5)-1;
	ausrichtung = einlesenEinerZahl("Wie wird die PV-Anlage ausgerichtet? (1=horizontal, 2=Sued 30, 3=Sued 45, 4=Sued 60)", 1, 4)-1;
	spitzenleistung = einlesenEinerZahl("Wie gross ist die Spitzenleistung (kWp)? (1-30)", 1, 30);
	abspeichern = einlesenEinerZahl("Möchtest du dein Ergebnis in einer Datei speichern (=1) oder ausgeben(=2)", 1, 2);

	bool inDatei = true;
	if (abspeichern == 2) inDatei = false; 
	 
	JahresMittelMonatsMittelAufgabe4(neigungskorrekturfaktoren[ausrichtung], monatlichesMittelJeStadt[ort], monate, spitzenleistung, inDatei);


#endif

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

int JahresMittelMonatsMittelAufgabe4(double neigungskorrekturfaktoren[12], double monatlichesmittelproStadt[12], char monate[][12], int kwP, bool inDatei) { 
	double korrigierteMonatlicheKWH[12];
	for (int i = 0; i < 12; i++) {
		korrigierteMonatlicheKWH[i] = (monatlichesmittelproStadt[i] * neigungskorrekturfaktoren[i]) * kwP;
	}

	printf("\n");
	double gesamtkwhJahr = 0;
	double jahresmittel = 0;
	double anzahlMonate = 12;
	// Berechnung des Jahresmittels + Ausgabe 
	for (int i = 0; i < 12; i++) {
		gesamtkwhJahr += korrigierteMonatlicheKWH[i];
	}
	jahresmittel = gesamtkwhJahr / anzahlMonate;	

	if (inDatei == false) {
		bool ersterDurchlauf = true; 
		for (int i = 0; i < 12; i++) {
			if (ersterDurchlauf) {
				printf("%s: %.2f ", monate[i], korrigierteMonatlicheKWH[i]);
				ersterDurchlauf = false; 
			}
			else {
				printf("|%s: %.2f ", monate[i], korrigierteMonatlicheKWH[i]);
			}
		}
		printf("\n"); 
		printf("Jahresmittel: %.2f kWh\n", jahresmittel);
		printf("Jahresgesamt: %.2f kwh\n", gesamtkwhJahr);
		printf("\n\n");
	}
	#ifndef ausgabe_berechnung
	jahresumsatz(gesamtkwhJahr, kwP);

	if (inDatei) { // Ergebnisse in Datei schreiben 
		char dateiname[] = "kwh_werte.txt";
		FILE* datei = fopen(dateiname, "w");
		if (datei == NULL) {
			printf("Fehler: Datei konnte nicht geöffnet werden");
			return 1;
		}
		for (int i = 0; i < 12; i++) {
			bool ersterDurchlauf = true; 
			if (ersterDurchlauf) {
				fprintf(datei, "%s: %.2f ", monate[i], korrigierteMonatlicheKWH[i]);
				ersterDurchlauf = false; 
			}
			else {
				fprintf(datei, "| %s: %.2f ", monate[i], korrigierteMonatlicheKWH[i]);
			}
		}
		fprintf(datei,"\n");
		fprintf(datei, "Jahresmittel: %.2f kWh\n", jahresmittel);
		fprintf(datei, "Jahresgesamt: %.2f kwh\n", gesamtkwhJahr);
		fprintf(datei, "\n");

		fclose(datei);

	}
	#endif
	return 0; 
}

#ifndef ausgabe_berechnung
void jahresumsatz(double gesamtkwhJahr, double kwP) {
	double umsatz; 
	if (kwP > 10) {
		double einspeisepreis; 
		double restMit0071; 
		restMit0071 = kwP - 10; 
		einspeisepreis = ((10 * 0.082 + restMit0071 * 0.071) / kwP); // die ersten 10 kwP haben den Einspeisepreis 8,2ct und die restlichen 7,1ct
		umsatz = gesamtkwhJahr * einspeisepreis;
	}
	else {
		umsatz = gesamtkwhJahr * 0.082; // 8,2 ct ist der Einspeisepreis für eine kwh, wenn die Anlage weniger als 10 kwP hat 
	}
	printf("Der Umsatz fuer eine reine Einspeisanlage waere %.2f Euro pro Jahr.\n", umsatz); 
	printf("In den meisten Faellen lohnt sich jedoch eine reine Einspeisanlage eher weniger, da gekaufter Strom sehr teuer ist und man nur wenig Geld fuer das Einspeisen bekommt.\n"); 
	printf("Deshalb kann man meist mehr Geld sparen/verdienen, wenn man mit der Anlage auch den Eigenbedarf deckt.\n"); 
}
#endif 
