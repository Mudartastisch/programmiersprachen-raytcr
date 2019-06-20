#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <Sphere.hpp>
#include <Box.hpp>
#include <iostream>
#include <ray.hpp>
#include <glm/gtx/intersect.hpp>
#include <hitPoint.hpp>

glm::vec3 zeroVec{ 0.0,0.0,0.0 };
glm::vec3 oneVec{ 1.0,1.0,1.0 };
Color black{1.0,1.0,1.0};

TEST_CASE("create sphere") {
	Sphere basic{};
	Sphere advanced{ zeroVec,{3.85f},{"advanced"},{black} };

	REQUIRE(advanced.getCenter().x == zeroVec.x);
	REQUIRE(advanced.getCenter().y == zeroVec.y);
	REQUIRE(advanced.getCenter().z == zeroVec.z);
	REQUIRE(advanced.getRadius() == 3.85f);

	REQUIRE(advanced.area() == Approx(186.26501f));
	REQUIRE(advanced.volume() == Approx(179.28008f));
}

TEST_CASE("create box") {
	Box basic{};
	Box advanced{ zeroVec, oneVec,{ "advanced" },{ black } };
	
	REQUIRE(advanced.getMin().x == zeroVec.x);
	REQUIRE(advanced.getMin().y == zeroVec.y);
	REQUIRE(advanced.getMin().z == zeroVec.z);
	REQUIRE(advanced.getMax().x == oneVec.x);
	REQUIRE(advanced.getMax().y == oneVec.y);
	REQUIRE(advanced.getMax().z == oneVec.z);

	REQUIRE(advanced.area() == Approx(8.0f));
	REQUIRE(advanced.volume() == Approx(1.0f));
}

TEST_CASE("print % operator<<") {
	Sphere s{ zeroVec,{3.85f},{"printSphere"},{black} };
	Box b{ zeroVec, oneVec,{ "printBox" },{ black } };
	std::cout << s;
	std::cout << b;
}


TEST_CASE("intersectRaySphere")
{
	// Ray
	glm::vec3 ray_origin{ 0.0 ,0.0 ,0.0 };
	// ray direction has to be normalized !
	// you can use :
	// v = glm :: normalize ( some_vector )
	glm::vec3 ray_direction{ 0.0 ,0.0 ,1.0 };
	// Sphere
	glm::vec3 sphere_center{ 0.0 ,0.0 ,5.0 };
	float sphere_radius{ 1.0 };
	float distance{ 0.0 };
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, // squared radius !!!
		distance);
	REQUIRE(distance == Approx(4.0f));
	Sphere s1{{0.0 ,0.0 ,5.0}, 1.0, "s1", black };
	glm::vec3 ray_direction_negative{ 0.0 ,0.0 ,-1.0 };
	hitPoint miss;
	miss = s1.intersect(Ray{ray_origin, ray_direction_negative});
	REQUIRE(miss.hit == false);
	hitPoint shouldHit1(s1.intersect(Ray{ray_origin, ray_direction}));
	REQUIRE(shouldHit1.hit);
	Sphere s2{{5.0 ,5.0 ,5.0}, 1.0, "s1", black };
	glm::vec3 ros2y{ 5.0 ,0.0 ,5.0 };
	glm::vec3 rds2y{ 0.0 ,1.0 ,0.0 };
	glm::vec3 ros2z{ 5.0 ,5.0 ,0.0 };
	glm::vec3 rds2z{ 0.0 ,0.0 ,1.0 };
	hitPoint shouldHit2(s2.intersect(Ray{ros2y, rds2y}));
	hitPoint shouldHit3(s2.intersect(Ray{ros2z, rds2z}));
	REQUIRE(shouldHit2.hit);
	REQUIRE(shouldHit3.hit);

}

TEST_CASE("deconstructer")
{
	Color red{1.0 , 0.0 , 0.0};
	glm::vec3 position{0.0f , 0.0f , 0.0f };
	Sphere *s1 = new Sphere{position , 1.2f , "sphere0" ,red};
	Shape *s2 = new Sphere {position , 1.2f , "sphere1", red};
	s1 -> print ( std::cout );
	s2 -> print ( std::cout );
	delete s1 ;
	delete s2 ;
}




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
