#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <Shape.hpp>
#include <Sphere.hpp>
#include <Box.hpp>
#include <iostream>

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




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
