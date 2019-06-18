#ifndef BOX_HPP
#define BOX_HPP

#include "Shape.hpp"
#include <glm/vec3.hpp>

class Box :	public Shape{
public:
	Box(): min_(0.0), max_(0.0){};
	Box(glm::vec3 const& min, glm::vec3 const& max): min_(min), max_(max){};
	~Box();
	float area() override;
	float volume() override;
	glm::vec3 getMin();
	glm::vec3 getMax();
private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif // BOX_HPP