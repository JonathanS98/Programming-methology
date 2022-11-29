//Lab 1, DT079G
//Jonathan Shahi
//28/11/22

#include <iostream>
#include "Buffer.h"
#include "sorted.h"
#include <chrono>
#include <algorithm>
#include <ctime>

void f(int_buffer buf);
void f_auto(int_buffer buf);
void print(int_sorted s);
void go_on();
void sort_insert(int_sorted& buf);
bool is_sorted(int_sorted& s);


int main() {
	/*---------------------------------------------------------------------*/
	f(int_buffer(10));
	go_on();
	/*---------------------------------------------------------------------*/
	f_auto(int_buffer(10));
	go_on();
	/*-----------------------using insert---------------------------*/
	int_sorted buf(nullptr, 0);
	sort_insert(buf);
	go_on();
	/*-----------------------sort 40000 elements---------------------------*/
	int_buffer buf1(40000);
	for (auto& e : buf1) {
		e = rand() % 39999 + 1;
	}

	int_buffer buf2 = buf1;
	int_sorted buffer(buf1.begin(), buf1.size());
	int_sorted buffer2 = buffer;
	std::cout << "40000 elements using merge sort: " << std::endl;
	auto start1 = std::chrono::steady_clock::now();
	int_sorted mergebuf = buffer.sort(buffer.begin(), buffer.end());
	auto end1 = std::chrono::steady_clock::now();
	std::chrono::duration<double> merge_elapsed_seconds = end1 - start1;
	print(mergebuf);
	std::cout << "\nelapsed time: " << merge_elapsed_seconds.count() << "s\n\n";
	go_on();
	/*-----------------------std::sort() 40000 elements---------------------------*/
	std::cout << "40000 elements using std::sort: " << std::endl;
	auto start2 = std::chrono::steady_clock::now();
	std::sort(buf1.begin(), buf1.end());
	auto end2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> sort_elapsed_seconds = end2 - start2;
	for (auto& e : buf1) {
		std::cout << e << "\n";
	}
	std::cout << "\nelapsed time: " << sort_elapsed_seconds.count() << "s\n\n";
	go_on();
	/*-----------------------selectionsort 40000 elements---------------------------*/
	std::cout << "40000 elements using selection sort: " << std::endl;
	auto start3 = std::chrono::steady_clock::now();
	selectionsort(buf2.begin(), buf2.end());
	auto end3 = std::chrono::steady_clock::now();
	std::chrono::duration<double> select_elapsed_seconds = end3 - start3;
	for (auto& e : buf2) {
		std::cout << e << "\n";
	}
	std::cout << "\nelapsed time: " << select_elapsed_seconds.count() << "s\n\n";
	go_on();
	/*---------------------------------------------------------------------*/
	std::cout << "End of tests :D" << "\n";

	return 0;
}

void f(int_buffer buf) {


	int count = 1;
	for (int* i = buf.begin(); i != buf.end(); i++) {
		*i = count++;
	}
	for (const int* i = buf.begin(); i != buf.end(); i++) {
		std::cout << *i << "\n";
	}
}

void f_auto(int_buffer buf) {
	int count = 1;
	for (auto& e : buf) {
		e = count++;
	}
	for (auto& e : buf) {
		std::cout << e << "\n";
	}
}

void sort_insert(int_sorted& buf) {
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		buf.insert(rand() % 9999 + 1);
	}
	is_sorted(buf);
}

void print(int_sorted s) {
	for (auto& e : s) {
		std::cout << e << "\n";
	}
}

void go_on() {
	std::cout << "Press Enter To Continue";
	std::cin.get();
}

bool is_sorted(int_sorted& s) {
	const int* a = s.begin();
	const int* b = s.begin() + 1;
	while (a != s.end()) {
		b++;
		if (a > b) {
			std::cout << "not sorted" << "\n";
			return false;
		}
		a = b;
	}
	std::cout << "sorted" << "\n";
	return true;
}
