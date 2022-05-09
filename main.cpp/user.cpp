#include "user.h"

User::User(const String& username, const String& password, const String& email) : 
	m_username(username), m_password(password), m_email(email) {
	validate_username();
}

User::User(const char* username, const char* password, const char* email):
	m_username(username), m_password(password), m_email(email) {
	validate_username();
}

User::User(const User& other): 
	m_username(other.m_username),
	m_password(other.m_password),
	m_email(other.m_email) {}

String User::username() const {
	return m_username;
}
String User::password() const {
	return m_password;
}
String User::email() const {
	return m_email;
}


std::istream& operator>>(std::istream& in, User& user) {
	in >> user.m_username;
	user.validate_username();
	in >> user.m_password;
	in >> user.m_email;
	in >> user.m_trips;///////
	return in;
}

std::ostream& operator<<(std::ostream& out, const User& user) {
	out << user.m_username<<" "<< user.m_password<<" "<< user.m_email<<'\n';
	out << user.m_trips;
	return out;
}

void User::validate_username() {
	bool valid_username{ true };
	for (unsigned i = 0; i < m_username.size(); i++) {
		if (!((m_username[i] >= 'a' && m_username[i] <= 'z') ||
			(m_username[i] >= 'A' && m_username[i] <= 'Z') ||
			(m_username[i] >= '0' && m_username[i] <= '9')))
		{
			valid_username = false;
			break;
		}
		
	}
	assert(valid_username && "Username is invalid!");
}