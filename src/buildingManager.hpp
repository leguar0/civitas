#ifndef BUILDING_MANAGER_HPP
#define BUILDING_MANAGER_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "building.hpp"
#include "iBuildingManager.hpp"

class BuildingManager 
    : public IBuildingManager
{
private:
    std::vector<Building> buildings_;
    std::unordered_map<BuildingType, double> buildingCosts_;

    auto findBuildingIterator(const int index) const;
public:
    BuildingManager();
    ~BuildingManager() = default;

    const std::vector<Building>& getBuildings() const override;
    void addBuilding(BuildingType type) override;
    bool removeBuilding(const int index) override;
    Building* getBuilding(const int index) override;
    int getCostBuilding(BuildingType type) const override;
};

#endif
