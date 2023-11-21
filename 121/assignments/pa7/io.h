#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

void wait_for_enter(void);
void clear(void);
void consume_input(void);

void warn(char *message);

#endif
