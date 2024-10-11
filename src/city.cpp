#include "city.hpp"

City::City()
    : people_(10)
    , money_(100.0)
{}

std::vector<Building>& City::getBuildings()
{
    return buildings_;
}

bool City::addBuilding(Building building)
{
    buildings_.push_back(building);
    if (!buildings_.empty())
        return true;
    return false;
}

