#pragma once
#include "string.h"
#include "date.h"

class Trip {
public:
	Trip() = default;
	friend std::istream& operator>>(std::istream& in, Trip& trip) {
		in >> trip.m_destination >> trip.m_begin_date >> trip.m_end_date >> trip.m_grade >> trip.m_comment;

	}

private:
	

	String m_destination{};
	Date m_begin_date{};
	Date m_end_date{};
	unsigned m_grade{}; // 1-5
	String m_comment{};
	String* m_photos{nullptr};
	unsigned m_number_photos;
	unsigned m_capacity_photos;
};