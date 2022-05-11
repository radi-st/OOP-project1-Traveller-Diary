#pragma once
#include "string.h"
#include <algorithm>

class PhotoCollection {
public:
	PhotoCollection() = default;
	PhotoCollection(const PhotoCollection& other);
	PhotoCollection& operator=(const PhotoCollection& other);
	~PhotoCollection();
	String& operator[](unsigned index);
	const String& operator[](unsigned index) const;
	friend std::istream& operator>>(std::istream& in, PhotoCollection& photo_col);
	unsigned size() const;
	void swap(PhotoCollection& other);
private:
	void validate_photo(const String& photo_name) const;
	void resize();
	unsigned m_capacity{};
	String* m_data{nullptr};
	unsigned m_size{};
};

std::ostream& operator<<(std::ostream& out, const PhotoCollection& photo_col);