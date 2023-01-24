//
// Created by Gregstr on 24/01/2023.
//

#ifndef BLACKJACK_MAIN_H
#define BLACKJACK_MAIN_H

#endif //BLACKJACK_MAIN_H

#include <stdbool.h>

#define MAX_SIZE 22
#define null ((void*)0)

int hit();
int sum(int *p);

void Hit();
void Stand();
void Start();

typedef struct Card{
    int num;
    char id, name[MAX_SIZE];
} card;

typedef struct Localization{
    char error_hs[29], error_unk[24], option_hs[16], option_win[12], option_lose[13];
} localization;

extern int HandSumMe, HandSumHouse;
extern int HandMe[MAX_SIZE], HandHouse[MAX_SIZE];
extern int cardNumMe, cardNumHouse;
extern card ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king;
extern localization czech, english, def;

localization local();
bool hitOrStand();

extern bool bPlayerTurn;

extern bool bWin;
extern bool bLose;