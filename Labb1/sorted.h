//Lab 1, DT079G
//Jonathan Shahi
//28/11/22
//Declaration of int_sorted header

#ifndef sorted
#define sorted

#include "buffer.h"

class int_sorted {
public:

	int_sorted(const int* source, size_t size);

	size_t size() const;

	void insert(int value);

	const int* begin() const;

	const int* end() const;

	int_sorted merge(const int_sorted& merge_with) const;

	int_sorted sort(const int* begin, const	int* end);

private:

	int_buffer buf;
};

void selectionsort(int* begin, int* end);

#endif