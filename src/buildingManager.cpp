#include "buildingManager.hpp"

auto BuildingManager::findBuildingIterator(const int index) const
{
    return std::find_if(buildings_.begin(), buildings_.end(), [&](const Building& b) {
        return b.getId() == index;
    });
}

BuildingManager::BuildingManager()
{
    buildingCosts_.insert({
        {BuildingType::hospital, 500.0},
        {BuildingType::house, 25.0},
        {BuildingType::police_station, 50.0},
        {BuildingType::post, 75.0},
        {BuildingType::power_station, 250.0},
        {BuildingType::subway, 650.0},
        {BuildingType::apartment_building, 1000.0}
    });
}

void BuildingManager::addBuilding(BuildingType type)
{
    buildings_.push_back(Building {type});
}

bool BuildingManager::removeBuilding(const int index)
{
    auto it = findBuildingIterator(index);
    if (it != buildings_.end()) {
        buildings_.erase(it);

        return true;
    }
    return false;
}

bool BuildingManager::addPeopleToBuilding(const int index, const int people)
{
    if (index >= 0 && index < buildings_.size()) {
        buildings_[index].addPeople(people);

        return true;
    }

    return false;
}

bool BuildingManager::removePeopleFromBuilding(const int index, const int people)
{
    if (index >= 0 && index < buildings_.size()) {
        if (buildings_[index].getPeople() >= people) {
            buildings_[index].removePeople(people);
            return true;
        }
    }

    return false;
}

int BuildingManager::getCostBuilding(BuildingType type) const
{
    return buildingCosts_.at(type);
}

Building *BuildingManager::getBuilding(const int index) const
{
    auto it = findBuildingIterator(index);
    
    if (it != buildings_.end()) {
        return const_cast<Building*>(&(*it)); 
    } else {
        return nullptr; 
    }
}

const std::vector<Building>& BuildingManager::getBuildings() const
{
    return buildings_;
}

