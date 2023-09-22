#include "headers.h"

int main() {
	int bonus = 0;

	if (read_bool("All-Star Game appearance"))
		bonus += 25000;
	if (read_bool("Regular season MVP"))
		bonus += 75000;
	if (read_bool("World Series MVP"))
		bonus += 100000;
	if (read_bool("Gold Glove award"))
		bonus += 50000;
	if (read_bool("Silver Slugger award"))
		bonus += 35000;
	if (read_bool("Home run champ"))
		bonus += 25000;
	if (read_bool("Batting average champ"))
		bonus += 25000;

	printf("Season bonus: %d\n", bonus);

	return 0;
}
