#include <gtest/gtest.h>
#include "city.hpp"
#include "building.hpp"


struct CityTest : public ::testing::Test {
    City city;
};


TEST_F(CityTest, CanAddBuildingToCity)
{
    Building building {BuildingType::hospital};

    EXPECT_TRUE(city.addBuilding(building));

}

TEST_F(CityTest, CanAddPeopleToBuilding)
{
    Building building {BuildingType::police_station};
    int value = 10;
    city.addBuilding(building);
    EXPECT_FALSE(city.getBuildings().empty());
    city.getBuildings()[0].addPeople(value);
    EXPECT_EQ(city.getBuildings()[0].getPeople(), value);
}
