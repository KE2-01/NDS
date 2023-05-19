/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"


int tekla; // Sakatutako tekla gordetzeko aldagaia



int teklaDetektatu() 
{
	// TRUE itzultzen du teklaren bat sakatu dela detektatzen badu
	if ((~TEKLAK_DAT & 0x03ff)!=0) return 1;
	else return 0;

}

int sakatutakoTekla() 
{

	// Sakatutako teklaren balioa itzultzen du: A=0;B=1;Select=2;Start=3;Esk=4;Ezk=5;
	//Gora=6;Behera=7;R=8;L=9;
	if (~(TEKLAK_DAT) & 0x0001) return A;
	if (~(TEKLAK_DAT) & 0x0002) return B;

	if (~(TEKLAK_DAT) & 0x0004) return SELECT;
	if (~(TEKLAK_DAT) & 0x0008) return START;

	if (~(TEKLAK_DAT) & 0x0010) return ESKUBI;
	if (~(TEKLAK_DAT) & 0x0020) return EZKER;
	if (~(TEKLAK_DAT) & 0x0030) return GORA;
	if (~(TEKLAK_DAT) & 0x0040) return BEHERA;

	if (~(TEKLAK_DAT) & 0x0100) return R;
	if (~(TEKLAK_DAT) & 0x0200) return L;

	return (int) NULL;
}

void konfiguratuTeklatua(int TEK_konf)
{
	// Teklatuaren konfigurazioa bere S/I erregistroak aldatuz
	TEKLAK_KNT |= TEK_konf; // TEKLAK_KNT = TEKLAK_KNT | TEK_konf
}

void konfiguratuTenporizadorea(int Latch, int TENP_konf)
{
	// Tenporizadorearen konfigurazioa bere S/I erregistroak aldatuz
	DENB0_DAT = Latch;
	DENB0_KNT |= TENP_konf;
	
}

void tekEtenBaimendu()
{
	// Teklatuaren etenak baimendu
	// Lan hau burutzeko lehenengo eten guztiak galarazi behar dira eta bukaeran baimendu 
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE |= 0x1000;
	IME=1;
}

void tekEtenGalarazi()
{

	// Teklatuaren etenak galarazi
	// Lan hau burutzeko lehenengo eten guztiak galarazi behar dira eta bukaeran baimendu 
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE &= 0xEFFF;
	IME=1;
}  

void denbEtenBaimendu()
{

// Denboragailu baten etenak baimendu (Timer0)
// Horretarako lehenengo eten guztiak galarazi eta bukaeran berriro baimendu
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE |= 0x00000008;
	IME=1;
}

void denbEtenGalarazi()
{

// Denboragailu baten etenak galarazi (Timer0)
// Horretarako lehenengo eten guztiak galarazi eta bukaeran berriro baimendu
	IME=0;
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	IE &= 0xFFFFFFF7;
	IME=1;

}

void erlojuaMartxanJarri()
{
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	DENB0_KNT |= 0x00C0;
}

void erlojuaGelditu()
{
	// HEMEN IDATZI BEHAR DUZUE ZUEN KODEA
	DENB0_KNT &= 0xFF7F;
}
