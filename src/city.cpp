#include "city.hpp"

City::City()
    : people_(10)
    , money_(100.0)
{}

const std::vector<Building>& City::getBuildings() const
{
    return buildingManager_.getBuildings();
}

bool City::addBuilding(BuildingType type)
{
    int cost = buildingManager_.getCostBuilding(type);
    if (money_ >= cost) {
        money_-= cost;

        return true;    
    }

    return false;
}

bool City::removeBuilding(const int id)
{
    return buildingManager_.removeBuilding(id);
}
