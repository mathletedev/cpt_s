#include "headers.h"

char *get_rand(char **arr, size_t size) { return arr[rand() % size]; }
