#include "Sphere.hpp"
#include <math.h>
#include <numeric>
#include <glm/gtx/intersect.hpp>
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

hitPoint Sphere::intersect(Ray ray_) const
{
    //https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection

	float distance{ 0.0 };
	if(glm::intersectRaySphere(ray_.origin_, glm::normalize(ray_.direction_), getCenter(), getRadius()*getRadius(), distance)){
        glm::vec3 L(ray_.origin_ - center_);
        int a[] = { L.x, L.y, L.z };
        int b[] = { ray_.direction_.x, ray_.direction_.y, ray_.direction_.z };
        float tca = std::inner_product(a, a + sizeof(a) / sizeof(a[0]), b, 0);
        /*
        if(tca < 0){
            std::cout << "tca smaller 0" << std::endl;
            return hitPoint(); }
          */
        float d = glm::sqrt((std::inner_product(a, a + sizeof(a) / sizeof(a[0]), a, 0)) - (tca * tca));
        if(pow(d,2) > pow(radius_,2)) {
            return hitPoint();}

        float thc = sqrt(pow(radius_, 2) - pow(d,2) );

        float t0 = tca - thc;

        glm::vec3 intersectPoint = ray_.origin_ + ray_.direction_ * t0;
        return hitPoint{true, t0, name_ ,color_ , intersectPoint, ray_.direction_};
    }
    else{
        return hitPoint();
    }
}