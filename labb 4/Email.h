//Lab 4, DT079G
//Jonathan Shahi
//Email.h, 09/12/22
// Implementation of class Email

#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <iostream>

class Email {
public:
	Email(std::string sender, std::string date, std::string subject)
		: sender(sender), date(date), subject(subject){}

	friend std::ostream& operator<<(std::ostream& out, const Email& email) {
		return out << email.sender << ", " << email.date << ", " <<
			email.subject << "\n";
	}
	
	friend struct CompDateAuthorSubject;
	friend struct CompAuthorDateSubject;
	friend struct CompSubjectAuthorDate;

private:
	std::string sender;
	std::string date;
	std::string subject;
};

struct CompDateAuthorSubject {
	auto operator()(const Email& lhs, const Email& rhs) {
		if (lhs.date != rhs.date) {
			return lhs.date < rhs.date;
		}
		if (lhs.sender != rhs.sender) {
			return lhs.sender < rhs.sender;
		}
		return lhs.subject < rhs.subject;
	}
};

struct CompAuthorDateSubject {
	auto operator()(const Email& lhs, const Email& rhs) {
		if (lhs.sender != rhs.sender) {
			return lhs.sender < rhs.sender;
		}
		if (lhs.date != rhs.date) {
			return lhs.date < rhs.date;
		}
		return lhs.subject < rhs.subject;
	}
};

struct CompSubjectAuthorDate {
	auto operator()(const Email& lhs, const Email& rhs) {
		if (lhs.subject != rhs.subject) {
			return lhs.subject < rhs.subject;
		}
		if (lhs.sender != rhs.sender) {
			return lhs.sender < rhs.sender;
		}
		return lhs.date < rhs.date;
	}
};

#endif
