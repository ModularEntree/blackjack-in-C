//
// Created by Gregstr on 19/01/2023.
//

#ifndef BLACKJACK_LOAD_STRUCTS_H
#define BLACKJACK_LOAD_STRUCTS_H

#endif //BLACKJACK_LOAD_STRUCTS_H

#include "raylib.h"


typedef struct Cards {
    Texture2D cA;
    Texture2D c2;
    Texture2D c3;
    Texture2D c4;
    Texture2D c5;
    Texture2D c6;
    Texture2D c7;
    Texture2D c8;
    Texture2D c9;
    Texture2D c10;
    Texture2D cK;
    Texture2D cQ;
    Texture2D cJ;

    Texture2D hA;
    Texture2D h2;
    Texture2D h3;
    Texture2D h4;
    Texture2D h5;
    Texture2D h6;
    Texture2D h7;
    Texture2D h8;
    Texture2D h9;
    Texture2D h10;
    Texture2D hK;
    Texture2D hJ;
    Texture2D hQ;

    Texture2D dA;
    Texture2D d2;
    Texture2D d3;
    Texture2D d4;
    Texture2D d5;
    Texture2D d6;
    Texture2D d7;
    Texture2D d8;
    Texture2D d9;
    Texture2D d10;
    Texture2D dK;
    Texture2D dJ;
    Texture2D dQ;

    Texture2D sA;
    Texture2D s2;
    Texture2D s3;
    Texture2D s4;
    Texture2D s5;
    Texture2D s6;
    Texture2D s7;
    Texture2D s8;
    Texture2D s9;
    Texture2D s10;
    Texture2D sK;
    Texture2D sJ;
    Texture2D sQ;

    Texture2D backfaceB;
    Texture2D backfaceR;
}Cards;

struct Cards loadStructs(Cards deck);