#include "trip_collection.h"

void TripCollection::resize() {
	m_capacity = m_capacity * 2 + 1;
	Trip* temp = new Trip[m_capacity]{};
	std::copy(m_data, m_data + m_size, temp);
	delete[] m_data;
	m_data = temp;
}

TripCollection::~TripCollection() {
	delete[] m_data;
}

unsigned TripCollection::size() const {
	return m_size;
}

TripCollection::TripCollection(const TripCollection& other) :
	m_capacity(other.m_capacity),
	m_data(new Trip[m_capacity]),
	m_size(other.m_size)
{
	std::copy(other.m_data, other.m_data + other.m_size, m_data);
}
TripCollection& TripCollection::operator=(const TripCollection& other) {
	TripCollection temp{ other };
	swap(temp);
	return *this;
}

void TripCollection::swap(TripCollection& other) {
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_size, other.m_size);
	std::swap(m_data, other.m_data);
}

Trip& TripCollection::operator[](unsigned index) {
	assert(index < m_size);
	return m_data[index];
}
const Trip& TripCollection::operator[](unsigned index) const {
	assert(index < m_size);
	return m_data[index];
}

std::istream& operator>>(std::istream& in, TripCollection& trip_col) {
	int begin_pos = in.tellg();
	in.seekg(0, std::ios::end);
	if (in.tellg() != begin_pos) {
		in.seekg(0, std::ios::beg);
		while (in) {
			Trip trip;
			in >> trip;
			trip_col.add_trip(trip);
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const TripCollection& trip_col) {
	for (unsigned i = 0; i < trip_col.size() - 1; i++) {
		out << trip_col[i] << '\n';
	}
	out << trip_col[trip_col.size() - 1];
	return out;
}


void TripCollection::add_trip(const Trip& trip) {
	if (m_capacity == m_size) {
		resize();
	}
	m_data[m_size++] = trip;
}

