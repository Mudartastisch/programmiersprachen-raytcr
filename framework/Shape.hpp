#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <color.hpp>

class Shape{
public:
    Shape(): name_("default"), color_(1.0,1.0,1.0){};
    virtual float area() const = 0 ;
    virtual float volume() const = 0 ;
    ~Shape();
    virtual std::ostream& print(std::ostream & os) const;

protected:
    Shape(std::string name, Color color): name_(name), color_(color){};
    std::string name_;
    Color color_;
};
std::ostream& operator<<(std::ostream& os, Shape const & s);
  




#endif // SHAPE_HPP