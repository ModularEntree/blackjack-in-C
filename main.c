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

typedef struct Card{
    int num;
    char id, name[MAX_SIZE];
} card;

typedef struct Localization{
    char error_hs[29], error_unk[24], option_hs[16];
} localization;

card ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king;
localization czech, english, def;

int hit();
int sum(int *p);

localization local();

int main() {
    srand(time(null));
    ace.num =  1;
    ace.id = 'A';
    two.num =  2;
    two.id = '2';
    three.num =  3;
    three.id = '3';
    four.num =  4;
    four.id = '4';
    five.num =  5;
    five.id = '5';
    six.num =  6;
    six.id = '6';
    seven.num =  7;
    seven.id = '7';
    eight.num =  8;
    eight.id = '8';
    nine.num =  9;
    nine.id = '9';
    ten.num =  10;
    ten.id = 'X';
    jack.num =  10;
    jack.id = 'J';
    queen.num =  10;
    queen.id = 'Q';
    king.num =  10;
    king.id = 'K';
    // start conf
    def = local();
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

    puts(def.option_hs);
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
                puts(def.error_hs);
            break;
        }
        case 4: {
            HOS = (char *) realloc ( HOS,sizeof(char)*4);
            if (!strcmp(HOS, "Hit"))
                Hit = true;
            else if (!strcmp(HOS, "hit"))
                Hit = true;
            else
                puts(def.error_hs);
            break;
        }
        case 5: {
            HOS = (char *) realloc ( HOS,sizeof(char)*5);
            if (!strcmp(HOS, "Hit."))
                Hit = true;
            else if (!strcmp(HOS, "hit."))
                Hit = true;
            else
                puts(def.error_hs);
            break;
        }
        case 6: {
            HOS = (char *) realloc ( HOS,sizeof(char)*6);
            if (!strcmp(HOS, "Stand"))
                Stand = true;
            else if(!strcmp(HOS, "stand"))
                Stand = true;
            else
                puts(def.error_hs);
            break;
        }
        case 7: {
            HOS = (char *) realloc ( HOS,sizeof(char)*7);
            if(!strcmp(HOS, "Stand."))
                Stand = true;
            else if(!strcmp(HOS, "stand."))
                Stand = true;
            else
                puts(def.error_hs);
            break;
        }
        default: {
            puts(def.error_unk);;
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

localization local() {
    //bool czech = false;
    if (setlocale(LC_ALL, "") == null) {
        printf("Error in locale detection.");
    } else if (!strcmp(setlocale(LC_ALL, ""), setlocale(LC_ALL, "Czech_Czechia.1250"))) {
        // Czech localization (cause i am czech, lol)
        // structs
        strcpy(ace.name, "Eso");
        strcpy(two.name, "Dvojka");
        strcpy(three.name, "Trojka");
        strcpy(four.name, "Ctyrka");
        strcpy(five.name, "Petka");
        strcpy(six.name, "Sestka");
        strcpy(seven.name, "Sedma");
        strcpy(eight.name, "Osma");
        strcpy(nine.name, "Devitka");
        strcpy(ten.name, "Desitka");
        strcpy(jack.name, "Junek");
        strcpy(queen.name, "Kralovna");
        strcpy(king.name, "Kral");
        // normal text
        strcpy(czech.option_hs, "Hit nebo stand?");
        // errors
        strcpy(czech.error_hs, "Nepodporovany vyraz.");
        strcpy(czech.error_unk, "Neznama chyba.");
        return czech;
    } else {
        // Default US localization
        strcpy(ace.name, "Ace");
        strcpy(two.name, "Two");
        strcpy(three.name, "Three");
        strcpy(four.name, "Four");
        strcpy(five.name, "Five");
        strcpy(six.name, "Six");
        strcpy(seven.name, "Seven");
        strcpy(eight.name, "Eight");
        strcpy(nine.name, "Nine");
        strcpy(ten.name, "Ten");
        strcpy(jack.name, "Jack");
        strcpy(queen.name, "Queen");
        strcpy(king.name, "King");
        strcpy(english.option_hs, "Hit or stand?");
        strcpy(english.error_hs, "Unknown option was selected.");
        strcpy(english.error_unk, "Unknown error occurred.");
        return english;
    }
}