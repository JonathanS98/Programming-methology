//Lab 4, DT079G
//Jonathan Shahi
//Mailbox.cpp, 09/12/22
// Implementation of class Mailbox

#include "Mailbox.h"
#include <algorithm>

std::vector<Email> Mailbox::emails() {
	return email;
}

size_t Mailbox::size() {
	return email.size();
}

auto Mailbox::begin() {
	return email.begin();
}

auto Mailbox::end() {
	return email.end();
}

const auto Mailbox::begin() const {
	return email.begin();
}

const auto Mailbox::end() const {
	return email.end();
}

void Mailbox::push(const Email& inbox) {
	email.push_back(inbox);
}

void Mailbox::sortSender() {
	std::sort(email.begin(), email.end(), CompAuthorDateSubject());
}

void Mailbox::sortdate() {
	std::sort(email.begin(), email.end(), CompDateAuthorSubject());
}

void Mailbox::sortsubject() {
	std::sort(email.begin(), email.end(), CompSubjectAuthorDate());
}