#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Shape.hpp"
#include "color.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape{
public:
    Sphere(): center_(0.0), radius_(1.0), name_("default"), color_(0.0,0.0,0.0){};
    Sphere(glm::vec3 const& center, float radius, std::string name, Color color): center_(center), radius_(radius),name_(name), color_(color){};
    ~Sphere();
    float area() override;
    float volume() override;
    glm::vec3 getCenter();
    float getRadius();
    std::string getName();
    Color getColor();

private:
    glm::vec3 center_;
    float radius_;
    std::string name_;
    Color color_;
};


#endif //SPHERE_HPP