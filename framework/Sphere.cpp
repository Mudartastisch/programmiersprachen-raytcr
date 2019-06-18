#include "Sphere.hpp"
#include <math.h>
#define _USE_MATH_DEFINES

Sphere::~Sphere(){};

float Sphere::area(){
    return (4 * M_PI * (radius_ * radius_));
}

float Sphere::volume(){
    return ((4/3) * M_PI * (radius_ * radius_ * radius_));
}

glm::vec3 Sphere::getCenter(){
    return center_;
}

float Sphere::getRadius(){
    return radius_;
}

std::string Sphere::getName(){
	return name_;
}

Color Sphere::getColor(){
	return color_;
}