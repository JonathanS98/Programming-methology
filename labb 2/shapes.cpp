//Lab 2, DT079G
//Jonathan Shahi
//shapes.cpp ,29/11/22
//implementing the shapes

#include "shapes.h"
#define PI 3.14159265359

using namespace dif_shapes;

/*------------------------------------------------------------------*/
shape::shape(std::string colour): colour(colour) {
	
}

std::string shape::get_colour() const {
	return colour;
}
/*------------------------------------------------------------------*/
rectangle::rectangle(float width, float height, std::string colour)
	: width(width), height(height), shape(colour) {

}

float rectangle::get_height() const {
	return height;
}

float rectangle::get_width() const {
	return width;
}

float rectangle::get_area() const {
	return width * height;
}
/*------------------------------------------------------------------*/
rounded_rectangle::rounded_rectangle(rectangle rec, float cr)
	: rectangle(rec), cr(cr) {

}

float rounded_rectangle::get_cr() const {
	return cr;
}

float rounded_rectangle::get_area() const {
	const float r_area = rectangle::get_area() - pow(cr, 2) * (4 - PI);
	return r_area;
}
/*------------------------------------------------------------------*/
parallelepiped::parallelepiped(rectangle rec, float depth) 
	: rectangle(rec), depth(depth) {
}

parallelepiped::parallelepiped(float width, float height, float depth, std::string colour)
	: rectangle(width, height, colour), depth(depth) {

}

float parallelepiped::get_depth() const {
	return depth;
}

float parallelepiped::get_area() const {
	return rectangle::get_area() * depth;
}
/*------------------------------------------------------------------*/
circle::circle(float radius, std::string colour)
	: radius(radius), shape(colour) {

}

float circle::get_area() const {
	float c_area = PI * pow(radius, 2);
	return c_area;
}
/*------------------------------------------------------------------*/
cylinder::cylinder(circle c, float height) 
	: circle(c), height(height) {
}

cylinder::cylinder(float r, float height, std::string colour)
	: circle(r, colour), height(height) {

}

float cylinder::get_height() {
	return height;
}

float cylinder::get_area() const {
	return circle::get_area() * height;
}