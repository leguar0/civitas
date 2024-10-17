#include <gtest/gtest.h>
#include <iostream>
#include "city.hpp"
#include "building.hpp"
#include "buildingManager.hpp"
#include "resourceManager.hpp"

struct CityTest : public ::testing::Test {
    std::shared_ptr<BuildingManager> buildingManager; 
    std::shared_ptr<ResourceManager> resourceManager;
    City* city;

    void SetUp() override {
        buildingManager = std::make_shared<BuildingManager>();
        resourceManager = std::make_shared<ResourceManager>();
        city = new City(buildingManager, resourceManager); 
    }

    void TearDown() override {
        delete city;
    }
};

TEST_F(CityTest, CanAddBuildingToCity)
{
    House house();
    // EXPECT_TRUE(city->addBuilding(house));
    std::cout << city->getMoney() << std::endl; 
}

/*
TEST_F(CityTest, CanAddPeopleToBuilding)
{
    int value = 5;
    city->addBuilding(BuildingType::house); 
    EXPECT_TRUE(city->addPeopleToBuilding(0, value));
    EXPECT_EQ(city->getBuilding(0)->getPeople(), value);
}
*/
