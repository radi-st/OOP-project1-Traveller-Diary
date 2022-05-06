#include "trip.h"

void Trip::validate_time_period() {
	assert(m_begin_date < m_end_date);
}
void Trip::validate_grade() {
	assert(m_grade >= 1 && m_grade <= 5);
}
void Trip::validate_photo(const String& photo_name) {
	unsigned len = photo_name.size();
	assert(len > 4);

	bool ends_with_png{ photo_name[len - 4] == '.' && photo_name[len - 3] == 'p'
		&& photo_name[len - 2] == 'n' && photo_name[len - 1] == 'g' };

	bool ends_with_jpeg{ photo_name[len - 5] == '.' && photo_name[len - 4] == 'j'
		&& photo_name[len - 3] == 'p' && photo_name[len - 2] == 'e' && photo_name[len - 1] == 'g' };

	bool has_valid_symbols = true;

	for (unsigned i; i < len; i++) {
		if (!((photo_name[i] >= 'a' && photo_name[i] <= 'z') ||
			(photo_name[i] >= 'A' && photo_name[i] <= 'Z') || photo_name[i] == '_')) {
			has_valid_symbols = false;
			break;
		}
	}
	assert((ends_with_png || ends_with_jpeg) && has_valid_symbols);
}

std::istream& operator>>(std::istream& in, Trip& trip) {
	in >> trip.m_destination >> trip.m_begin_date >> trip.m_end_date >> trip.m_grade >> trip.m_comment >> trip.photos;
}

