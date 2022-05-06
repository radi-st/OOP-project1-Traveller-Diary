#pragma once
#include "string.h"
#include <iostream>

class User {
public:
	User() = default;
	User(const String& username, const String& password, const String& email);
	User(const char* username, const char* password, const char* email);
	User(const User& other); // mai nqma nujda
	
	friend std::istream& operator>>(std::istream& in, User& user);
	friend std::ostream& operator<<(std::ostream& out, const User& user);
private:
	void validate_username();

	String m_username{};
	String m_password{};
	String m_email{};
};
