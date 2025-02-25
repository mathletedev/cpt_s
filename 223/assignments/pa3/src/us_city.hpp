#pragma once

#include <string>
#include <vector>
class UsCity {
	public:
		std::string lat, lng, city, state_id, state_name, zcta,
		    parent_zcta, population, density, county_fips, county_name,
		    county_weights, county_names_all, county_fips_all,
		    imprecise, military, timezone;

		UsCity(const std::vector<std::string> &columns);
};
