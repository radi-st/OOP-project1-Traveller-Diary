#pragma once
#include "trip.h"
#include <algorithm>

class TripCollection {
public:
	TripCollection() = default;
	~TripCollection();
	Trip& operator[](unsigned index);
	Trip operator[](unsigned index) const;
	friend std::istream& operator>>(std::istream& in, TripCollection& trip_col);
	unsigned size() const;
	void add_trip(const Trip& trip);
private:
	
	void resize();
	Trip* m_data{ nullptr };
	unsigned m_size{};
	unsigned m_capacity{};
};

std::ostream& operator<<(std::ostream& out, const TripCollection& trip_col);