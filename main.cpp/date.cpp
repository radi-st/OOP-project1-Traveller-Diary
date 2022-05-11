#include "date.h"

bool Date::is_valid() {
	return (m_year>1900 && m_year<2023) && (m_month > 0 && m_month <= 12) && (m_day > 0 && m_day <= 31);
}
Date::Date(unsigned year, unsigned month, unsigned day) : 
	m_year(year), m_month(month), m_day(day) {
	assert(is_valid() && "The date is invalid");
}

std::istream& operator>>(std::istream& in, Date& date) {
	//1989-07-09
	char year[5];
	char month[3];
	char day[3];
	in.getline(year,5,'-');
	in.getline(month,3, '-');
	in.getline(day, 3,' ');

	date.m_year = atoi(year);
	date.m_month = atoi(month);
	date.m_day = atoi(day);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
	return out << date.year()<< "-"<<date.month()<<"-"<<date.day();
}

unsigned Date::year() const {
	return m_year;
}
unsigned Date::month() const {
	return m_month;
}
unsigned Date::day() const{
	return m_day;
}

void Date::swap(Date& other) {
	std::swap(m_year, other.m_year);
	std::swap(m_month, other.m_month);
	std::swap(m_day, other.m_day);
}

bool operator< (const Date& lhs, const Date& rhs) {
	if (lhs.year() < rhs.year())
		return true;
	if (lhs.year() == rhs.year()) {
		if (lhs.month() < rhs.month())
			return true;
		if (lhs.month() == rhs.month()) {
			return lhs.day() < rhs.day();
		}
		return false;
	}
	return false;
}