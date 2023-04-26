/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"

int EGOERA;
int seg3;

void ZE_Teklatua() {
	switch (EGOERA) {
	case HASIERA:
		switch (sakatutakoTekla()) {
			case A:
				jokoaHasi();
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

