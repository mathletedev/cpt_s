#include "data.hpp"

std::ifstream &operator>>(std::ifstream &lhs, data &rhs) {
	std::string tmp;

	if (!utils::read_token(lhs, tmp)) {
		// no data to extract
		lhs.setstate(std::ios::failbit);
		return lhs;
	}
	rhs.record_ = stoi(tmp);
	utils::read_token(lhs, tmp), rhs.id_ = stoi(tmp);
	utils::read_token(lhs, tmp), rhs.name_ = tmp;
	utils::read_token(lhs, tmp), rhs.email_ = tmp;
	utils::read_token(lhs, tmp), rhs.units_ = (tmp == "AU" ? 0 : stoi(tmp));
	utils::read_token(lhs, tmp), rhs.major_ = tmp;
	utils::read_token(lhs, tmp), rhs.level_ = tmp;

	rhs.num_absences_ = 0;

	return lhs;
}
