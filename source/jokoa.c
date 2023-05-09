/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>		// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		// C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h>		// Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia

//Geuk garatutako fitxategiak
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"
#include "jokoa.h"

#include <maxmod.h>

extern int T3min;
extern bool BIZIRIK;
touchPosition PANT_DAT;

void jokoa() {	
	EGOERA = HASIERA;

	// Keyboard config
	int TEK_konf = 0x43FC; // A + B -> Inkesta
	konfiguratuTeklatua(TEK_konf);

	// Timer0 config
	int Latch = 62259; // (65536 - (1/10)*(33554432/1024)) = (65536 - (33554432/10240)) = (65536 - 3277)
	int TENP_konf = 0xC3; // 1100 0011
	konfiguratuTenporizadorea(Latch, TENP_konf);

	// Baimendu teklatuaren etenak
	tekEtenBaimendu();

	// Denboragailuaren etenak baimendu
	erlojuaMartxanJarri();
	denbEtenBaimendu();

	// Zerbitzu errutinak ezarri
	etenZerbErrutEzarri();

	while (EGOERA != AMAITU) {
		iprintf("\x1b[10;5HPLACEHOLDER");
		iprintf("\x1b[15;5HPLACEHOLDER");

		if (EGOERA == JOLASTEN && !BIZIRIK) {
			mmStop();
			hidePlayer(1, POSX, POSY);
			EGOERA = GAMEOVER;
		}
		if (EGOERA == GAMEOVER) {
			if (PANT_DAT.px > 0 || PANT_DAT.py > 0) {
				EGOERA = HASIERA;
			}
		}
	}
}

void jokoaHasi() {
	mmEffect(SFX_INGAME); // Start background song from memory
	BIZIRIK = true;
	int POSX = 128;
	int POSY = 191;
	showPlayer(1, POSX, POSY);
	T3min = 0;
	EGOERA = JOLASTEN;
}

void jokoaAmaitu() {
	EGOERA = AMAITU;
}