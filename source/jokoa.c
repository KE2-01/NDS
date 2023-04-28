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


void jokoa()
{	
	EGOERA = HASIERA;

	// Keyboard config
	int TEK_konf = 0x43FC; // A + B -> Inkesta
	konfiguratuTeklatua(TEK_konf);

	// Timer0 config
	int Latch = 62259; // (65536 - (1/10)*(33554432/1024)) = (65536 - (33554432/10240)) = (65536 - 3277)
	int TENP_konf = 0xC3; // 1100 0011
	konfiguratuTenporizadorea(Latch, TENP_konf);

	// Baimendu teklatuaren etenak
	TekEtenBaimendu();

	// Denboragailuaren etenak baimendu
	ErlojuaMartxanJarri();
	DenbEtenBaimendu();

	// Zerbitzu errutinak ezarri
	etenZerbErrutEzarri();

	while (EGOERA != AMAITU) {
		iprintf("\x1b[10;5HPLACEHOLDER");
		iprintf("\x1b[15;5HPLACEHOLDER");
	}
}
