#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <locale.h>
#include <winnls.h>
//#include <raylib.h>
#define MAX_SIZE 22
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
    Karta ace;
    ace.cislo =  1;
    ace.id = 'A';
    Karta two;
    two.cislo =  2;
    two.id = '2';
    Karta three;
    three.cislo =  3;
    three.id = '3';
    Karta four;
    four.cislo =  4;
    four.id = '4';
    Karta five;
    five.cislo =  5;
    five.id = '5';
    Karta six;
    six.cislo =  6;
    six.id = '6';
    Karta seven;
    seven.cislo =  7;
    seven.id = '7';
    Karta eight;
    eight.cislo =  8;
    eight.id = '8';
    Karta nine;
    nine.cislo =  9;
    nine.id = '9';
    Karta ten;
    ten.cislo =  10;
    ten.id = 'X';
    Karta jack;
    jack.cislo =  10;
    jack.id = 'J';
    Karta queen;
    queen.cislo =  10;
    queen.id = 'Q';
    Karta king;
    king.cislo =  10;
    king.id = 'K';
    // start conf
    char error_hs[29], error_unk[24], option_hs[16];
    if (setlocale(LC_ALL, "")==null) {
        printf("Error in locale detection.");
    }
    else if (!strcmp(setlocale(LC_ALL, ""),setlocale(LC_ALL, "Czech_Czechia.1250"))) {
        // Czech localization (cause i am czech, lol)
        // structs
        strcpy(ace.nazev, "Eso");
        strcpy(two.nazev, "Dvojka");
        strcpy(three.nazev, "Trojka");
        strcpy(four.nazev, "Ctyrka");
        strcpy(five.nazev, "Petka");
        strcpy(six.nazev, "Sestka");
        strcpy(seven.nazev, "Sedma");
        strcpy(eight.nazev, "Osma");
        strcpy(nine.nazev, "Devitka");
        strcpy(ten.nazev, "Desitka");
        strcpy(jack.nazev, "Junek");
        strcpy(queen.nazev, "Kralovna");
        strcpy(king.nazev, "Kral");
        // normal text
        strcpy(option_hs, "Hit nebo stand?");
        // errors
        strcpy(error_hs, "Nepodporovany vyraz.");
        strcpy(error_unk, "Neznama chyba.");
    }
    else {
        // Default US localization
        strcpy(ace.nazev, "Ace");
        strcpy(two.nazev, "Two");
        strcpy(three.nazev, "Three");
        strcpy(four.nazev, "Four");
        strcpy(five.nazev, "Five");
        strcpy(six.nazev, "Six");
        strcpy(seven.nazev, "Seven");
        strcpy(eight.nazev, "Eight");
        strcpy(nine.nazev, "Nine");
        strcpy(ten.nazev, "Ten");
        strcpy(jack.nazev, "Jack");
        strcpy(queen.nazev, "Queen");
        strcpy(king.nazev, "King");
        strcpy(option_hs, "Hit or stand?");
        strcpy(error_hs, "Unknown option was selected.");
        strcpy(error_unk, "Unknown error occurred.");
    }
    // game
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

    puts(option_hs);
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
                puts(error_hs);
            break;
        }
        case 4: {
            HOS = (char *) realloc ( HOS,sizeof(char)*4);
            if (!strcmp(HOS, "Hit"))
                Hit = true;
            else if (!strcmp(HOS, "hit"))
                Hit = true;
            else
                puts(error_hs);
            break;
        }
        case 5: {
            HOS = (char *) realloc ( HOS,sizeof(char)*5);
            if (!strcmp(HOS, "Hit."))
                Hit = true;
            else if (!strcmp(HOS, "hit."))
                Hit = true;
            else
                puts(error_hs);
            break;
        }
        case 6: {
            HOS = (char *) realloc ( HOS,sizeof(char)*6);
            if (!strcmp(HOS, "Stand"))
                Stand = true;
            else if(!strcmp(HOS, "stand"))
                Stand = true;
            else
                puts(error_hs);
            break;
        }
        case 7: {
            HOS = (char *) realloc ( HOS,sizeof(char)*7);
            if(!strcmp(HOS, "Stand."))
                Stand = true;
            else if(!strcmp(HOS, "stand."))
                Stand = true;
            else
                puts(error_hs);
            break;
        }
        default: {
            puts(error_unk);;
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