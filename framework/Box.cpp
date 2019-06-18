#include "Box.hpp"

Box::~Box(){};

float Box::area(){
	float frontSide = (max_.z-min_.z)*(max_.y-min_.y);
	float foundationSide  = (max_.z - min_.z)*(max_.x - min_.x);
	float angleSide  = (max_.x - min_.x)*(max_.y - min_.y);

	return ((2*frontSide)*(2*foundationSide)*(2*angleSide));
}

float Box::volume(){
	return ((max_.z - min_.z)*(max_.y - min_.y)*(max_.x - min_.x));
}

glm::vec3 Box::getMin(){
	return min_;
}

glm::vec3 Box::getMax(){
	return max_;
}
