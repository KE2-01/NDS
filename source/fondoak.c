/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>		// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		// C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h>		// Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia

/* Fondo desberdinak erakutsi nahi izango baditugu, hemen fondo bakoitzaren burukoa (.h fitxategia) gehitu behar da. Buruko horiek
automatikoki sortzen dira, konpilatzerako garaian, baina horretarako gogoratu behar da */

#include "fondoak.h"
#include "grafikoak.h"
#include "stars.h"
#include "black.h"
#include "gameover.h"
#include "mainbg.h"

/* irudiak memorian kopiatzeko DMA kanala aukeratu (3.a) */
static const int DMA_CHANNEL = 3;

/* Pantailaratu nahi den grafiko bakoitzerako horrelako prozedura bat idatzi behar da */

void showStars() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     starsBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     starsBitmapLen); /* Luzera (bytetan); automatikoki sortzen den aldagaia */
}

void showBlack() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     blackBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     blackBitmapLen); /* Luzera (bytetan); automatikoki sortzen den aldagaia */
}

void showOver() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     gameoverBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     gameoverBitmapLen); /* Luzera (bytetan); automatikoki sortzen den aldagaia */
}

void showMain() {
    dmaCopyHalfWords(DMA_CHANNEL, mainbgBitmap, (uint16 *)BG_BMP_RAM(0), mainbgBitmapLen);
}