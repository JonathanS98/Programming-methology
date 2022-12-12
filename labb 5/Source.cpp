//Lab 5, DT079G
//Jonathan Shahi
//source.cpp, 11/12/22
//Testing with some algorithms

#include "Movie.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>


struct MyPrint {
	auto operator()(const Movies& p) const {
		std::cout << p.get_name() << ": " << p.get_rating() << "\n";
	}
};

struct is_greater {
private:
	double rating;
public:
	is_greater(double rating) : rating(rating) {};
	auto operator()(const Movies& lhs) const {
		return lhs.get_rating() >= rating;
	}
};

struct My_bin_op {
	size_t sz;
	My_bin_op(size_t sz) : sz(sz) {};
	auto operator()(double i, const Movies& m){
		return i += m.get_rating() / sz;
	}
};

struct My_un_op {
	auto operator()(const Movies& m) const {
		return m.get_rating() - 0.2;
	}
};

struct My_func {
	double mean;
	My_func(double mean): mean(mean){}
	auto operator()(const double& rating) const {
		return rating - mean;
	}
};

struct ascending_order {
	auto operator()(const double& a, const double& b) { 
		return a < b;
	}
};

int main() {
	std::array<Movies, 10> Movie_list = {
		Movies("The Shawshank Redemption", 9.2),
		Movies("The Godfather", 9.2),
		Movies("12 Angry Men", 9.0),
		Movies("Sharknado", 3.3),
		Movies("Pulp Fiction", 8.8),
		Movies("Forrest Gump", 8.8),
		Movies("Interstellar", 8.6),
		Movies("Inception", 8.7),
		Movies("The Aviator", 7.5),
		Movies("The Aviator", 5.5),
	};

	std::vector<Movies> mov(Movie_list.begin(), Movie_list.end());

	/*-----------------------(1)FOR_EACH---------------------------*/
	MyPrint mp;
	std::for_each(mov.begin(), mov.end(), mp);
	std::cout << "--------------------------------------\n";
	/*-----------------------(2)FIND_IF---------------------------*/
	is_greater greater(8);
	auto find_greater = std::find_if(mov.begin(), mov.end(), greater);
	mp(*find_greater);
	std::cout << "--------------------------------------\n";
	/*-----------------------(3)Adjacent_find---------------------------*/
	auto Twins = std::adjacent_find(mov.begin(), mov.end());
	mp(*Twins);
	std::cout << "--------------------------------------\n";
	/*-----------------------(4)Equal---------------------------*/
	auto equal = std::equal(Movie_list.begin(), Movie_list.end(), mov.begin(), mov.end());
	if (equal) {
		std::cout << "Equal\n";
	}
	else if (!equal) {
		std::cout << "Not Equal\n";
	}
	std::cout << "--------------------------------------\n";
	/*-----------------------(5)Search---------------------------*/
	auto finding = std::search(Movie_list.begin(), Movie_list.end(), mov.begin(), mov.end());
	if (finding != Movie_list.end()) {
		std::cout << "vector 'mov' is present at index " << (finding - Movie_list.begin()) << "\n";
	}
	else {
		std::cout << "Vector 'mov' is not present in Movie_list\n";
	}
	std::cout << "--------------------------------------\n";
	/*-----------------------(6)Average---------------------------*/
	My_bin_op mbo(mov.size());
	auto mean = std::accumulate(mov.begin(), mov.end(), double(), mbo);
	std::cout << "The average rating is: " << mean << "\n";
	std::cout << "--------------------------------------\n";
	/*-----------------------(7)Transform---------------------------*/
	std::vector<double> v2(mov.size());
	My_un_op muo;
	std::transform(mov.begin(), mov.end(), v2.begin(), muo);
	for (auto e : v2) {
		std::cout << e << "\n";
	}
	std::cout << "--------------------------------------\n";
	/*-----------------------(8)Transform---------------------------*/
	My_func func(mean);
	std::transform(v2.begin(), v2.end(), v2.begin(), func);
	for (auto e : v2) {
		std::cout << e << "\n";
	}
	std::cout << "--------------------------------------\n";
	/*-----------------------(9)sort---------------------------*/
	ascending_order ao;
	std::sort(v2.begin(), v2.end(), ao);
	for (auto e : v2) {
		std::cout << e << "\n";
	}
}