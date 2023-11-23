#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "types.h"

void wait_for_enter(void);
void clear(void);
void consume_input(void);

void warn(char *message);

void write_hand(Hand *hand, int visible, int show_ids);

#endif
