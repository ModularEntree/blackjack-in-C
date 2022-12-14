#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 10
#define TRUE true

int hit() {
    return rand() % (10-1+1) + 1;
}

typedef struct karta{
    int cislo;
    char id;
    char nazev[MAX_SIZE];
} Karta;


int main() {
    srand(time(NULL));
    Karta eso;
    eso.cislo =  1;
    eso.id = 'A';
    strcpy(eso.nazev, "Eso");
    Karta dvojka;
    dvojka.cislo =  2;
    dvojka.id = '2';
    strcpy(dvojka.nazev, "Dvojka");
    Karta trojka;
    trojka.cislo =  3;
    trojka.id = '3';
    strcpy(trojka.nazev, "Trojka");
    Karta ctyrka;
    ctyrka.cislo =  4;
    ctyrka.id = '4';
    strcpy(ctyrka.nazev, "Ctyrka");
    Karta petka;
    petka.cislo =  5;
    petka.id = '5';
    strcpy(petka.nazev, "Petka");
    Karta sestka;
    sestka.cislo =  6;
    sestka.id = '6';
    strcpy(sestka.nazev, "Sestka");
    Karta sedma;
    sedma.cislo =  7;
    sedma.id = '7';
    strcpy(sedma.nazev, "Sedma");
    Karta osma;
    osma.cislo =  8;
    osma.id = '8';
    strcpy(osma.nazev, "Osma");
    Karta devitka;
    devitka.cislo =  9;
    devitka.id = '9';
    strcpy(devitka.nazev, "Devitka");
    Karta desitka;
    desitka.cislo =  10;
    desitka.id = 'X';
    strcpy(desitka.nazev, "Desitka");
    Karta junek;
    junek.cislo =  10;
    junek.id = 'J';
    strcpy(junek.nazev, "Junek");
    Karta kralovna;
    kralovna.cislo =  10;
    kralovna.id = 'Q';
    strcpy(kralovna.nazev, "Kralovna");
    Karta kral;
    kral.cislo =  10;
    kral.id = 'K';
    strcpy(kral.nazev, "Kral");
    // hra
    int i;
    int HandMe[22];
    int HandHouse[22];
    for (i = 0; i<=22;i++)
        HandMe[i] = 0;
    for (i = 0; i<=22;i++)
        HandMe[i] = 0;
    HandMe[0] = hit();
    HandMe[1] = hit();
    HandHouse[0] = hit();
    HandHouse[1] = hit();
    while (TRUE) {

    }
    return 0;
}
