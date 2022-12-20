//Lab 4, DT079G
//Jonathan Shahi
//source.cpp, 09/12/22
//Runing some tests

#include <iostream>
#include "Mailbox.h"

template<typename T>
void preview(const std::vector<T>& elements) {
	for (auto e : elements) {
		std::cout << e;
	}
}

int main() {
	Mailbox em;

	em.push(Email("Jonathan", "2022-12-08", "Computer Science"));
	em.push(Email("Jonathan", "2022-12-08", "Computer Engineering"));
	em.push(Email("Alice", "2022-12-07", "Computer Science"));
	em.push(Email("Rey", "2021-09-21", "Backup dancer"));
	em.push(Email("Franco", "2022-12-08", "Computer Engineering"));
	em.push(Email("Micheal", "2018-02-04", "lawyer"));

	em.sortdate();
	preview(em.emails());
	return 0;
}