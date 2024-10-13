#include "city.hpp"

City::City()
{}

const std::vector<Building>& City::getBuildings() const
{
    return buildingManager_.getBuildings();
}

Building* City::getBuilding(const int index)
{
    return buildingManager_.getBuilding(index);
}

bool City::addBuilding(BuildingType type)
{
    double cost = buildingManager_.getCostBuilding(type);
    if (resourceManager_.removeMoney(cost)) {
        buildingManager_.addBuilding(type);
        return true;    
    }

    return false;
}

bool City::removeBuilding(const int id)
{
    return buildingManager_.removeBuilding(id);
}