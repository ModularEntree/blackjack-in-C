#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
//#include <raylib.h>
#define MAX_SIZE 22
#define null ((void*)0)

typedef struct Card{
    int num;
    char id, name[MAX_SIZE];
} card;

typedef struct Localization{
    char error_hs[29], error_unk[24], option_hs[16], option_win[12], option_lose[13];
} localization;

card ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king;
localization czech, english, def;

int hit();
int sum(int *p);

localization local();
bool hitOrStand ();
/*
int main() {
    srand(time(null)); // maybe change the seed?
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
    // GAME - in future in function
    int i, HandSumMe, HandSumHouse, cardNumMe = 0, cardNumHouse = 0;
    // "nulling" hands and giving them first two cards
    int HandMe[MAX_SIZE], HandHouse[MAX_SIZE];
    for (i = 0; i<=MAX_SIZE;i++)
        HandMe[i] = 0;
    for (i = 0; i<=MAX_SIZE;i++)
        HandHouse[i] = 0;
    HandMe[cardNumMe++] = hit();
    printf("%d\n", HandMe[--cardNumMe]);
    HandMe[cardNumMe++] = hit();
    printf("%d\n", HandMe[--cardNumMe]);
    HandHouse[cardNumHouse++] = hit();
    printf("%d\n", HandHouse[--cardNumHouse]);
    HandHouse[cardNumHouse++] = hit();
    printf("%d\n", HandHouse[--cardNumHouse]);
    // sum of hands for later start-win situation
    HandSumMe = sum(HandMe);
    HandSumHouse = sum(HandHouse);

    for (true;true;cardNumMe++) {
        if (hitOrStand()==true) {
            HandMe[cardNumMe] = hit();
            printf("%d\n", HandMe[cardNumMe]);
        }
        else
            for (true;true;cardNumHouse++) {
                HandHouse[cardNumHouse] = hit();
                printf("%d\n", HandHouse[cardNumHouse]);
                if ((sum(HandHouse)<=21)&&(sum(HandHouse)>=sum(HandMe))) {
                    puts(def.option_lose);
                    break;
                }
                else {
                    puts(def.option_win);
                    break;
                }
            }
        if (sum(HandMe)>21) {
            puts(def.option_lose);
            break;
        }
    }

    return 0;
}

int hit() {
    return rand() % (10-1+1) + 1;
}

int sum(int *hand) {
    int sum = 0, i, exc;
    for (i =0;i<=MAX_SIZE;(hand++)&&(i++)) {
        if ((sum<=21)&&(*hand==1)) {
            exc = 11; //this is temporary solution - i should make a recursive function to do this
        }
        else
            exc = *hand;
        sum = sum + exc;
    }
    return sum;
}

bool hitOrStand () {
    int stringlen;
    char *HOS;
    HOS = (char *) malloc (sizeof(char)*MAX_SIZE);
    puts(def.option_hs);
    fgets(HOS, sizeof(HOS), stdin);
    stringlen = strlen(HOS);
    HOS[stringlen-1]='\0';
    switch (stringlen) {
        case 2: {
            HOS = (char *) realloc ( HOS,sizeof(char)*2);
            if (!strcmp(HOS, "H"))
                return true;
            else if(!strcmp(HOS, "S"))
                return false;
            else if(!strcmp(HOS, "h"))
                return true;
            else if(!strcmp(HOS, "s"))
                return false;
            else
                puts(def.error_hs);
            break;
        }
        case 4: {
            HOS = (char *) realloc ( HOS,sizeof(char)*4);
            if (!strcmp(HOS, "Hit"))
                return true;
            else if (!strcmp(HOS, "hit"))
                return true;
            else
                puts(def.error_hs);
            break;
        }
        case 5: {
            HOS = (char *) realloc ( HOS,sizeof(char)*5);
            if (!strcmp(HOS, "Hit."))
                return true;
            else if (!strcmp(HOS, "hit."))
                return true;
            else
                puts(def.error_hs);
            break;
        }
        case 6: {
            HOS = (char *) realloc ( HOS,sizeof(char)*6);
            if (!strcmp(HOS, "Stand"))
                return false;
            else if(!strcmp(HOS, "stand"))
                return false;
            else
                puts(def.error_hs);
            break;
        }
        case 7: {
            HOS = (char *) realloc ( HOS,sizeof(char)*7);
            if(!strcmp(HOS, "Stand."))
                return false;
            else if(!strcmp(HOS, "stand."))
                return false;
            else
                puts(def.error_hs);
            break;
        }
        default: {
            puts(def.error_unk);;
            break;
        }
    }

    return null;
}

// i am not sure, if this will work, 'cause i am not on linux. must try it later
#ifdef __linux__ //outdated
localization local() {
    if (setlocale(LC_ALL, "") == null) {
        printf("Error in locale detection.");
    } else if (!strcmp(setlocale(LC_ALL, ""), setlocale(LC_ALL, "cs_CZ.UTF-8"))) {
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
#else
localization local() {
    //bool czech = false;
    if (!strcmp(setlocale(LC_ALL, ""), setlocale(LC_ALL, "Czech_Czechia.1250"))) {
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
        strcpy(czech.option_lose, "Prohlal jsi!");
        strcpy(czech.option_win, "Vyhral jsi!");
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
        strcpy(english.option_lose, "You lost!");
        strcpy(english.option_win, "You won!");
        strcpy(english.error_hs, "Unknown option was selected.");
        strcpy(english.error_unk, "Unknown error occurred.");

        return english;
    }
}
#
 */