#include "Box.hpp"

Box::~Box(){};

float Box::area() const{
	float frontSide = (max_.z-min_.z)*(max_.y-min_.y);
	float foundationSide  = (max_.z - min_.z)*(max_.x - min_.x);
	float angleSide  = (max_.x - min_.x)*(max_.y - min_.y);

	return ((2*frontSide)*(2*foundationSide)*(2*angleSide));
}

float Box::volume() const{
	return ((max_.z - min_.z)*(max_.y - min_.y)*(max_.x - min_.x));
}

glm::vec3 Box::getMin() const{
	return min_;
}

glm::vec3 Box::getMax()const {
	return max_;
}

std::string Box::getName() const{
	return name_;
}

Color Box::getColor() const{
	return color_;
}

std::ostream& Box::print(std::ostream & os) const{
    Shape::print(os) << "Min: " << min_.x << " " << min_.y << " " << min_.z << " " <<  "Max: " << max_.x << " " << max_.y << " " <<  max_.z << " " << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, Box const & s){
    s.print(os);
};