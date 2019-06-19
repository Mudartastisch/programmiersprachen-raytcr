#include "Sphere.hpp"
#include <math.h>
#define _USE_MATH_DEFINES

Sphere::~Sphere(){};

float Sphere::area() const{
    return (4 * M_PI * (radius_ * radius_));
}

float Sphere::volume() const{
    return ((4/3) * M_PI * (radius_ * radius_ * radius_));
}

glm::vec3 Sphere::getCenter() const{
    return center_;
}

float Sphere::getRadius() const{
    return radius_;
}

std::string Sphere::getName() const{
	return name_;
}

Color Sphere::getColor() const{
	return color_;
}

std::ostream& Sphere::print(std::ostream & os) const {
    Shape::print(os) << "Center: " << center_.x << " " << center_.y << " " << center_.z << " " << "Radius: " << radius_ << " " << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, Sphere const & s){
    s.print(os);
};