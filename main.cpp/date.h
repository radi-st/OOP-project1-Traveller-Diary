#pragma once
#include <iostream>
#include <cassert>
class Date {
public:
	Date() = default;
	Date(unsigned year, unsigned month, unsigned day);
	unsigned year() const;
	unsigned month() const;
	unsigned day() const;
	friend std::istream& operator>>(std::istream& in, Date& date);
	void swap(Date& other);
private:
	bool is_valid();
	unsigned m_year{};
	unsigned m_month{};
	unsigned m_day{};
};

bool operator< (const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& out, const Date& date);