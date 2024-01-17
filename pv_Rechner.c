/***

Name:			Noten-Durchschnitt ermitteln
Beschreibung:	Programm, in welchem mittlere kWh aus Solarstrahlung für verschiedene Standorte berechnet wird. Je nach Makro-Definition werden entweder Berechnungen
				zu Mittelwerten ausgegeben, oder es findet eine Benutzerabfrage statt, wo der User Werte über seine PV-Anlage angeben und sich die berechneten
				PV-Erträge in eine .txt-Datei abgespeichert werden.
Autorinnen:	    Emily Klemt, Carolin Altstaedt
Datum:		    22.12.2023
Version:			1

***/

#define _CRT_SECURE_NO_WARNINGS
//#define ausgabe_berechnung

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
	char* modulname;
	char* kurzform;
	float faktor;
	float note;
} tModul;


// Funktion zur Erfassung der Benutzereingabe
short einlesenEinerZahl(char text[], short min, short max);

int main(void) {
	char buffer[1000]; 
	char* data;
	
	int anzahlModule = 35; 

	tModul* moduleGesamt = (tModul*)malloc(anzahlModule * sizeof(tModul));


	if (moduleGesamt == NULL) {
		return 1; // Fehler mit malloc
	}

	/**DATEI**/
	FILE* moduleCSV = fopen("module.csv", "r");
	if (moduleCSV == NULL) {// Fehler?
		printf("Fehler: Datei nicht gefunden");
		return 1;
	}
	printf("Erfolg: Datei gefunden\n");
	/**DATEI**/
	

	fgets(buffer, sizeof(buffer), moduleCSV);
	printf("%s\n", buffer);
	int index = 0;

	while (fgets(buffer, sizeof(buffer), moduleCSV)) {

		// Speicher für chat-Werte von struct allokieren
		moduleGesamt[index].modulname = (char*)malloc(100 * sizeof(char));
		moduleGesamt[index].kurzform = (char*)malloc(10 * sizeof(char));


		data = strtok(buffer, ";");
		printf("%s,", data);
		strcpy((moduleGesamt[index].modulname), data);
		

		data = strtok(NULL, ";");
		printf("%s, ", data);
		strcpy((moduleGesamt[index].kurzform), data);

		data = strtok(NULL, ";");
		printf("%s,", data);

		data = strtok(NULL, ";");
		printf("%s", data);

		index++;
		//anzahlModule++;
	}

	fclose(moduleCSV);



	printf("\n");
	printf("Ausgabe gespeicherte Module:\n");

	for(int i = 0; i < anzahlModule; i++) {
		printf("%s, %s", moduleGesamt[i].modulname, moduleGesamt[i].kurzform);
		printf("\n");
	}

	float deineNote = einlesenEinerZahl("Welche Note hattest du", 1, 15);

	moduleGesamt[0].note = deineNote;


	printf("Deine gespeicherte Note: %.2f", moduleGesamt[0].note);
	

	

	// Free memory for the array of tModul elements
	/*
	for (int i = 0; i < anzahlModule; i++) {
		free(moduleGesamt[i].modulname);
		free(moduleGesamt[i].kurzform);
	}
	*/
	free(moduleGesamt);



	//ausgeben
	/*
	for (int i = 0; i < anzahlModule; i++) {
		printf("Modul: %c %c %c %c\n", moduleGesamt[i].modulname, moduleGesamt[i].kurzform, moduleGesamt[i].faktor, moduleGesamt[i].note);
	}
	*/

	return 0; 
}


short einlesenEinerZahl( // Funktion, um eine Benutzereingabe einzulesen
	char text[],
	short min,
	short max)
{
	short eingelesenerWert;		// eingegebene Zahl des Benutzers
	bool fertig = false;			// Variable, die anzeigt, ob die Eingabe den Anforderungen einer Lottozahl entspricht
	char ch;						// möglicher Buchstabe nach der eingegebenen Zahl
	int Rückgabewert;			// Rückgabewert von scanf

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







