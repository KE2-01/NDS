extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern void memoriaErreserbatu();

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu pantaila nagusian. 0 balioa gardena da 
   eta definitu gabeko balioak beltzak. */

extern void paletaNagusiaEzarri();

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu bigarren pantailan. 0 balioa 
   gardena da eta definitu gabeko balioak beltzak. */

extern void bigarrenPaletaEzarri();

/* Irudikatutako Spriteak memorian kargatzen ditu.*/

extern void spriteakMemorianGorde();

/* Funtzio honek erronbo bat irudikatzen du pantailako x-y posizioan. Pantailan ateratzea nahi den erronbo 
   bakoitzari indize desberdin bat esleitu behar zaio, 0 eta 126 balioen arteko indizea izan daiteke. */

extern void showPlayer(int indizea, int x, int y);

/*Funtzio honek erronbo baten indizea pasata pantailatik ezabatzen du*/

extern void hidePlayer(int indizea, int x, int y);

extern void showBoss(int indizea, int x, int y);
extern void hideBoss(int indizea, int x, int y);

extern void showProjectile(int indizea, int x, int y);
extern void hideProjectile(int indizea, int x, int y);

extern void showEnemy(int indizea, int x, int y);
extern void hideEnemy(int indizea, int x, int y);
