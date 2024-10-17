#include "buildingManager.hpp"

auto BuildingManager::findBuildingIterator(const int index) const
{
    return std::find_if(buildings_.begin(), buildings_.end(), [&](const std::unique_ptr<Building>& building) {
        return building->getId() == index;
    });
}

void BuildingManager::addBuilding(std::unique_ptr<Building> building)
{
    buildings_.push_back(std::move(building));
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

Building* BuildingManager::getBuilding(const int index)
{
    auto it = findBuildingIterator(index);
    return (it != buildings_.end()) ? it->get() : nullptr;
}

const std::vector<std::unique_ptr<Building>>& BuildingManager::getBuildings() const
{
    return buildings_;
}

