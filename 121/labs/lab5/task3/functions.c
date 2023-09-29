#include "headers.h"

int read_int(FILE *infile) {
	int data;
	fscanf(infile, "%d", &data);

	return data;
}

int gcd_for(int a, int b) {
	for (int tmp = a % b; tmp != 0; tmp = a % b) {
		a = b;
		b = tmp;
	}

	return b;
}

int gcd_while(int a, int b) {
	int tmp = a % b;
	while (tmp != 0) {
		a = b;
		b = tmp;
		tmp = a % b;
	}

	return b;
}
