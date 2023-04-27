/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>		// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		// C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h>		// Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia

#include <maxmod.h> // Maxmod definitions for ARM9
#include "soundbank.h" // Soundbank definitions

// Geuk garatutako fitxategiak

#include "grafikoak.h"		
#include "definizioak.h"
#include "spriteak.h"
#include "jokoa.h"


//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// MaxMod from https://maxmod.devkitpro.org
	mmInitDefaultMem( (mm_addr) soundbank_bin);
	mmLoad(MOD_INGAME); // Load ingame song into memory

	HasieratuGrafikoakSpriteak();
	EtenakBaimendu();

	// Enables sound on the DS. Should be called prior to attempting sound playback.
	soundEnable();

	// Zuen jokoari dei egingo zaio hemendik
	jokoa();

	return(0);

}
