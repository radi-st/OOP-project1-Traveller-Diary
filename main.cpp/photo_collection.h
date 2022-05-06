#pragma once
#include "string.h"
#include <algorithm>

class PhotoCollection {
public:
	PhotoCollection() = default;
	~PhotoCollection();
	String& operator[](unsigned index);
	String operator[](unsigned index) const;
	friend std::istream& operator>>(std::istream& in, PhotoCollection& photo_col);
	unsigned size() const;
private:
	void validate_photo(const String& photo_name);
	void resize();
	String* m_data{nullptr};
	unsigned m_size{};
	unsigned m_capacity{};
};

std::ostream& operator<<(std::ostream& out, const PhotoCollection& photo_col);