/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"

// Maxmod Utility
#include <maxmod.h> // Maxmod definitions for ARM9
#include "soundbank.h" // Soundbank definitions

int EGOERA;
int T3min;

void ZE_Teklatua() {
	switch (EGOERA) {
	case HASIERA:
		switch (sakatutakoTekla()) {
			case A:
				jokoaHasi();
				mmStart(MOD_INGAME, MM_PLAY_LOOP); // Start background song from memory
				EGOERA = JOLASTEN;
				T3min = 0;
				break;
			case B:
				jokoaAmaitu();
				EGOERA = AMAITU;
				break;
			default:
				break;
		}
		break;
	case JOLASTEN:
		if (sakatutakoTekla() == A) {
			tiroEgin();
		}
		break;
	case GAMEOVER:
		if (sakatutakoTekla() == B) {
			jokoaAmaitu();
			EGOERA = AMAITU;
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
		if (T3min == 3 * 60 * ) {
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

