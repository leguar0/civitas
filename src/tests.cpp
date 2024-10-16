#include <gtest/gtest.h>
#include <iostream>
#include "city.hpp"
#include "building.hpp"
#include "buildingManager.hpp"
#include "resourceManager.hpp"


struct CityTest : public ::testing::Test {
    BuildingManager buildingManager;
    ResourceManager resourceManager;
    City* city;

    void SetUp() override {
        city = new City(std::make_shared<BuildingManager>(buildingManager),
                        std::make_shared<ResourceManager>(resourceManager));
    }

    void TearDown() override {
        delete city;
    }
};


TEST_F(CityTest, CanAddBuildingToCity)
{
    EXPECT_TRUE(city->addBuilding(BuildingType::house));
    std::cout << city->getMoney() << std::endl;
}

/*
TEST_F(CityTest, CanAddPeopleToBuilding)
{
    int value = 5;
    city.addBuilding(BuildingType::house);
    EXPECT_TRUE(city.addPeopleToBuilding(0, value));
    EXPECT_EQ(city.getBuilding(1)->getPeople(), value);
}
*/