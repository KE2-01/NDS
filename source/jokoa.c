/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h>	// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>	// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h> // C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h> // Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia

// Geuk garatutako fitxategiak

#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"
#include "jokoa.h"

extern int T3min;
extern bool BIZIRIK;
extern bool tiro;
touchPosition PANT_DAT;
extern int xtiro;
extern int ytiro;

extern int enemyX[];
extern int enemyY[];
extern bool enemyAlive[];
extern int total;
extern int remaining;

extern int vaultX[];
extern int vaultY[];

void jokoa()
{
	EGOERA = HASIERA;
	xtiro = 0;
	ytiro = 160;
	tiro = false;

	// Keyboard config
	int TEK_konf = 0x43FD; // B -> Inkesta (0100 0011 1111 1101)
	konfiguratuTeklatua(TEK_konf);

	// Timer0 config
	int Latch = 62259;	  // (65536 - (1/10)*(33554432/1024)) = (65536 - (33554432/10240)) = (65536 - 3277)
	int TENP_konf = 0xC3; // 1100 0011
	konfiguratuTenporizadorea(Latch, TENP_konf);

	// Baimendu teklatuaren etenak
	tekEtenBaimendu();

	// Denboragailuaren etenak baimendu
	erlojuaMartxanJarri();
	denbEtenBaimendu();

	// Zerbitzu errutinak ezarri
	etenZerbErrutEzarri();

	while (EGOERA != AMAITU)
	{
		iprintf("\x1b[2;5HSouls Invaders");
		iprintf("\x1b[7;5Hby");
		iprintf("\x1b[10;5HMario Gomez");
		iprintf("\x1b[12;5HXiker Indias");
		iprintf("\x1b[14;5HSendoa Careaga");

		if (sakatutakoTekla() == SELECT || sakatutakoTekla() == B) {
			if (EGOERA == HASIERA || EGOERA == GAMEOVER) {
				showBlack();
				jokoaAmaitu();
			}
		}

		switch(EGOERA) {
			case HASIERA:
				showMain();
				break;
			case JOLASTEN:
				iprintf("\x1b[20;5HEnemies= %d", remaining);
				if (!BIZIRIK) { // Player is not alive [LOST]
					hidePlayer(1, POSX, 170);
					showOver();
					EGOERA = GAMEOVER;
				} else { // Player is alive
					if (remaining == 0) { // No enemies remaining [WIN]
						hideProjectile(5, xtiro, ytiro);
						hidePlayer(1, POSX, 170);
						showOver();
						EGOERA = GAMEOVER;
					} else { // Some enemies remaining [INGAME]
						int i;
						for (i = 0; i < total; i++) {
							if (enemyAlive[i]) {
								showEnemy(i+6, enemyX[i], enemyY[i]); // If enemy is still alive, show sprite
							}
						}

						if (tiro) { // Show projectile
							showProjectile(5, xtiro, ytiro);
						}

						if (ytiro <= 10) { // Projectile reached end of trajectory
							hideProjectile(5, xtiro, ytiro);
							tiro = false;
							ytiro = 160;
						}
					}
				}
				break;
			case GAMEOVER:
				touchRead(&PANT_DAT);
				if (PANT_DAT.px > 0 || PANT_DAT.py > 0) {
					EGOERA = HASIERA;
				}
		}
	}

	tekEtenGalarazi();

	erlojuaGelditu();
	denbEtenGalarazi();
}

void jokoaHasi()
{	
	BIZIRIK = true;
	showPlayer(1, POSX, 180);
	T3min = 0;
	EGOERA = JOLASTEN;
}

void jokoaAmaitu()
{
	EGOERA = AMAITU;
}

void resetEnemies() {
	int i;
	for (i = 0; i < total; i++) {
		enemyX[i] = vaultX[i];
		enemyY[i] = vaultY[i];
	}
	memset(eskubira, true, total);
	memset(enemyAlive, true, total);
	remaining = total;
}

void hideAllEnemies() {
	int i;
	for (i = 0; i < total; i++) {
		if (enemyAlive[i]) {
			hideEnemy(i+6, enemyX[i], enemyY[i]);
			enemyX[i] = -99;
			enemyY[i] = -99;
		}
	}
}