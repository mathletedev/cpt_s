#include "data.hpp"

// reads data from fstream, returns true if successful
bool data::read(std::ifstream &fstream, bool const &include_dates) {
	std::string tmp;

	// no data to extract
	if (!utils::read_token(fstream, tmp)) return false;

	record_ = stoi(tmp);
	utils::read_token(fstream, tmp), id_ = stoi(tmp);
	utils::read_token(fstream, tmp), name_ = tmp;
	utils::read_token(fstream, tmp), email_ = tmp;
	utils::read_token(fstream, tmp), units_ = (tmp == "AU" ? 0 : stoi(tmp));
	utils::read_token(fstream, tmp), major_ = tmp;
	utils::read_token(fstream, tmp), level_ = tmp;

	// whether or not to include absences data
	if (!include_dates) {
		num_absences_ = 0;
		return true;
	}

	utils::read_token(fstream, tmp), num_absences_ = stoi(tmp);

	dates_absences_.read(fstream, num_absences_);

	// ignore comma
	fstream.ignore();

	return true;
}

// writes data to a filestream in csv format
void data::write(std::ofstream &fstream) const {
	fstream << record_ << ",";
	fstream << id_ << ",";
	fstream << utils::format_token(name_) << ",";
	fstream << utils::format_token(email_) << ",";
	fstream << (units_ == 0 ? "AU" : std::to_string(units_)) << ",";
	fstream << utils::format_token(major_) << ",";
	fstream << utils::format_token(level_) << ",";
	fstream << num_absences_ << ",";

	dates_absences_.write(fstream);
}
