#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>

// sleep function for AI "thinking"
// https://www.geeksforgeeks.org/sleep-function-in-c
#ifdef _WIN_32
#include <Windows.h>
#define sleep Sleep
#else
#include <unistd.h>
#endif

#include "globals.h"
#include "io.h"
#include "utils.h"

#endif
