#ifndef BOX_HPP
#define BOX_HPP

#include "Shape.hpp"
#include "color.hpp"
#include <glm/vec3.hpp>

class Box :	public Shape{
public:
	Box(): min_(0.0), max_(0.0), name_("default"), color_(0.0,0.0,0.0){};
	Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Color color): min_(min), max_(max),name_(name), color_(color){};
	~Box();
	float area() override;
	float volume() override;
	glm::vec3 getMin();
	glm::vec3 getMax();
	std::string getName();
	Color getColor();
private:
	glm::vec3 min_;
	glm::vec3 max_;
	std::string name_;
    Color color_;
};

#endif // BOX_HPP