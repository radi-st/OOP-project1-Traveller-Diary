#pragma once
#include "trip.h"
#include <algorithm>

class TripCollection {
public:
	TripCollection() = default;
	TripCollection(const TripCollection& other);
	TripCollection& operator=(const TripCollection& other);
	~TripCollection();
	Trip& operator[](unsigned index);
	const Trip& operator[](unsigned index) const;
	friend std::istream& operator>>(std::istream& in, TripCollection& trip_col);
	unsigned size() const;
	void add_trip(const Trip& trip);
	void swap(TripCollection& other);
private:
	
	void resize();
	unsigned m_capacity{};
	Trip* m_data{ nullptr };
	unsigned m_size{};
};

std::ostream& operator<<(std::ostream& out, const TripCollection& trip_col);