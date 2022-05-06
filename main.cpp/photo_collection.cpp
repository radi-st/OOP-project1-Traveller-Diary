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
	assert(index < m_size);
	return m_data[index];
}
String PhotoCollection::operator[](unsigned index) const {
	assert(index < m_size);
	return m_data[index];
}

std::istream& operator>>(std::istream& in, PhotoCollection& photo_col) {
	String photo;
	while (in >> photo) {
		photo_col.validate_photo(photo);
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

void PhotoCollection::validate_photo(const String& photo_name) {
	unsigned len = photo_name.size();
	assert(len > 4);

	bool ends_with_png{ photo_name[len - 4] == '.' && photo_name[len - 3] == 'p'
		&& photo_name[len - 2] == 'n' && photo_name[len - 1] == 'g' };

	bool ends_with_jpeg{ photo_name[len - 5] == '.' && photo_name[len - 4] == 'j'
		&& photo_name[len - 3] == 'p' && photo_name[len - 2] == 'e' && photo_name[len - 1] == 'g' };

	bool has_valid_symbols = true;

	for (unsigned i=0; i < len; i++) {
		if (!((photo_name[i] >= 'a' && photo_name[i] <= 'z') ||
			(photo_name[i] >= 'A' && photo_name[i] <= 'Z') || photo_name[i] == '_')) {
			has_valid_symbols = false;
			break;
		}
	}
	assert((ends_with_png || ends_with_jpeg) && has_valid_symbols);
}
