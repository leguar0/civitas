#ifndef BUILDING_MANAGER_HPP
#define BUILDING_MANAGER_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "building.hpp"

class BuildingManager
{
private:
    std::vector<Building> buildings_;
    std::unordered_map<BuildingType, double> buildingCosts_;

    auto findBuildingIterator(const int index) const;
public:
    BuildingManager();
    ~BuildingManager() = default;

    void addBuilding(BuildingType type);
    bool removeBuilding(const int index);

    int getCostBuilding(BuildingType type) const;
    Building* getBuilding(const int index) const;
    const std::vector<Building>& getBuildings() const;
};

#endif
