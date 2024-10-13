#include "city.hpp"

City::City()
    : people_(10)
    , money_(100.0)
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
    int cost = buildingManager_.getCostBuilding(type);
    if (money_ >= cost) {
        money_-= cost;

        buildingManager_.addBuilding(type);
        return true;    
    }

    return false;
}

bool City::removeBuilding(const int id)
{
    return buildingManager_.removeBuilding(id);
}

bool City::addPeopleToBuilding(const int id, const int people)
{
    if (people_ >= people) {
        people_-= people;
        return buildingManager_.addPeopleToBuilding(id, people);
    }
    return false;
}

bool City::removePeopleFromBuilding(const int id, const int people)
{
    return buildingManager_.removePeopleFromBuilding(id, people);
}
