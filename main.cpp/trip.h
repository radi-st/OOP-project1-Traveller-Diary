#pragma once
#include "string.h"
#include "date.h"
#include <cassert>
#include "photo_collection.h"

class Trip {
public:
	Trip() = default;
	friend std::istream& operator>>(std::istream& in, Trip& trip);

private:
	void validate_time_period();
	void validate_grade();
	void validate_photo(const String& photo_name);

	String m_destination{};
	Date m_begin_date{};
	Date m_end_date{};
	unsigned m_grade{}; // 1-5
	String m_comment{};
	PhotoCollection photos;
};