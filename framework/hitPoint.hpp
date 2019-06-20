#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <color.hpp>
#include <glm/vec3.hpp>

struct hitPoint
{
    bool hit = false;
    int t = 0;
    std::string name_ = "default";
    Color color_ = {1.0,1.0,1.0};
    glm::vec3 intersectPoint = {0.0,0.0,0.0};
    glm::vec3 direction_ = {0.0f , 0.0f , -1.0f };
};

#endif // HITPOINT_HPP