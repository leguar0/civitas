#include <gtest/gtest.h>
#include <iostream>
#include "city.hpp"
#include "building.hpp"


struct CityTest : public ::testing::Test {
    City city;
};


TEST_F(CityTest, CanAddBuildingToCity)
{
    EXPECT_TRUE(city.addBuilding(BuildingType::house));

}

TEST_F(CityTest, CanAddPeopleToBuilding)
{
    int value = 5;
    city.addBuilding(BuildingType::house);
    EXPECT_TRUE(city.addPeopleToBuilding(0, value));
    EXPECT_EQ(city.getBuilding(1)->getPeople(), value);
}
