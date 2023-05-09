/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"
#include "jokoa.h"

// Maxmod Utility
#include <maxmod.h> // Maxmod definitions for ARM9
#include "soundbank.h" // Soundbank definitions

int EGOERA;
int T3min;
int POSX;
int POSY;
bool BIZIRIK = true;

void ZE_Teklatua() {
	switch (EGOERA) {
	case HASIERA:
		switch (sakatutakoTekla()) {
			case A:
				jokoaHasi();
				break;
			case B:
				jokoaAmaitu();
				break;
			default:
				break;
		}
		break;
	case JOLASTEN:
		switch (sakatutakoTekla()) {
		case A:
			//tiroEgin();
			break;
		case EZKER:
			hidePlayer(1, POSX, POSY);
			showPlayer(1, POSX-1, POSY);
			POSX -= 1;
			break;
		case ESKUBI:
			hidePlayer(1, POSX, POSY);
			showPlayer(1, POSX+1, POSY);
			POSX += 1;
			break;
		case GORA:
			hidePlayer(1, POSX, POSY);
			showPlayer(1, POSX, POSY+1);
			POSY += 1;
			break;
		case BEHERA:
			hidePlayer(1, POSX, POSY);
			showPlayer(1, POSX, POSY-1);
			POSY -= 1;
			break;
		default:
			break;
		}
		break;
	case GAMEOVER:
		if (sakatutakoTekla() == B) {
			jokoaAmaitu();
		}
		break;
	default:
		break;
	}
}

void ZE_Timer0() {
	switch (EGOERA) {
	case JOLASTEN:
		T3min++;
		break;
		if (T3min == 3 * 60 * 10) {
			mmStop(); // Stop current song
			EGOERA = HASIERA;
		}
	default:
		break;
	}
}

void etenZerbErrutEzarri()
{
// HAU BETE
	irqSet(IRQ_KEYS, ZE_Teklatua);
	irqSet(IRQ_TIMER0, ZE_Timer0);
}

