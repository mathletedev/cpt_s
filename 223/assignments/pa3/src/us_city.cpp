#include "us_city.hpp"

UsCity::UsCity(const std::vector<std::string> &columns) {
	lat = columns[1];
	lng = columns[2];
	city = columns[3];
	state_id = columns[4];
	state_name = columns[5];
	zcta = columns[6];
	parent_zcta = columns[7];
	population = columns[8];
	density = columns[9];
	county_fips = columns[10];
	county_name = columns[11];
	county_weights = columns[12];
	county_names_all = columns[13];
	county_fips_all = columns[14];
	imprecise = columns[15];
	military = columns[16];
	timezone = columns[17];
}
