#include "Shape.hpp"
#include <iostream>

Shape::~Shape(){
    std::cout << "Deconstructing shape" << std::endl;
};

std::ostream& Shape::print(std::ostream& os) const{
    os << "Name: " << name_ << " " << "Color: " << color_ ;
}

std::ostream& operator<<(std::ostream& os, Shape const & s) {
    s.print(os);
};