//Lab 4, DT079G
//Jonathan Shahi
//Mailbox.h, 09/12/22
//declaration of class Mailbox
#include <vector>

#ifndef MAILBOX_H
#define MAILBOX_H
#include "Email.h"

class Mailbox {
public:
	std::vector<Email> emails();
	size_t size();
	auto begin();
	auto end();
	const auto begin() const;
	const auto end() const;
	void push(const Email& inbox);
	void sortSender();
	void sortdate();
	void sortsubject();
private:
	std::vector<Email> email;
};

#endif
