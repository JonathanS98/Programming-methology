//Lab 1, DT079G
//Jonathan Shahi
//28/11/22
//implementation of int_sorted

#include "sorted.h"
#include <iostream>
#include <algorithm>

int_sorted::int_sorted(const int* source, size_t size): buf(source, size) {
	if (size > 1) {
		buf = sort(source, source + size).buf;
	}
}

size_t int_sorted::size() const {
	return buf.size();
}

void int_sorted::insert(int value) {
	buf = merge(int_sorted(&value, 1)).buf;
}

const int* int_sorted::begin() const {
	return buf.begin();
}

const int* int_sorted::end() const {
	return buf.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const {
	int_buffer c(size() + merge_with.size());
	const int* A_ptr = begin();
	const int* B_ptr = merge_with.begin();
	int a, b, i = 0;
	while (A_ptr != end() && B_ptr != merge_with.end()) {
		a = *A_ptr;
		b = *B_ptr;
		if (a < b) {
			c[i++] = *A_ptr;
			A_ptr++;
		}
		else {
			c[i++] = *B_ptr;
			B_ptr++;
		}
	}
	while (A_ptr != end()) {
		c[i++] = *A_ptr;
		a = *++A_ptr;
	}
	while (B_ptr != merge_with.end()) {
		c[i++] = *B_ptr;
		b = *++B_ptr;
	}
	int_sorted merged(nullptr, 0);
	merged.buf = c;
	return merged;
}

int_sorted int_sorted::sort(const int* begin, const	int* end) {
	if (begin == end) {
		return int_sorted(nullptr, 0);
	}
	if (begin == end - 1) {
		return int_sorted(begin, 1);
	}

	ptrdiff_t half = (end - begin) / 2; //pointer diff type
	const int* mid = begin + half;
	return sort(begin, mid).merge(sort(mid, end));
}

void selectionsort(int* begin, int* end) {
	int_buffer s(begin, end - begin);
	int* tempptr;
	int index = 0;
	for (int* i = begin; i != end; i++) {
		tempptr = i;
		for (int* j = i + 1; j != end; j++) {
			if (*j < *tempptr) {
				tempptr = j;
			}
		}
		if (tempptr != i) {
			std::swap(*tempptr, *i);
		}
	}
}
