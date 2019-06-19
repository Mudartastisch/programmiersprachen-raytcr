#ifndef BOX_HPP
#define BOX_HPP

#include "Shape.hpp"
#include "color.hpp"
#include <glm/vec3.hpp>

class Box :	public Shape{
public:
	Box(): min_(0.0), max_(0.0), Shape(){};
	Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Color color): min_(min), max_(max),Shape(name, color){};
	~Box();
	float area() const override;
	float volume() const override;
	glm::vec3 getMin() const;
	glm::vec3 getMax() const;
	std::string getName() const;
	Color getColor() const;
	std::ostream& print(std::ostream & os) const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
};

std::ostream& operator<<(std::ostream& os, Box const & s);

#endif // BOX_HPP