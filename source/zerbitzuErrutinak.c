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
int recoil;
int POSX;
int ytiro;
int xtiro;

int vaultX[] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
int vaultY[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80};


int enemyX[] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
int enemyY[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80};
bool eskubira[] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
bool enemyAlive[] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
int remaining = 50;
int total = 50;

bool BIZIRIK = true;
bool tiro;
void ZE_Teklatua() {
	switch (EGOERA) {
	case HASIERA:
		if (sakatutakoTekla() == START) {
			// Reset enemies
			resetEnemies();

			showStars();
			POSX = 120;
			jokoaHasi();
		}
		if (sakatutakoTekla() == SELECT) {
			showBlack();
			jokoaAmaitu();
		}

		break;
	case JOLASTEN:

		if (sakatutakoTekla() == A && recoil >= 10 && !tiro) {
		
			recoil=0;
			xtiro=POSX;
			tiro=true;

			if (ytiro > 5) {
				showProjectile(5,xtiro,ytiro);
			}
			
		}


		switch (sakatutakoTekla()) {

		case EZKER:
			if (POSX > 0) {
				hidePlayer(1, POSX, 180);
				showPlayer(1, POSX-1, 180); // Show sprite 1px to the left
				POSX--; // Change logic position of player
			}
			break;
		case ESKUBI:
			if (POSX < 239) {
				hidePlayer(1, POSX, 180);
				showPlayer(1, POSX+1, 180); // Show sprite 1px to the right
				POSX++; // Change logic position of player
			}
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
		if (ytiro > 5 && tiro) {
			ytiro -= 5;
		}
		for (int i = 0; i < total; i++) {
			// Collider check with projectile
			if (xtiro >= enemyX[i]-8 && xtiro <= enemyX[i]+8) { // Projectile is inside X position range [-10 / 10]
				if (ytiro >= enemyY[i]-16 && ytiro <= enemyY[i]+16) { // Projectile is inside Y position range [-16 / 16]
					hideEnemy(i+6, enemyX[i], enemyY[i]); // Sprite disappears
					enemyAlive[i] = false; // Enemy marked as not alive
					ytiro = 0;
					if (remaining == 10) {
						consoleClear();
					}
					remaining--;
					enemyX[i] = -99;
					enemyY[i] = -99;
				}
			}

			// Collider check with borders
			if (enemyX[i] < 240 && eskubira[i]) {
				if (enemyAlive[i]) {
					enemyX[i] += 3;
				} else {
					hideEnemy(i+6, enemyX[i], enemyY[i]);
				}
			}

			if (enemyX[i] > 10 && !eskubira[i]) {
				if (enemyAlive[i]) {
					enemyX[i] -= 3;
				} else {
					hideEnemy(i+6, enemyX[i], enemyY[i]);
				}
			}

			if (enemyX[i] >= 235) {
				if (enemyAlive[i]) {
					enemyY[i] += 20;
					eskubira[i] = false;
				} else {
					hideEnemy(i+6, enemyX[i], enemyY[i]);
				}	
			}

			if (enemyX[i] <= 18) {
				if (enemyAlive[i]) {
					enemyY[i] += 20;
					eskubira[i] = true;
				} else {
					hideEnemy(i+6, enemyX[i], enemyY[i]);
				}
			}

			// Enemy check for Y value
			if (enemyY[i] > 160) {
				if (enemyAlive[i]) {
					hideAllEnemies(); // Player lost, enemy reached target Y coordinate
					BIZIRIK = false;
				}
			}
			
		}
		
		T3min++;
		recoil++;
		break;
		if (T3min == 3 * 60 * 10) {
			EGOERA = HASIERA;
		}
	default:
		break;
	}
}

void etenZerbErrutEzarri()
{
	irqSet(IRQ_KEYS, ZE_Teklatua);
	irqSet(IRQ_TIMER0, ZE_Timer0);
}