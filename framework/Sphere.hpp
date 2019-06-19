#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Shape.hpp"
#include "color.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape{
public:
    Sphere(): center_(0.0), radius_(1.0), Shape(){};
    Sphere(glm::vec3 const& center, float radius, std::string name, Color color): center_(center), radius_(radius),Shape(name, color){};
    ~Sphere();
    float area() const override;
    float volume() const override;
    glm::vec3 getCenter() const;
    float getRadius() const;
    std::string getName() const;
    Color getColor() const;
    std::ostream& print(std::ostream & os) const override;

private:
    glm::vec3 center_;
    float radius_;
};

std::ostream& operator<<(std::ostream& os, Sphere const & s);


#endif //SPHERE_HPP