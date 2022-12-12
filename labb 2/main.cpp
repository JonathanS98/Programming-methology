//Lab 2, DT079G
//Jonathan Shahi
//main.cpp, 29/11/22
//Doing some testing :D

#include "shapes.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace dif_shapes;

//using shape_ptr = std::unique_ptr<shape>;
void get_data(std::vector<shape*> area);

int main() {
	std::vector<shape*> s_vec(5,nullptr);

	//s_vec.push_back(std::make_unique<rectangle>(2, 4, "white"));
	s_vec[0] = new rectangle(2, 4, "White");
	s_vec[1] = new rounded_rectangle(rectangle(2, 4, "Black"), 2);
	s_vec[2] = new parallelepiped(rectangle(2, 3, "Yellow"), 1);
	s_vec[3] = new circle(2, "Red");
	s_vec[4] = new cylinder(2,5,"Blue");

	get_data(s_vec);

	return 0;
}

void get_data(std::vector<shape*> area) {
	float total_area = 0;
	for (auto& e : area) {
		std::cout << "The area is: " << e->get_area() << " ,and have the colour: " << e->get_colour() << "\n";
		total_area += e->get_area();
	}
	std::cout << "Total area is: " << total_area << "\n";
}
