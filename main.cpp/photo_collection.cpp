#include "photo_collection.h"

void PhotoCollection::resize() {
	m_capacity = m_capacity * 2 + 1;
	String* temp = new String[m_capacity] {};
	std::copy(m_data, m_data + m_size, temp);
	delete[] m_data;
	m_data = temp;
}

PhotoCollection::~PhotoCollection() {
	delete[] m_data;
}

unsigned PhotoCollection::size() const {
	return m_size;
}

String& PhotoCollection::operator[](unsigned index) {
	return m_data[index];
}
String PhotoCollection::operator[](unsigned index) const {
	return m_data[index];
}

std::istream& operator>>(std::istream& in, PhotoCollection& photo_col) {
	String photo;
	while (in >> photo) {
		if (photo_col.m_capacity == photo_col.m_size) {
			photo_col.resize();
		}
		photo_col[photo_col.m_size++] = photo;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const PhotoCollection& photo_col) {
	for (unsigned i = 0; i < photo_col.size()-1; i++) {
		out << photo_col[i]<<" ";
	}
	out << photo_col[photo_col.size() - 1];
	return out;
}