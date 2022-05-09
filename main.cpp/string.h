#pragma once
#pragma warning(disable:4996)
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
class String {
public:
	String() = default;
	String(const char* other);
	String(const String& other);
	String& operator=(const String& other);
	~String();
	friend std::istream& operator>>(std::istream& in,String& str);
	const char& operator[](unsigned index) const;
	char& operator[](unsigned index);
	friend String& operator+(const String& lhs,const String& rhs);
	void concat_char(char c);
	unsigned size() const;
	const char* data() const;
	friend std::istream& getline(std::istream& in, String& str, char delim='\n');
	void swap(String& other);
private:
	
	void resize();

	char* m_data{ nullptr };
	unsigned m_size{ 0 };
	unsigned m_capacity{ 0 };
};
bool operator == (const String& lhs, const String& rhs);
std::ostream& operator<<(std::ostream& out, const String& str);