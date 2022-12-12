//Lab 5, DT079G
//Jonathan Shahi
//movie.h, 11/12/22
//Declaration of the class movie

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
class Movies {
public:
	Movies(std::string name, double rating);
	bool operator==(const Movies& lhs);
	std::string get_name();
	double get_rating();
	std::string get_name() const;
	double get_rating() const;
private:
	std::string name;
	double rating;
};

#endif
