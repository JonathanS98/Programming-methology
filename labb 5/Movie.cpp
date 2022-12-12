//Lab 5, DT079G
//Jonathan Shahi
//movie.cpp, 11/12/22
//Implementation of the class movie

#include "Movie.h"
#include <string>

Movies::Movies(std::string name, double rating) : name(name), rating(rating){}

bool Movies::operator==(const Movies& rhs) {
	return name == rhs.name;
}

std::string Movies::get_name() {
	return name;
}

double Movies::get_rating() {
	return rating;
}

std::string Movies::get_name() const {
	return name;
}

double Movies::get_rating() const {
	return rating;
}