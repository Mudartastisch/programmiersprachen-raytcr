#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape{
public:
    Sphere(): center_(0.0), radius_(1.0){};
    Sphere(glm::vec3 const& center, float radius): center_(center), radius_(radius) {};
    ~Sphere();
    float area() override;
    float volume() override;
    glm::vec3 getCenter();
    float getRadius();

private:
    glm::vec3 center_;
    float radius_;
};


#endif //SPHERE_HPP