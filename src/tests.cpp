#include <gtest/gtest.h>
#include "city.hpp"
#include "building.hpp"


struct CityTest : public ::testing::Test {
    City city;
};


TEST_F(CityTest, CanAddBuildingToCity)
{
    EXPECT_TRUE(
        city.addBuilding(
            Building {
                 BuildingType::police_station 
            }
        )
    );
}
