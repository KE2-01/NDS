extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

void memoriaErreserbatu();

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu pantaila nagusian. 0 balioa gardena da 
   eta definitu gabeko balioak beltzak. */

void paletaNagusiaEzarri();

/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu bigarren pantailan. 0 balioa 
   gardena da eta definitu gabeko balioak beltzak. */

void bigarrenPaletaEzarri();

/* Irudikatutako Spriteak memorian kargatzen ditu.*/

void spriteakMemorianGorde();

/* Funtzio honek erronbo bat irudikatzen du pantailako x-y posizioan. Pantailan ateratzea nahi den erronbo 
   bakoitzari indize desberdin bat esleitu behar zaio, 0 eta 126 balioen arteko indizea izan daiteke. */

void showPlayer(int indizea, int x, int y);

/*Funtzio honek erronbo baten indizea pasata pantailatik ezabatzen du*/

void hidePlayer(int indizea, int x, int y);

void showBoss(int indizea, int x, int y);
void hideBoss(int indizea, int x, int y);

void showProjectile(int indizea, int x, int y);
void hideProjectile(int indizea, int x, int y);

void showEnemy(int indizea, int x, int y);
void hideEnemy(int indizea, int x, int y);
