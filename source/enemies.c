/*
enemies.c
*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "periferikoak.h"
#include "zerbitzuErrutinak.h"

int desplazamendua = -10;
int enemyPosY = 5;
bool ezkerrera = false;

void moveEnemies() {
    hideEnemy(2, 20+desplazamendua, enemyPosY);
    hideEnemy(2, 40+desplazamendua, enemyPosY);
    hideEnemy(2, 60+desplazamendua, enemyPosY);
    hideEnemy(2, 80+desplazamendua, enemyPosY);

    if (ezkerrera) {
        if (desplazamendua == -10) {
            ezkerrera = false;
        }
        desplazamendua--;
    } else {
        if (desplazamendua == 10) {
            ezkerrera = true;
        }
        desplazamendua++;
    }

    showEnemy(2, 20+desplazamendua, enemyPosY);
    showEnemy(2, 40+desplazamendua, enemyPosY);
    showEnemy(2, 60+desplazamendua, enemyPosY);
    showEnemy(2, 80+desplazamendua, enemyPosY);
}