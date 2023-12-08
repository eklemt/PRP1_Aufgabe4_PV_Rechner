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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	float kwhProTagUndTageImMonat[12][2] = { {0.52, 31}, {1.13, 28}, {2.23, 31}, {3.55, 30}, {4.67, 31}, {5.44, 30}, {4.82, 31}, {4.34, 31}, {2.79, 30}, {1.49, 31}, {0.67, 30}, {0.40, 31} };
	float mittlererkwhWertMonat[12];
	float anzahlMonate = 12.0; 

	// Berechnung der mittleren monatlichen Strahlung + Ausgabe 
	for (int i = 0; i < 12; i++) {
		mittlererkwhWertMonat[i] = kwhProTagUndTageImMonat[i][0] * kwhProTagUndTageImMonat[i][1];
	}
	for (int i = 0; i < 12; i++) {
		printf("Mittlerer monatlicher Kwh Wert: %.2f\n", mittlererkwhWertMonat[i]); 
	}
	// Berechnung des Jahresmittels + Ausgabe 
	float gesamtkwhJahr = 0; 
	for (int i = 0; i < 12; i++) {
		gesamtkwhJahr += mittlererkwhWertMonat[i]; 
	}
	float monatlichesMittel = gesamtkwhJahr / anzahlMonate; 
	printf("Monatliches Mittel: %.2f\n", monatlichesMittel); 
}
