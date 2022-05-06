#include "string.h"

String::String(const char* other){
	int len = std::strlen(other);
	m_data = new char[len+1];
	m_size = len;
	m_capacity = len;
	strcpy(m_data, other);
}

void String::swap(String& other) {
	std::swap(m_data, other.m_data);
	std::swap(m_size, other.m_size);
	std::swap(m_capacity, other.m_capacity);
}

String::String(const String& other) {
	m_data = new char[other.m_capacity];
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	strcpy(m_data, other.m_data);
}

String& String::operator=(const String& other) {
	String temp{ other };
	swap(temp);
	return *this;
}

void String::resize() {
	m_capacity = m_capacity * 2 + 2;
	char* temp = new char[m_capacity] {};
	if (m_data != nullptr) {
		std::strcpy(temp, m_data);
	}
	delete[] m_data;
	m_data = temp;
}

void String::concat_char(char c) {
	if (m_size + 1 >= m_capacity) {
		resize();
	}
	m_data[m_size++] = c;
}

std::istream& getline(std::istream& in, String& str, char delim) {
	char c;
	while (in.get(c) && c != delim && c!='\n') {
		str.concat_char(c);
	}
	return in;
}

std::istream& operator>>(std::istream& in, String& str) {
	return getline(in, str, ' ');
}

std::ostream& operator<<(std::ostream& out, const String& str) {
	out << str.data();
	return out;
}

const char& String::operator[](unsigned index) const {
	assert(index < m_size);
	return m_data[index];
}
char& String::operator[](unsigned index) {
	assert(index < m_size);
	return m_data[index];
}

String::~String() {
	delete[] m_data;
}

unsigned String::size() const {
	return m_size;
}

const char* String::data() const {
	return m_data;
}