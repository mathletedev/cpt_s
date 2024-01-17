#include "headers.h"

int main(void) {
	FILE *data = fopen("FitbitData.csv", "r");
	if (!data) {
		puts("Failed to open FitbitData.csv");
		return 1;
	}

	fclose(data);
	return 0;
}
