#pragma once
#include "string.h"
#include "date.h"
#include <cassert>
#include "photo_collection.h"

class Trip {
public:
	Trip() = default;
	Trip(const Trip& other);
	Trip& operator=(const Trip& other);
	friend std::istream& operator>>(std::istream& in, Trip& trip);
	friend std::ostream& operator<<(std::ostream& out, const Trip& trip);
	String destination() const;

private:
	void validate_time_period();
	void validate_grade();
	void swap(Trip& other);

	String m_destination{};
	Date m_begin_date{};
	Date m_end_date{};
	unsigned m_grade{}; // 1-5
	String m_comment{};
	PhotoCollection m_photos;
};