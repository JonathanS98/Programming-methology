//Lab 2, DT079G
//Jonathan Shahi
//shapes.h, 29/11/22
//declaration of the shapes 

#ifndef SHAPES
#define SHAPES

#include <iostream>
#include <string>

namespace dif_shapes {

	class shape {
	public:
		shape() = default;
		shape(std::string colour);
		virtual ~shape() = default;
		std::string get_colour() const;
		virtual float get_area() const = 0; // pure virtual 
	protected:
		std::string colour;
	};

	class rectangle : public shape {
	public:
		rectangle() = default;
		rectangle(float width, float height, std::string colour);
		float get_area() const override;
		float get_width() const;
		float get_height() const;
	private:
		float width;
		float height;
	};

	class rounded_rectangle : public rectangle {
	public:
		rounded_rectangle() = delete;
		rounded_rectangle(rectangle rec, float cr);
		float get_cr() const;
		float get_area() const override;
	private:
		float cr;
	};

	class parallelepiped : public rectangle {
	public:
		parallelepiped() = delete;
		parallelepiped(rectangle rec, float depth);
		parallelepiped(float width, float height, float depth, std::string colour);
		float get_depth() const;
		float get_area() const override;
	private:
		float depth;
	};

	class circle : public shape {
	public:
		circle() = default;
		circle(float radius, std::string colour);
		float get_area() const override;
	private:
		float radius;
	};

	class cylinder : public circle {
	public:
		cylinder() = delete;
		cylinder(circle c, float height);
		cylinder(float r, float height, std::string colour);
		float get_height();
		float get_area() const override;
	private:
		float height;
	};

}

#endif