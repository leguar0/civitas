#ifndef I_BUILDING_MANAGER_HPP
#define I_BUILDING_MANAGER_HPP

#include <vector>
#include "building.hpp"

class IBuildingManager
{
public:
    virtual ~IBuildingManager() = default;
    virtual const std::vector<Building>& getBuildings() const = 0;
    virtual Building* getBuilding(const int index) = 0;
    virtual void addBuilding(BuildingType type) = 0;
    virtual bool removeBuilding(const int id) = 0;
    virtual int getCostBuilding(BuildingType type) const = 0;
};

#endif