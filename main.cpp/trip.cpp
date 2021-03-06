#include "trip.h"

void Trip::validate_time_period() {
	assert(m_begin_date < m_end_date);
}
void Trip::validate_grade() {
	assert(m_grade >= 1 && m_grade <= 5);
}
String Trip::destination()const {
	return m_destination;
}
unsigned Trip::grade() const {
	return m_grade;
}
std::istream& operator>>(std::istream& in, Trip& trip) {
	in >> trip.m_destination >> trip.m_begin_date >> trip.m_end_date;
	trip.validate_time_period();
	in >> trip.m_grade;
	trip.validate_grade();
	in.ignore();
	getline(in, trip.m_comment); 
	in>> trip.m_photos;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Trip& trip) {
	out << trip.m_destination << " " << trip.m_begin_date << " " << trip.m_end_date <<" "<<trip.m_grade<<'\n';
	out << trip.m_comment << '\n';
	out << trip.m_photos << '\n';
	return out;
}
std::ostream& output_without_dest(std::ostream& out, const Trip& trip) {
	out <<'\n'<< trip.m_begin_date << " " << trip.m_end_date;
	out<<"\nGrade:" << trip.m_grade << '\n';
	out << trip.m_comment << '\n';
	out << trip.m_photos << '\n';
	return out;
}

Trip::Trip(const Trip& other) :
	m_destination(other.m_destination), m_begin_date(other.m_begin_date), m_end_date(other.m_end_date),
	m_grade(other.m_grade), m_comment(other.m_comment), m_photos(other.m_photos) {}

Trip& Trip::operator=(const Trip& other) {
	Trip temp{ other };
	swap(temp);
	return *this;
}

void Trip::swap(Trip& other) {
	m_destination.swap(other.m_destination);
	m_begin_date.swap(other.m_begin_date);
	m_end_date.swap(other.m_end_date);
	std::swap(m_grade, other.m_grade);
	m_comment.swap(other.m_comment);
	m_photos.swap(other.m_photos);
}
