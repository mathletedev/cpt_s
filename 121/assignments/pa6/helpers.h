#ifndef HELPERS_H
#define HELPERS_H

#include "globals.h"

int ship_to_int(char ship);
char *ship_to_name(char ship);

int check_shot(Coordinates target, Board board);

#endif
