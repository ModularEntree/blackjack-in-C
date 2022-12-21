#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
//#include <raylib.h>
#define MAX_SIZE 22
#define TRUE true
#define null ((void*)0)

int hit();
int sum(int *p);

typedef struct karta{
    int cislo;
    char id;
    char nazev[MAX_SIZE];
} Karta;


int main() {
    srand(time(null));
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
    int i, HandSumMe = 0, HandSumHouse = 0, stringlen;
    char *HOS;
    HOS = (char *) malloc (sizeof(char)*MAX_SIZE);
    int HandMe[MAX_SIZE];
    int HandHouse[MAX_SIZE];
    bool Hit = false, Stand = false;
    for (i = 0; i<=MAX_SIZE;i++)
        HandMe[i] = 0;
    for (i = 0; i<=MAX_SIZE;i++)
        HandHouse[i] = 0;
    HandMe[0] = hit();
    printf("%d\n", HandMe[0]);
    HandMe[1] = hit();
    printf("%d\n", HandMe[1]);
    HandHouse[0] = hit();
    printf("%d\n", HandHouse[0]);
    HandHouse[1] = hit();
    printf("%d\n", HandHouse[1]);

    HandSumMe = sum(HandMe);
    HandSumHouse = sum(HandHouse);
    printf("%d\n", HandSumMe);
    printf("%d\n", HandSumHouse);

    printf("Hit or Stand? \n");
    fgets(HOS, sizeof(HOS), stdin);
    stringlen = strlen(HOS);
    HOS[stringlen-1]='\0';
    switch (stringlen) {
        case 2: {
            HOS = (char *) realloc ( HOS,sizeof(char)*2);
            if (!strcmp(HOS, "H"))
                Hit = true;
            else if(!strcmp(HOS, "S"))
                Stand = true;
            else if(!strcmp(HOS, "h"))
                Hit = true;
            else if(!strcmp(HOS, "s"))
                Stand = true;
            else
                printf("Nepodporovany vyraz.");
            break;
        }
        case 4: {
            HOS = (char *) malloc (sizeof(char)*4);
            if (!strcmp(HOS, "Hit"))
                Hit = true;
            else if (!strcmp(HOS, "hit"))
                Hit = true;
            else
                printf("Nepodporovany vyraz.");
            break;
        }
        case 5: {
            HOS = (char *) malloc (sizeof(char)*5);
            if (!strcmp(HOS, "Hit."))
                Hit = true;
            else if (!strcmp(HOS, "hit."))
                Hit = true;
            else
                printf("Nepodporovany vyraz.");
            break;
        }
        case 6: {
            HOS = (char *) malloc (sizeof(char)*6);
            if (!strcmp(HOS, "Stand"))
                Stand = true;
            else if(!strcmp(HOS, "stand"))
                Stand = true;
            else
                printf("Nepodporovany vyraz.");
            break;
        }
        case 7: {
            HOS = (char *) malloc (sizeof(char)*7);
            if(!strcmp(HOS, "Stand."))
                Stand = true;
            else if(!strcmp(HOS, "stand."))
                Stand = true;
            else
                printf("Nepodporovany vyraz");
            break;
        }
        default: {
            printf("Chyba ve funkci.");
            break;
        }
    }
    if (Hit==true||Stand==true)
        puts("Amogus");
    return 0;
}

int hit() {
    return rand() % (10-1+1) + 1;
}

int sum(int *p) {
    int sum = 0, i;
    for (i =0;i<=MAX_SIZE;p++&&i++)
        sum = sum + *p;
    return sum;
}