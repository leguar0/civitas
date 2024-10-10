#include "city.hpp"

City::City()
{
}

bool City::addBuilding(Building building)
{
    buildings_.push_back(building);
    if (!buildings_.empty())
        return true;
    return false;
}