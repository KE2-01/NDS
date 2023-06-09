#ifndef DEFINIZIOAK_H
#define DEFINIZIOAK_H

/*-------------------------------------
definizioak.h
-------------------------------------*/

#include <nds.h> // NDS-rako garatuta dagoen liburutegia
#include <stdio.h> // C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h> // C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h> // Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia

#define IME (*(vuint32*)0x04000208) // Interrupt Master Enable -- Eten guztiak baimendu-galarazi
#define IE (*(vuint32*)0x04000210) // Interrupt Enable -- Etenak banaka baimendu-galarazi
#define IF (*(vuint32*)0x04000214) // Interrupt Flag -- Eten eskaeren erregistroa

// Etenen tratamendurako funtzioak
#define EtenakBaimendu() IME=1 // Eten guztiak baimendu
#define EtenakGalarazi() IME=0 // Eten guztiak galarazi

// teklatuaren erregistroak
#define TEKLAK_DAT (*(vu16*)0x4000130) // teklatuaren datu-erregistroa
#define TEKLAK_KNT (*(vu16*)0x4000132) // teklatuaren kontrol-erregistroa

// denboragailuaren (Timer0) erregistroak
#define DENB0_KNT (*(vuint16*)0x04000102) // kontrol-erregistroa
#define DENB0_DAT (*(vuint16*)0x04000100) // datu-erregistroa



// ukimen-pantailaren erregistroak
extern touchPosition PANT_DAT;

// Teklei izena eman diegu zenbakiak nahasgarriak izan daitezkeelako

#define A 0 
#define B 1
#define SELECT 2 
#define START 3
#define ESKUBI 4 
#define EZKER 5
#define GORA 6 
#define BEHERA 7
#define R 8 
#define L 9

// Egoerak
extern int EGOERA;
#define HASIERA 0
#define JOLASTEN 1
#define GAMEOVER 2
#define AMAITU 3

// Maxmod Utility
// Songs (audio folder)
#define SFX_INGAME 0
#define SFX_SECRET 1

// Other Settings
#define MSL_NSONGS 0
#define MSL_NSAMPS 2
#define MSL_BANKSIZE 2

// Player related variables
extern bool BIZIRIK;
extern int POSX;
extern int recoil;
extern bool tiro;
extern int ytiro;
extern int xtiro;

// Enemy related variables
extern int enemyX[];
extern int enemyY[];
extern bool enemyAlive[];
extern bool eskubira[];

#endif /* DEFINIZIOAK_H */