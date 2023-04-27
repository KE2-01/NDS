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

int denb;

void jokoa()
{	
	EGOERA = HASIERA;

	// Keyboard config
	// int TEK_konf = ALDATU_BALIO_HAU;
	// konfiguratuTeklatua(TEK_konf);

	// Timer0 config
	// int Latch = ALDATU_BALIO_HAU;
	// int TENP_konf = ALDATU_BALIO_HAU;
	// konfiguratuTenporizadorea(Latch, TENP_konf);

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
